package alma.ucn.oca.ccd.logic;

import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.LinkedList;
import alma.JavaContainerError.wrappers.AcsJContainerServicesEx;
import alma.acs.component.client.ComponentClient;
import alma.acs.container.ContainerServices;
import alma.acs.nc.Consumer;
import alma.ACS.ACSComponent;

public class gCCDCompModel extends ComponentClient {
	private alma.ACS.ROstring myStringProperty;
	private alma.ACS.RWdouble myDoubleProperty;
	// Reference to the CCD component
	private alma.CCDmodule.CCDinterface ccdCompReference;
	// Instance of Notification Channel consumer
	private Consumer m_consumer;
	// Reference to the Container Services of ACS
	private ContainerServices m_containerServices;
	// List of the received filenames
	private LinkedList<String> l_filenames;
	private gCCDCompNCEvent lastNotification;
	private boolean consumerOn;
	private LinkedList<String> modelsList;
	private String selectedCamera;

	// Constructor
	public gCCDCompModel(Logger logger, String managerLoc, String clientName)
			throws Exception {
		super(logger, managerLoc, clientName);

		ccdCompReference = null;
		m_consumer = null;
		// Get the Container Services
		m_logger.info("INFO: Container services...");
		m_containerServices = getContainerServices();
		l_filenames = null;
		lastNotification = null;
		consumerOn = false;

		myStringProperty = null;
		myDoubleProperty = null;

		getCameraModelsFromCDB();
	}

	// Obtains a connection to the ACS Component
	public void connectToComponent() throws AcsJContainerServicesEx {
		m_logger.info("INFO: Connecting to component...");
		// Casts the object to get access to the IDL interface
		ccdCompReference = alma.CCDmodule.CCDinterfaceHelper
				.narrow(m_containerServices.getComponent(selectedCamera));

		ccdCompReference.on();

		myStringProperty = ccdCompReference.cameraName();
		myDoubleProperty = ccdCompReference.commandedCCDTemperature();
		System.out
				.println("[TRACE] CAMERA NAME"
						+ myStringProperty
								.get_sync(new alma.ACSErr.CompletionHolder()));
		System.out
				.println("[TRACE] CMDCCD TEMP"
						+ myDoubleProperty
								.get_sync(new alma.ACSErr.CompletionHolder()));

		m_logger.info("INFO: Connected!!!");
	}

	// Returns a reference to the ACS component
	public alma.CCDmodule.CCDinterface getComponent() {
		return ccdCompReference;
	}

	// This method is called whenever a new notificacion is received
	public void receive(alma.CCDmodule.ncCCDFilename newImageEvent) {
		m_logger.info(newImageEvent.fileName);
		m_logger.info("INFO: Notification received");
		// The list gets instantiated
		if (l_filenames == null) {
			l_filenames = new LinkedList<String>();
		}

		lastNotification = new gCCDCompNCEvent(newImageEvent.type.toString(),
				newImageEvent.id, newImageEvent.total);
		m_logger.info("INFO: Last notification:" + lastNotification.getID());
		if ((newImageEvent.type.toString()).equals("FILENAME")) {
			m_logger.info("INFO: 'FILENAME' Notification received filename: "
					+ newImageEvent.fileName);
			// The received name gets added to the list
			l_filenames.add(newImageEvent.fileName);
			m_logger.info("INFO: Last added: " + l_filenames.getLast());
		} else if ((newImageEvent.type.toString()).equals("END_SUBSCRIPTION")) {
			m_logger.info("INFO: 'END_SUBSCRIPTION' Notification received");
			// Disconnect the consumer
			this.disconnectConsumer();
		}
	}

	// This method calls the CCD component and asks for an image.
	// It also prepares the NC consumer to start receiving notifications.
	public void getImage(int width, int height, int acquisitionMode,
			int numberOfAcc, float exposureTime) {
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
			m_logger.info("INFO: Consumer is ready");
			m_logger.info("INFO: acq Mode: " + acquisitionMode);
			m_logger.info("INFO: fpf number of acc: " + numberOfAcc);
			m_logger.info("INFO: exposure time: " + exposureTime);
			ccdCompReference.acquisitionMode().set_sync(acquisitionMode);
			ccdCompReference.numberOfAcquisitions().set_sync(numberOfAcc);
			ccdCompReference.exposureTime().set_sync(exposureTime);
			ccdCompReference.startExposure();
		} catch (Exception e) {
			m_logger.info("EXCEPTION: Consumer has been disconnected");
			this.disconnectConsumer();
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

	public void disconnectCamera() {
		// myStringProperty.set_sync("BLABLA");
		System.out.println("[TRACE] CAMERA NAME: "
				+ ccdCompReference.cameraName().get_sync(
						new alma.ACSErr.CompletionHolder()));
		System.out
				.println("[TRACE] CAMERA NAME: "
						+ myStringProperty
								.get_sync(new alma.ACSErr.CompletionHolder()));

		myDoubleProperty.set_sync(12.7);
		System.out.println("[TRACE] CMDCCD TEMP"
				+ ccdCompReference.commandedCCDTemperature().get_sync(
						new alma.ACSErr.CompletionHolder()));
		System.out
				.println("[TRACE] CMDCCD TEMP"
						+ myDoubleProperty
								.get_sync(new alma.ACSErr.CompletionHolder()));
		System.out
				.println("[TRACE] CMDCCD TEMP" + myDoubleProperty.min_value());

		disconnectConsumer();
		ccdCompReference.off();
	}

	// Get method for LinkedList<String> filenames
	public LinkedList<String> getFilenameList() {
		if (l_filenames != null) {
			System.out.println("Filenames: "
					+ l_filenames.getFirst().toString());
		}
		return l_filenames;
	}

	public gCCDCompNCEvent getLastNotification() {
		return lastNotification;
	}

	// Returns true if the consumer is activated
	public boolean isConsumerOn() {
		return consumerOn;
	}

	public void getCameraModelsFromCDB() throws AcsJContainerServicesEx {
		// TODO Auto-generated method stub
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
	}

	public String[] getCameraModels() {
		return modelsList.toArray(new String[0]);
	}

	public void setCameraModel(int model) {
		selectedCamera = modelsList.get(model);
	}

}
