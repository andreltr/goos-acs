package alma.model;

import alma.dao.DAO;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Model extends AbstractModel {
	// Connection properties
	private DAO dome_dao;
	private String managerLoc;
	private String clientName;

	/**
	 * Default constructor
	 */
	public Model() throws Exception {

		managerLoc = System.getProperty("ACS.manager");
		if (managerLoc == null) {
			System.out
					.println("Java property 'ACS.manager' must be set to the corbaloc of the ACS manager!");
			System.exit(-1);
		}
		clientName = "gDOMECLIENT";

		try {
			if (dome_dao == null) {
				dome_dao = new DAO(null, managerLoc, clientName, this);
			}
		} catch (Exception e) {
			throw e;
		}
	}

	/**
	 * Provides the means to set or reset the model to a default state.
	 * 
	 * @throws Exception
	 */
	public void init() throws Exception {
		dome_dao.init();
	}

	// DAO interface

	public void connectToComponent() throws Exception {
		try {
			if (dome_dao == null) {
				dome_dao = new DAO(null, managerLoc, clientName, this);

			}
			if (dome_dao != null) {
				dome_dao.connectToComponent("DOMESERVER1");
			}
		} catch (Exception e) {
			throw e;
		}
	}

	public void disconnectFromComponent() throws Exception {
		if (dome_dao != null) {
			try {
				dome_dao.disconnectFromComponent();
				dome_dao.tearDown();
				try {
					dome_dao = null;
				} catch (Exception e) {
					try {
						Logger logger = dome_dao.getContainerServices()
								.getLogger();
						logger.log(Level.SEVERE, "Client application failure",
								e);
					} catch (Exception e2) {
						e.printStackTrace(System.err);
					}
					throw e;
				}
			} catch (Exception e3) {
				// bad luck
				throw e3;
			}
		}
	}
	
	public double getCurrentPositionDome() {
		double currentPosition = 0;
		if (dome_dao != null) {			
			currentPosition = dome_dao.getCurrentPositionDome();			
		}
		return currentPosition;
	}

		
	public void rotateLeft(double radians) {
		
		if (dome_dao != null) {			
			dome_dao.rotateLeft(radians);
		}
	}
	
	public void rotateRight(double radians) {
		if (dome_dao != null) {			
			dome_dao.rotateRight(radians);
		}
	}
	
	public void openSlit() {
		if (dome_dao != null) {
			dome_dao.openSlit();			
		}
	}
	
	public void closeSlit() {
		if (dome_dao != null) {
			dome_dao.closeSlit();
		}
	}
	
}
