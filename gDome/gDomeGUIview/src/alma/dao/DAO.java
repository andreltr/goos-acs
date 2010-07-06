package alma.dao;

import alma.model.Model;
import java.util.logging.Logger;
import alma.JavaContainerError.wrappers.AcsJContainerServicesEx;
import alma.acs.component.client.ComponentClient;
import alma.acs.container.ContainerServices;

public class DAO extends ComponentClient {
	private Model model;
	// Reference to the CCD component
	private alma.acsdomeServer.DomeServer gDomeCompReference;
	// Reference to the Container Services of ACS
	private ContainerServices m_containerServices;
	private double move_to;

	private String systemMessage = "";
	
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
		systemMessage = "INFO: Container services...";
		m_logger.info(systemMessage);
		m_containerServices = getContainerServices();

		setModel(model);
	}

	
	// Obtains a connection to the ACS Component
	public void connectToComponent(String selectedDome)
			throws AcsJContainerServicesEx {
		m_logger.info("INFO: Connecting to component...");
		// Casts the object to get access to the IDL interface
		gDomeCompReference = alma.acsdomeServer.DomeServerHelper
				.narrow(m_containerServices.getComponent(selectedDome));

		systemMessage = "INFO: Connected!!!";
		m_logger.info(systemMessage);
	}

	public void disconnectFromComponent() {
		m_logger.info("INFO: Disconnecting from component...");
		m_logger.info("INFO: Disconnected!!!");
	}	
	
	public void getCurrentPosition() {
		systemMessage = "INFO: Receiving current position...";
		m_logger.info(systemMessage);
		gDomeCompReference.domeCurrentPosition().get_sync(new alma.ACSErr.CompletionHolder());
	}

		
	// Returns a reference to the ACS component
	public alma.acsdomeServer.DomeServer getComponent() {
		return gDomeCompReference;
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
			systemMessage = "already opened";
			m_logger.info(systemMessage);		
		}else		{
			gDomeCompReference.slitCurrentState().set_sync(1);
			systemMessage = "INFO: Current Slite State:"+gDomeCompReference.slitCurrentState().get_sync(new alma.ACSErr.CompletionHolder());
			m_logger.info(systemMessage);
			systemMessage = "OK";
		}
	}
	
	public void closeSlit() {
		m_logger.info("INFO: Closing the slit");
		if(gDomeCompReference.slitCurrentState().get_sync(new alma.ACSErr.CompletionHolder()) == 0){
			systemMessage = "already closed";
			m_logger.info(systemMessage);
		}else{
			systemMessage = "INFO: Current Slite State:"+gDomeCompReference.slitCurrentState().get_sync(new alma.ACSErr.CompletionHolder());
			gDomeCompReference.slitCurrentState().set_sync(0);
			m_logger.info(systemMessage);
			systemMessage = "OK";
		}
	}
	
	public String getSystemMessage() {
		return systemMessage;
	}
}
