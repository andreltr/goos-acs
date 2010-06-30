package alma.model;

import alma.controller.Controller;
import alma.dao.DAO;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Model extends AbstractModel {
	// Connection properties
	private DAO ccd_dao;
	private String managerLoc;
	private String clientName;

	// Component properties
	private double actualAirTemperature;
	private double commandedCCDTemperature;
	private String cameraName;
	private long cameraModel;
	//
	private int currentState;

	// GUI properties
	private String[] ccdModels;
	private int currentImage;
	private int selectedCamera;

	/**
	 * Default constructor
	 */
	public Model() throws Exception {

		actualAirTemperature = -999;
		commandedCCDTemperature = -999;
		cameraName = "none";
		cameraModel = -1;

		managerLoc = System.getProperty("ACS.manager");
		if (managerLoc == null) {
			System.out
					.println("Java property 'ACS.manager' must be set to the corbaloc of the ACS manager!");
			System.exit(-1);
		}
		clientName = "gCCDGUIClient";

		try {
			if (ccd_dao == null) {
				ccd_dao = new DAO(null, managerLoc, clientName, this);
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
		ccd_dao.init();
	}

	// DAO interface

	public void connectToCamera() throws Exception {
		try {
			if (ccd_dao == null) {
				ccd_dao = new DAO(null, managerLoc, clientName, this);

			}
			if (ccd_dao != null) {
				ccd_dao.connectToComponent(ccdModels[selectedCamera]);
			}
		} catch (Exception e) {
			throw e;
		}
	}

	public void disconnectFromCamera() throws Exception {
		if (ccd_dao != null) {
			try {
				ccd_dao.disconnectFromComponent();
				ccd_dao.tearDown();
				try {
					ccd_dao = null;
				} catch (Exception e) {
					try {
						Logger logger = ccd_dao.getContainerServices()
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

	// Component interface
	public void startCooler() {
		if (ccd_dao != null) {
			ccd_dao.startCooler();
		}
	}

	/**
	 * @return the currentState
	 */
	public int getCurrentState() {
		return currentState;
	}

	public void getCCDValues() {
		if (ccd_dao != null) {
			ccd_dao.setCurrentModelValuesFromComponent();
		}
	}

	// Accessors

	public void setCurrentState(Integer currentState) {
		Integer oldCurrentState = this.currentState;
		this.currentState = currentState;

		firePropertyChange(Controller.COMP_CURRENT_STATE,
				oldCurrentState, currentState);
	}

	/**
	 * @param ccdModels
	 *            the ccdModels to set
	 */

	public void setCCDModels(String[] ccdModels) {
		String[] oldCcdModels = this.ccdModels;
		this.ccdModels = ccdModels;

		firePropertyChange(Controller.COMP_CAMERA_MODELS, oldCcdModels,
				ccdModels);
	}

	/**
	 * @return the ccdModels
	 */
	public String[] getCCDModels() {
		return ccdModels;
	}

	/**
	 * @param ccdModels
	 *            the ccdModels to set
	 */

	public void setSelectedCamera(Integer selectedCamera) {
		Integer oldSelectedCamera = this.selectedCamera;
		this.selectedCamera = selectedCamera;

		firePropertyChange(Controller.COMP_SELECTED_MODEL,
				oldSelectedCamera, selectedCamera);
	}

	/**
	 * @return the ccdModels
	 */
	public String[] getSelectedCamera() {
		return ccdModels;
	}

	/**
	 * @param actualAirTemperature
	 *            the actualAirTemperature to set
	 */

	public void setActualAirTemperature(Double actualAirTemperature) {
		Double oldActualAirTemperature = this.actualAirTemperature;
		this.actualAirTemperature = actualAirTemperature;

		firePropertyChange(Controller.COMP_ACTUAL_AIR_TEMP,
				oldActualAirTemperature, actualAirTemperature);
	}

	/**
	 * @return the actualAirTemperature
	 */
	public double getActualAirTemperature() {
		return actualAirTemperature;
	}

	/**
	 * @param commandedCCDTemperature
	 *            the commandedCCDTemperature to set
	 */
	public void setCommandedCCDTemperature(Double commandedCCDTemperature) {
		Double oldCommandedCCDTemperature = this.commandedCCDTemperature;
		this.commandedCCDTemperature = commandedCCDTemperature;

		firePropertyChange(Controller.COMP_COMMANDED_CCD_TEMP,
				oldCommandedCCDTemperature, commandedCCDTemperature);
	}

	/**
	 * @return the commandedCCDTemperature
	 */
	public double getCommandedCCDTemperature() {
		return commandedCCDTemperature;
	}

	/**
	 * @param cameraName
	 *            the cameraName to set
	 */
	public void setCameraName(String cameraName) {
		String oldCameraName = this.cameraName;
		this.cameraName = cameraName;

		firePropertyChange(Controller.COMP_CAMERA_NAME, oldCameraName,
				cameraName);
	}

	/**
	 * @return the cameraName
	 */
	public String getCameraName() {
		return cameraName;
	}

	/**
	 * @param cameraModel
	 *            the cameraModel to set
	 */
	public void setCameraModel(Long cameraModel) {
		// this.cameraModel = cameraModel;
		Long oldCameraModel = this.cameraModel;
		this.cameraModel = cameraModel;

		firePropertyChange(Controller.COMP_CAMERA_MODEL, oldCameraModel,
				cameraModel);
	}

	/**
	 * @return the cameraModel
	 */
	public long getCameraModel() {
		return cameraModel;
	}

	/**
	 * @param currentImage
	 *            the currentImage to set
	 */
	public void setCurrentImage(Integer currentImage) {
		Integer oldCurrentImage = this.currentImage;
		this.currentImage = currentImage;

		firePropertyChange(Controller.COMP_CURRENT_IMAGE,
				oldCurrentImage, currentImage);
	}

	/**
	 * @return the currentImage
	 */
	public int getCurrentImage() {
		return currentImage;
	}
}
