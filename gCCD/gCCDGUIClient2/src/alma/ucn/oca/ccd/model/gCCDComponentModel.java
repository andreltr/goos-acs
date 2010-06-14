package alma.ucn.oca.ccd.model;

import alma.ucn.oca.ccd.controller.DefaultController;
import alma.ucn.oca.ccd.dao.gCCDComponentDAO;

//import java.beans.PropertyChangeEvent;
import java.util.LinkedList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class gCCDComponentModel extends AbstractModel {
	// Connection properties
	private gCCDComponentDAO ccd_dao;
	private String managerLoc;
	private String clientName;

	// Component properties
	private double actualAirTemperature;
	private double actualCCDTemperature;
	private double commandedCCDTemperature;
	private String cameraName;
	private long cameraModel;
	private String filterName;
	private String objectName;
	private String observerName;
	private double exposureTime;
	private long acquisitionMode;
	private long numberOfAcquisitions;
	private double focalLength;
	private double gain;
	private double xPixelSize;
	private double yPixelSize;
	private long xStart;
	private long xEnd;
	private long yStart;
	private long yEnd;

	//
	private int currentState;

	// GUI properties
	private String[] ccdModels;
	private int currentImage;
	private int selectedCamera;
	private LinkedList<String> listFiles;

	/**
	 * Default constructor
	 */
	public gCCDComponentModel() throws Exception {

		actualAirTemperature = -999;
		actualCCDTemperature = -999;
		commandedCCDTemperature = -999;
		cameraName = "none";
		cameraModel = -1;
		filterName = "none";
		objectName = "none";
		observerName = "none";
		exposureTime = -1;
		acquisitionMode = -1;
		numberOfAcquisitions = -1;
		focalLength = -999;
		gain = -999;
		xPixelSize = -999;
		yPixelSize = -999;
		xStart = -1;
		xEnd = -1;
		yStart = -1;
		yEnd = -1;

		managerLoc = System.getProperty("ACS.manager");
		if (managerLoc == null) {
			System.out
					.println("Java property 'ACS.manager' must be set to the corbaloc of the ACS manager!");
			System.exit(-1);
		}
		clientName = "gCCDGUIClient";

		try {
			if (ccd_dao == null) {
				ccd_dao = new gCCDComponentDAO(null, managerLoc, clientName,
						this);
			}
		} catch (Exception e) {
			throw e;
		}
	}

	/**
	 * Provides the means to set or reset the model to a default state.
	 */
	public void init() {
		ccd_dao.init();
	}

	// DAO interface

	public void connectToCamera() throws Exception {
		try {
			if (ccd_dao == null) {
				ccd_dao = new gCCDComponentDAO(null, managerLoc, clientName,
						this);

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

	public void startCamera() {
		if (ccd_dao != null) {
			ccd_dao.startCamera();
		}
	}

	public void shutdownCamera() {
		if (ccd_dao != null) {
			ccd_dao.shutdownCamera();
		}
	}

	public void resetCamera() {
		if (ccd_dao != null) {
			ccd_dao.resetCamera();
		}
	}

	public void startExposure() {
		if (ccd_dao != null) {
			ccd_dao.startExposure(640, 480, (int) acquisitionMode,
					(int) numberOfAcquisitions, (float) exposureTime);
		}
	}

	public void stopExposure() {
		if (ccd_dao != null) {
			ccd_dao.stopExposure();
		}
	}

	public void startCooler() {
		if (ccd_dao != null) {
			ccd_dao.startCooler();
		}
	}

	public void stopCooler() {
		if (ccd_dao != null) {
			ccd_dao.stopCooler();
		}
	}

	/**
	 * @return the currentState
	 */
	public int getCurrentState() {
		return currentState;
	}

	public void endSubscription() {
		firePropertyChange(DefaultController.COMP_END_SUBSCRIPTION, null, null);
	}

	// Accessors

	public void setCurrentState(Integer currentState) {
		Integer oldCurrentState = this.currentState;
		this.currentState = currentState;

		firePropertyChange(DefaultController.COMP_CURRENT_STATE,
				oldCurrentState, currentState);
	}

	/**
	 * @param ccdModels
	 *            the ccdModels to set
	 */

	public void setCCDModels(String[] ccdModels) {
		String[] oldCcdModels = this.ccdModels;
		this.ccdModels = ccdModels;

		firePropertyChange(DefaultController.COMP_CAMERA_MODELS, oldCcdModels,
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

		firePropertyChange(DefaultController.COMP_SELECTED_MODEL,
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

		firePropertyChange(DefaultController.COMP_ACTUAL_AIR_TEMP,
				oldActualAirTemperature, actualAirTemperature);
	}

	/**
	 * @return the actualAirTemperature
	 */
	public double getActualAirTemperature() {
		return actualAirTemperature;
	}

	/**
	 * @param actualCCDTemperature
	 *            the actualCCDTemperature to set
	 */

	public void setActualCCDTemperature(Double actualCCDTemperature) {
		Double oldActualCCDTemperature = this.actualCCDTemperature;
		this.actualCCDTemperature = actualCCDTemperature;

		firePropertyChange(DefaultController.COMP_ACTUAL_CCD_TEMP,
				oldActualCCDTemperature, actualCCDTemperature);
	}

	/**
	 * @return the actualCCDTemperature
	 */
	public double getActualCCDTemperature() {
		return actualCCDTemperature;
	}

	/**
	 * @param commandedCCDTemperature
	 *            the commandedCCDTemperature to set
	 */
	public void setCommandedCCDTemperature(Double commandedCCDTemperature) {
		Double oldCommandedCCDTemperature = this.commandedCCDTemperature;
		this.commandedCCDTemperature = commandedCCDTemperature;

		firePropertyChange(DefaultController.COMP_COMMANDED_CCD_TEMP,
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

		firePropertyChange(DefaultController.COMP_CAMERA_NAME, oldCameraName,
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

		firePropertyChange(DefaultController.COMP_CAMERA_MODEL, oldCameraModel,
				cameraModel);
	}

	/**
	 * @return the cameraModel
	 */
	public long getCameraModel() {
		return cameraModel;
	}

	/**
	 * @param filterName
	 *            the filterName to set
	 */
	public void setFilterName(String filterName) {
		String oldFilterName = this.filterName;
		this.filterName = filterName;

		firePropertyChange(DefaultController.COMP_FILTER_NAME, oldFilterName,
				filterName);
	}

	/**
	 * @return the filterName
	 */
	public String getFilterName() {
		return filterName;
	}

	/**
	 * @param objectName
	 *            the objectName to set
	 */
	public void setObjectName(String objectName) {
		String oldObjectName = this.objectName;
		this.objectName = objectName;

		firePropertyChange(DefaultController.COMP_OBJECT_NAME, oldObjectName,
				objectName);

	}

	/**
	 * @return the objectName
	 */
	public String getObjectName() {
		return objectName;
	}

	/**
	 * @param observerName
	 *            the observerName to set
	 */
	public void setObserverName(String observerName) {
		String oldObserverName = this.observerName;
		this.observerName = observerName;

		firePropertyChange(DefaultController.COMP_OBSERVER_NAME,
				oldObserverName, observerName);

	}

	/**
	 * @return the observerName
	 */
	public String getObserverName() {
		return observerName;
	}

	/**
	 * @param exposureTime
	 *            the exposureTime to set
	 */
	public void setExposureTime(Double exposureTime) {
		Double oldExposureTime = this.exposureTime;
		this.exposureTime = exposureTime;

		firePropertyChange(DefaultController.COMP_EXPOSURE_TIME,
				oldExposureTime, exposureTime);

	}

	/**
	 * @return the exposureTime
	 */
	public double getExposureTime() {
		return exposureTime;
	}

	/**
	 * @param acquisitionMode
	 *            the acquisitionMode to set
	 */
	public void setAcquisitionMode(Long acquisitionMode) {
		Long oldAcquisitionMode = this.acquisitionMode;
		this.acquisitionMode = acquisitionMode;

		firePropertyChange(DefaultController.COMP_ACQ_MODE, oldAcquisitionMode,
				acquisitionMode);
	}

	/**
	 * @return the acquisitionMode
	 */
	public long getAcquisitionMode() {
		return acquisitionMode;
	}

	/**
	 * @param numberOfAcquisitions
	 *            the numberOfAcquisitions to set
	 */
	public void setNumberOfAcquisitions(Long numberOfAcquisitions) {
		Long oldNumberOfAcquisitions = this.numberOfAcquisitions;
		this.numberOfAcquisitions = numberOfAcquisitions;

		firePropertyChange(DefaultController.COMP_NUMBER_ACQ,
				oldNumberOfAcquisitions, numberOfAcquisitions);
	}

	/**
	 * @return the numberOfAcquisitions
	 */
	public long getNumberOfAcquisitions() {
		return numberOfAcquisitions;
	}

	/**
	 * @param focalLength
	 *            the focalLength to set
	 */
	public void setFocalLength(Double focalLength) {
		Double oldFocalLength = this.focalLength;
		this.focalLength = focalLength;

		firePropertyChange(DefaultController.COMP_FOCAL_LENGTH, oldFocalLength,
				focalLength);

	}

	/**
	 * @return the focalLength
	 */
	public double getFocalLength() {
		return focalLength;
	}

	/**
	 * @param gain
	 *            the gain to set
	 */

	public void setGain(Double gain) {
		Double oldGain = this.gain;
		this.gain = gain;

		firePropertyChange(DefaultController.COMP_GAIN, oldGain, gain);

	}

	/**
	 * @return the gain
	 */
	public double getGain() {
		return gain;
	}

	/**
	 * @param xPixelSize
	 *            the xPixelSize to set
	 */

	public void setxPixelSize(Double xPixelSize) {
		Double oldxPixelSize = this.xPixelSize;
		this.xPixelSize = xPixelSize;

		firePropertyChange(DefaultController.COMP_XPIXEL_SIZE, oldxPixelSize,
				xPixelSize);
	}

	/**
	 * @return the xPixelSize
	 */
	public double getxPixelSize() {
		return xPixelSize;
	}

	/**
	 * @param yPixelSize
	 *            the yPixelSize to set
	 */

	public void setyPixelSize(Double yPixelSize) {
		Double oldyPixelSize = this.yPixelSize;
		this.yPixelSize = yPixelSize;

		firePropertyChange(DefaultController.COMP_YPIXEL_SIZE, oldyPixelSize,
				yPixelSize);
	}

	/**
	 * @return the yPixelSize
	 */
	public double getyPixelSize() {
		return yPixelSize;
	}

	/**
	 * @param xStart
	 *            the xStart to set
	 */
	public void setxStart(Long xStart) {
		Long oldxStart = this.xStart;
		this.xStart = xStart;

		firePropertyChange(DefaultController.COMP_X_START, oldxStart, xStart);
	}

	/**
	 * @return the xStart
	 */
	public long getxStart() {
		return xStart;
	}

	/**
	 * @param xEnd
	 *            the xEnd to set
	 */
	public void setxEnd(Long xEnd) {
		Long oldxEnd = this.xEnd;
		this.xEnd = xEnd;

		firePropertyChange(DefaultController.COMP_X_END, oldxEnd, xEnd);
	}

	/**
	 * @return the xEnd
	 */
	public long getxEnd() {
		return xEnd;
	}

	/**
	 * @param yStart
	 *            the yStart to set
	 */
	public void setyStart(Long yStart) {
		Long oldyStart = this.yStart;
		this.yStart = yStart;

		firePropertyChange(DefaultController.COMP_Y_START, oldyStart, yStart);
	}

	/**
	 * @return the yStart
	 */
	public long getyStart() {
		return yStart;
	}

	/**
	 * @param yEnd
	 *            the yEnd to set
	 */
	public void setyEnd(Long yEnd) {
		Long oldyEnd = this.yEnd;
		this.yEnd = yEnd;

		firePropertyChange(DefaultController.COMP_Y_END, oldyEnd, yEnd);
	}

	/**
	 * @return the yEnd
	 */
	public long getyEnd() {
		return yEnd;
	}

	/**
	 * @param currentImage
	 *            the currentImage to set
	 */
	public void setCurrentImage(Integer currentImage) {
		Integer oldCurrentImage = this.currentImage;
		this.currentImage = currentImage;

		firePropertyChange(DefaultController.COMP_CURRENT_IMAGE,
				oldCurrentImage, currentImage);
	}

	/**
	 * @return the currentImage
	 */
	public int getCurrentImage() {
		return currentImage;
	}

	/**
	 * @param listFiles
	 *            the listFiles to set
	 */
	public void setListFiles(LinkedList<String> listFiles) {
		LinkedList<String> oldListFiles = this.listFiles;
		this.listFiles = listFiles;

		firePropertyChange(DefaultController.COMP_LIST_FILES, oldListFiles,
				listFiles);
	}

	/**
	 * @return the listFiles
	 */
	public LinkedList<String> getListFiles() {
		return listFiles;
	}
}
