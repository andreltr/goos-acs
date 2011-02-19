/*package alma.ucn.oca.ccd.dao;

import alma.ucn.oca.ccd.model.gCCDComponentModel;
import alma.ucn.oca.ccd.utils.gCCDNCEvent;
import java.util.logging.Logger;
import java.util.LinkedList;
import alma.JavaContainerError.wrappers.AcsJContainerServicesEx;
import alma.acs.component.client.ComponentClient;
import alma.acs.container.ContainerServices;
import alma.acs.nc.Consumer;

public class gCCDComponentDAO extends ComponentClient {
	private gCCDComponentModel model;
	// Reference to the CCD component
	private alma.CCDmodule.CCDinterface ccdCompReference;
	// Instance of Notification Channel consumer
	private Consumer m_consumer;
	// Reference to the Container Services of ACS
	private ContainerServices m_containerServices;
	// List of the received filenames
	private LinkedList<String> l_filenames;
	private gCCDNCEvent lastNotification;
	private boolean consumerOn;
	private LinkedList<String> modelsList;

	*//**
	 * Default constructor
	 * 
	 * @throws Exception
	 *//*
	public gCCDComponentDAO(Logger logger, String managerLoc,
			String clientName, gCCDComponentModel model) throws Exception {
		super(logger, managerLoc, clientName);

		ccdCompReference = null;
		m_consumer = null;
		// Get the Container Services
		m_logger.info("INFO: Container services...");
		m_containerServices = getContainerServices();
		l_filenames = null;
		lastNotification = null;
		consumerOn = false;

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
		disconnectConsumer();
		m_logger.info("INFO: Disconnected!!!");
		getCurrentState();
	}

	public void startCamera() {
		m_logger.info("INFO: Starting camera...");
		ccdCompReference.ipAddress().set_sync(model.getIP());
		ccdCompReference.deviceType().set_sync(model.getDeviceType());
		ccdCompReference.on();
		getCurrentState();
	}

	public void shutdownCamera() {
		m_logger.info("INFO: Shutting down camera...");
		ccdCompReference.off();
		getCurrentState();
	}

	public void resetCamera() {
		m_logger.info("INFO: Resetting camera...");
		ccdCompReference.resetCamera();
		getCurrentState();
	}

	// This method calls the CCD component and asks for an image.
	// It also prepares the NC consumer to start receiving notifications.
	public void startExposure() throws Exception {
		m_logger.info("INFO: Starting exposure...");
		try {
			l_filenames = null;
			consumerOn = true;
			m_consumer = new Consumer(
					alma.CCDmodule.CHANNELNAME_CCDCLIENT.value,
					m_containerServices);
			m_consumer
					.addSubscription(alma.CCDmodule.ncCCDFilename.class, this);
			m_logger.info("INFO: Channel subscription has been added");
			m_consumer.consumerReady();
		} catch (Exception e) {
			m_logger.info("EXCEPTION: Consumer has been disconnected");
			this.disconnectConsumer();
		}

		ccdCompReference.observerName().set_sync(
				(String) model.getObserverName());
		ccdCompReference.objectName().set_sync((String) model.getObjectName());
		ccdCompReference.telescopeName().set_sync(
				(String) model.getTelescopeName());
		ccdCompReference.acquisitionMode().set_sync(
				(int) model.getAcquisitionMode());
		ccdCompReference.numberOfAcquisitions().set_sync(
				(int) model.getNumberOfAcquisitions());
		ccdCompReference.exposureTime().set_sync(
				(double) model.getExposureTime());
		ccdCompReference.startExposure();

		System.out.println((String) ccdCompReference.objectName().get_sync(
				new alma.ACSErr.CompletionHolder()));
		System.out.println((String) ccdCompReference.observerName().get_sync(
				new alma.ACSErr.CompletionHolder()));
		System.out.println((String) ccdCompReference.telescopeName().get_sync(
				new alma.ACSErr.CompletionHolder()));

		getCurrentState();
	}

	public void stopExposure() {
		m_logger.info("INFO: Stopping exposure...");
		ccdCompReference.stopExposure();
		getCurrentState();
	}

	public void startCooler() {
		m_logger.info("INFO: Starting cooler...");
		ccdCompReference.commandedCCDTemperature().set_sync(
				model.getCommandedCCDTemperature());
		ccdCompReference.startCooler();
		getCurrentState();
	}

	public void stopCooler() {
		m_logger.info("INFO: Stopping cooler...");
		ccdCompReference.stopCooler();
		getCurrentState();
	}

	public void getCurrentState() {
		model.setCurrentState(ccdCompReference.getState());
	}

	public void setCurrentModelValuesFromComponent() {
		model.setActualAirTemperature(ccdCompReference.actualAirTemperature()
				.get_sync(new alma.ACSErr.CompletionHolder()));
		model.setActualCCDTemperature(ccdCompReference.actualCCDTemperature()
				.get_sync(new alma.ACSErr.CompletionHolder()));

		model.setCameraName(ccdCompReference.cameraName().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setCameraModel((long) ccdCompReference.cameraModel().get_sync(
				new alma.ACSErr.CompletionHolder()));

		model.setGain(ccdCompReference.gain().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setxPixelSize(ccdCompReference.xPixelSize().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setyPixelSize(ccdCompReference.yPixelSize().get_sync(
				new alma.ACSErr.CompletionHolder()));
	}

	//
	public void setInitialModelValuesFromCDB() {
		model.setActualAirTemperature((double) ccdCompReference
				.actualAirTemperature().get_sync(
						new alma.ACSErr.CompletionHolder()));
		model.setActualCCDTemperature((double) ccdCompReference
				.actualCCDTemperature().get_sync(
						new alma.ACSErr.CompletionHolder()));
		model.setCommandedCCDTemperature((double) ccdCompReference
				.commandedCCDTemperature().get_sync(
						new alma.ACSErr.CompletionHolder()));
		model.setCameraName((String) ccdCompReference.cameraName().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setCameraModel((long) ccdCompReference.cameraModel().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setFilterName((String) ccdCompReference.filterName().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setObjectName((String) ccdCompReference.objectName().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setObserverName((String) ccdCompReference.observerName()
				.get_sync(new alma.ACSErr.CompletionHolder()));
		model.setExposureTime((double) ccdCompReference.exposureTime()
				.get_sync(new alma.ACSErr.CompletionHolder()));
		model.setAcquisitionMode((long) ccdCompReference.acquisitionMode()
				.get_sync(new alma.ACSErr.CompletionHolder()));
		model.setNumberOfAcquisitions((long) ccdCompReference
				.numberOfAcquisitions().get_sync(
						new alma.ACSErr.CompletionHolder()));
		model.setFocalLength((double) ccdCompReference.focalLength().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setGain((double) ccdCompReference.gain().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setxPixelSize((double) ccdCompReference.xPixelSize().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setyPixelSize((double) ccdCompReference.yPixelSize().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setxStart((long) ccdCompReference.xStart().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setxEnd((long) ccdCompReference.xEnd().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setyStart((long) ccdCompReference.yStart().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setyEnd((long) ccdCompReference.yEnd().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setTelescopeName((String) ccdCompReference.telescopeName()
				.get_sync(new alma.ACSErr.CompletionHolder()));
		model.setIP((String) ccdCompReference.ipAddress().get_sync(
				new alma.ACSErr.CompletionHolder()));
		model.setDeviceType((int) ccdCompReference.deviceType().get_sync(
				new alma.ACSErr.CompletionHolder()));
	}

	// Returns a reference to the ACS component
	public alma.CCDmodule.CCDinterface getComponent() {
		return ccdCompReference;
	}

	// This method is called whenever a new notificacion is received
	@SuppressWarnings("unchecked")
	public void receive(alma.CCDmodule.ncCCDFilename newImageEvent) {
		m_logger.info(newImageEvent.fileName);
		m_logger.info("INFO: Notification received");
		// The list gets instantiated
		if (l_filenames == null) {
			l_filenames = new LinkedList<String>();
		}

		lastNotification = new gCCDNCEvent(newImageEvent.type.toString(),
				newImageEvent.id, newImageEvent.total);
		m_logger.info("INFO: Last notification:" + lastNotification.getID());
		if ((newImageEvent.type.toString()).equals("FILENAME")) {
			m_logger.info("INFO: 'FILENAME' Notification received filename: "
					+ newImageEvent.fileName);
			// The received name gets added to the list
			l_filenames.add(newImageEvent.fileName);
			// To actually update the list
			model.setListFiles((LinkedList<String>) l_filenames.clone());
			model.fileReceived(lastNotification);
			m_logger.info("INFO: Last added: " + l_filenames.getLast());
		} else if ((newImageEvent.type.toString()).equals("END_SUBSCRIPTION")) {
			m_logger.info("INFO: 'END_SUBSCRIPTION' Notification received");
			// Disconnect the consumer
			model.endSubscription();
			this.disconnectConsumer();
			getCurrentState();
		}
	}

	// This method disconnects the NC consumer from the channel
	public void disconnectConsumer() {
		if (m_consumer != null) {
			m_logger.info("INFO: Consumer has been disconnected");
			m_consumer.disconnect();
			m_consumer = null;
			consumerOn = false;
			lastNotification = null;
		}
	}

	// Get method for LinkedList<String> filenames
	public LinkedList<String> getFilenameList() {
		if (l_filenames != null) {
			System.out.println("Filenames: "
					+ l_filenames.getFirst().toString());
		}
		return l_filenames;
	}

	public gCCDNCEvent getLastNotification() {
		return lastNotification;
	}

	// Returns true if the consumer is activated
	public boolean isConsumerOn() {
		return consumerOn;
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

	public void setModel(gCCDComponentModel model) {
		this.model = model;
	}

	public gCCDComponentModel getModel() {
		return this.model;
	}
}
*/