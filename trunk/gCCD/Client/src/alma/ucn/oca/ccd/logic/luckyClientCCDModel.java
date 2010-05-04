package alma.ucn.oca.ccd.logic;

import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.LinkedList;
import alma.JavaContainerError.wrappers.AcsJContainerServicesEx;
import alma.acs.component.client.ComponentClient;
import alma.acs.container.ContainerServices;
import alma.acs.nc.Consumer;
import alma.ACS.ACSComponent;

public class luckyClientCCDModel extends ComponentClient {
	// Reference to the CCD component
	private alma.CCDmodule.CCDinterface ccdCompReference;
	// Instance of Notification Channel consumer
	private Consumer m_consumer;
	// Reference to the Container Services of ACS
	private ContainerServices m_containerServices;
	// List of the received filenames
	private LinkedList<String> l_filenames;
	private luckyClientNCEvent lastNotification;
	private boolean consumerOn;
	private alma.CCDModels.CCDMODEL [] modelsList;

	// Constructor
	public luckyClientCCDModel(Logger logger, String managerLoc, String clientName)
			throws Exception {
		super(logger, managerLoc, clientName);
		ccdCompReference = null;
		m_consumer = null;
		m_containerServices = null;
		l_filenames = null;
		lastNotification = null;
		consumerOn = false;
	}

	// Obtains a connection to the ACS Component
	public void connectToComponent() throws AcsJContainerServicesEx {
		// Get the Container Services
		m_logger.info("INFO: Connecting to component...");
		m_containerServices = getContainerServices();
		m_logger.info("INFO: Container services...");
		// Casts the object to get access to the IDL interface
		// This should not be hard coded
		ccdCompReference = alma.CCDmodule.CCDinterfaceHelper
				.narrow(m_containerServices.getComponent("CCDComponent"));
		ccdCompReference.on();
		getCameraModels();
		m_logger.info("INFO: Connected!!!");
	}

	// Returns a reference to the ACS component
	public alma.CCDmodule.CCDinterface getComponent() {
		return ccdCompReference;
	}

	// This method is called whenever a new notificacion is received
	public void receive(alma.CCDmodule.ncCCDFilename newImageEvent) {
		// TODO: NCSupplier must send a "no more images" notification to
		// disconnect
		// m_logger.info(newImageEvent.fileName);
		m_logger.info("INFO: Notification received");
		// The list gets instantiated
		if (l_filenames == null) {
			l_filenames = new LinkedList<String>();
		}
		
		lastNotification = new luckyClientNCEvent(newImageEvent.type.toString(), newImageEvent.id ,newImageEvent.total);
		m_logger.info("INFO: Last notification:" + lastNotification.getID());
		if ((newImageEvent.type.toString()).equals("FILENAME")) {
			m_logger.info("INFO: 'FILENAME' Notification received filename: " + newImageEvent.fileName);
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
	public void getImage(int width, int height, int acquisitionMode, int numberOfAcc, float exposureTime) {
		try {
			l_filenames = null;
			consumerOn = true;
			m_consumer = new Consumer(alma.CCDmodule.CHANNELNAME_CCDCLIENT.value,
					m_containerServices);
			m_consumer
					.addSubscription(alma.CCDmodule.ncCCDFilename.class, this);
			m_logger.info("INFO: Channel subscription has been added");
			m_consumer.consumerReady();
			m_logger.info("INFO: Consumer is ready");
			m_logger.info("INFO: width: " + width);
			m_logger.info("INFO: height: " + height);
			m_logger.info("INFO: acq Mode: " + acquisitionMode);
			m_logger.info("INFO: frames per file: " + numberOfAcc);
			m_logger.info("INFO: exposure time: " + exposureTime);
			ccdCompReference.getImage(width,height,acquisitionMode,numberOfAcc,exposureTime);
		} catch (Exception e) {
			m_logger.info("EXCEPTION: Consumer has been disconnected");
			this.disconnectConsumer();
		}
	}

	// This method disconnects the NC consumer from the channel
	public void disconnectConsumer() {
		if(m_consumer != null){
			m_logger.info("INFO: Consumer has been disconnected");
			m_consumer.disconnect();
			m_consumer = null;
			consumerOn = false;
			lastNotification = null;
		}
	}
	
	public void disconnectCamera(){
		disconnectConsumer();
		ccdCompReference.off();		
	}

	// Get method for LinkedList<String> filenames
	public LinkedList<String> getFilenameList() {
		if(l_filenames != null){
		System.out.println("Filenames: " + l_filenames.getFirst().toString());
		}
		return l_filenames;
	}
	
	public luckyClientNCEvent getLastNotification(){
		return lastNotification;
	}
	
	//Returns true if the consumer is activated
	public boolean isConsumerOn(){
		return consumerOn;
	}

	public String[] getCameraModels() {
		// TODO Auto-generated method stub
		int listSize = 0;
		int index = 0;
	
		try{
			while(true){
				alma.CCDModels.CCDMODEL.from_int(index);
				index++;
				listSize++;
			}
		}
		catch(Exception ex){
			
		}
		
		String [] camModels = new String[listSize];
		modelsList = new alma.CCDModels.CCDMODEL[listSize];
		index = 0;
		
		for(int i=0; i<listSize;i++){
				modelsList[i] = alma.CCDModels.CCDMODEL.from_int(i);
				camModels[i] = modelsList[i].toString();
				System.out.println(camModels[i]);
		}
		
		return camModels;
	}
	
	public void setCameraModel(int model){
		ccdCompReference.setCCDModel(modelsList[model]);
	}
	

}
