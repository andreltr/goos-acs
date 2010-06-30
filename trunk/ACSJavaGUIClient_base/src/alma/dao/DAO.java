package alma.dao;

import alma.model.Model;
import java.util.logging.Logger;
import java.util.LinkedList;
import alma.JavaContainerError.wrappers.AcsJContainerServicesEx;
import alma.acs.component.client.ComponentClient;
import alma.acs.container.ContainerServices;

public class DAO extends ComponentClient {
	private Model model;
	// Reference to the CCD component
	private alma.CCDmodule.CCDinterface ccdCompReference;
	// Reference to the Container Services of ACS
	private ContainerServices m_containerServices;
	private LinkedList<String> modelsList;

	/**
	 * Default constructor
	 * 
	 * @throws Exception
	 */
	public DAO(Logger logger, String managerLoc, String clientName, Model model)
			throws Exception {
		super(logger, managerLoc, clientName);

		ccdCompReference = null;
		// Get the Container Services
		m_logger.info("INFO: Container services...");
		m_containerServices = getContainerServices();

		setModel(model);
	}

	public void init() throws AcsJContainerServicesEx {
		model.setCCDModels(getCameraModelsFromCDB());
	}

	// Obtains a connection to the ACS Component
	public void connectToComponent(String selectedCamera)
			throws AcsJContainerServicesEx {
		m_logger.info("INFO: Connecting to component...");
		// Casts the object to get access to the IDL interface
		ccdCompReference = alma.CCDmodule.CCDinterfaceHelper
				.narrow(m_containerServices.getComponent(selectedCamera));

		setInitialModelValuesFromCDB();
		m_logger.info("INFO: Connected!!!");
		getCurrentState();
	}

	public void disconnectFromComponent() {
		m_logger.info("INFO: Disconnecting from component...");
		m_logger.info("INFO: Disconnected!!!");
		getCurrentState();
	}

	public void startCooler() {
		m_logger.info("INFO: Starting cooler...");
		ccdCompReference.commandedCCDTemperature().set_sync(
				model.getCommandedCCDTemperature());
		ccdCompReference.startCooler();
		getCurrentState();
	}

	public void getCurrentState() {
		model.setCurrentState(ccdCompReference.getState());
	}

	public void setCurrentModelValuesFromComponent() {
		model.setActualAirTemperature(ccdCompReference.actualAirTemperature()
				.get_sync(new alma.ACSErr.CompletionHolder()));
		model.setCameraName(ccdCompReference.cameraName().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setCameraModel((long) ccdCompReference.cameraModel().get_sync(
				new alma.ACSErr.CompletionHolder()));
	}

	//
	public void setInitialModelValuesFromCDB() {
		model.setActualAirTemperature((double) ccdCompReference
				.actualAirTemperature().get_sync(
						new alma.ACSErr.CompletionHolder()));
		model.setCameraName((String) ccdCompReference.cameraName().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setCameraModel((long) ccdCompReference.cameraModel().get_sync(
				new alma.ACSErr.CompletionHolder()));
	}

	// Returns a reference to the ACS component
	public alma.CCDmodule.CCDinterface getComponent() {
		return ccdCompReference;
	}

	public String[] getCameraModelsFromCDB() throws AcsJContainerServicesEx {
		m_logger.info("INFO: Finding components...");
		if (modelsList == null) {
			modelsList = new LinkedList<String>();
			modelsList.add("<SELECT A CAMERA MODEL>");
		}

		for (String s : m_containerServices.findComponents(null, null)) {
			if (m_containerServices.getComponentDescriptor(s).getType().equals(
					"IDL:alma/CCDmodule/CCDinterface:1.0")) {
				modelsList.add(m_containerServices.getComponentDescriptor(s)
						.getName());
			}
		}
		return modelsList.toArray(new String[0]);
	}

	public void setModel(Model model) {
		this.model = model;
	}

	public Model getModel() {
		return this.model;
	}
}
