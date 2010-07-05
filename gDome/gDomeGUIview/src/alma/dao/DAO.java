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
	private alma.acsdomeServer.DomeServer gDomeCompReference;
	// Reference to the Container Services of ACS
	private ContainerServices m_containerServices;
	private LinkedList<String> modelsList;
	private double move_to;

	/**
	 * Default constructor
	 * 
	 * @throws Exception
	 */
	public DAO(Logger logger, String managerLoc, String clientName, Model model)
			throws Exception {
		super(logger, managerLoc, clientName);

		gDomeCompReference = null;
		// Get the Container Services
		m_logger.info("INFO: Container services...");
		m_containerServices = getContainerServices();

		setModel(model);
	}

	public void init() throws AcsJContainerServicesEx {
		//model.setCCDModels(getCameraModelsFromCDB());
	}

	// Obtains a connection to the ACS Component
	public void connectToComponent(String selectedDome)
			throws AcsJContainerServicesEx {
		m_logger.info("INFO: Connecting to component...");
		// Casts the object to get access to the IDL interface
		gDomeCompReference = alma.acsdomeServer.DomeServerHelper
				.narrow(m_containerServices.getComponent(selectedDome));

		//setInitialModelValuesFromCDB();
		m_logger.info("INFO: Connected!!!");
		getCurrentState();
	}

	public void disconnectFromComponent() {
		m_logger.info("INFO: Disconnecting from component...");
		m_logger.info("INFO: Disconnected!!!");
		getCurrentState();
	}	
	
	public void getCurrentPosition() {
		m_logger.info("INFO: Receiving current position...");
		gDomeCompReference.domeCurrentPosition().get_sync(new alma.ACSErr.CompletionHolder());
		//getCurrentState();
	}

	public void getCurrentState() { //Opción a borrar
		//model.setCurrentState(gDomeCompReference.getState(new alma.ACSErr.CompletionHolder()));
		gDomeCompReference.displayMessage();
	}
	
	// Returns a reference to the ACS component
	public alma.acsdomeServer.DomeServer getComponent() {
		return gDomeCompReference;
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
	
	public double getCurrentPositionDome(){
		return gDomeCompReference.domeCurrentPosition().get_sync(new alma.ACSErr.CompletionHolder());
	}
	
	public void rotateLeft(double radians){
		m_logger.info("INFO: Rotating Dome!");
		move_to = gDomeCompReference.domeCurrentPosition().get_sync(new alma.ACSErr.CompletionHolder()) + radians;
		gDomeCompReference.domeCurrentPosition().set_sync((double) move_to);
		m_logger.info("INFO: Current Position: "+gDomeCompReference.domeCurrentPosition().get_sync(new alma.ACSErr.CompletionHolder()));
	}
	
	public void rotateRight(double radians){
		m_logger.info("INFO: Rotating Dome!");
		move_to = gDomeCompReference.domeCurrentPosition().get_sync(new alma.ACSErr.CompletionHolder()) - radians;
		gDomeCompReference.domeCurrentPosition().set_sync((double) move_to);
		m_logger.info("INFO: Current Position: "+gDomeCompReference.domeCurrentPosition().get_sync(new alma.ACSErr.CompletionHolder()));
	}
	
	public void openSlit() {
		m_logger.info("INFO: Opening the slit");
		if(gDomeCompReference.slitCurrentState().get_sync(new alma.ACSErr.CompletionHolder()) == 1){
			m_logger.info("INFO: The slit is already opened");		
		}else		{
			gDomeCompReference.slitCurrentState().set_sync(1);
			m_logger.info("INFO: Current Slite State:"+gDomeCompReference.slitCurrentState().get_sync(new alma.ACSErr.CompletionHolder()));
		}
	}
	
	public void closeSlit() {
		m_logger.info("INFO: Closing the slit");
		if(gDomeCompReference.slitCurrentState().get_sync(new alma.ACSErr.CompletionHolder()) == 0){
			m_logger.info("INFO: The slit is already closed");
		}else{
			gDomeCompReference.slitCurrentState().set_sync(0);
			m_logger.info("INFO: Current Slite State:"+gDomeCompReference.slitCurrentState().get_sync(new alma.ACSErr.CompletionHolder()));
		}
	}
}
