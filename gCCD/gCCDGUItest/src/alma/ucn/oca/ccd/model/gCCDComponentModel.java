package alma.ucn.oca.ccd.model;

import alma.ucn.oca.ccd.controller.DefaultController;
import alma.ucn.oca.ccd.dao.gCCDComponentDAO;

import java.beans.PropertyChangeEvent;

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

	// GUI properties
	private String[] ccdModels;
	private boolean originalSize;
	private int currentImage;

	/**
	 * Default constructor
	 */
	public gCCDComponentModel() throws Exception {
		managerLoc = System.getProperty("ACS.manager");
		if (managerLoc == null) {
			System.out
					.println("Java property 'ACS.manager' must be set to the corbaloc of the ACS manager!");
			System.exit(-1);
		}
		clientName = "gCCDGUIClient";

		try {
			if (ccd_dao == null) {
				ccd_dao = new gCCDComponentDAO(null, managerLoc, clientName);
			}
		} catch (Exception e) {
			throw e;
		}
	}

	/**
	 * Provides the means to set or reset the model to a default state.
	 */
	public void initDefault() {

	}

	// Accessors

	/**
	 * @param actualAirTemperature
	 *            the actualAirTemperature to set
	 */
	/*
	 * public void setActualAirTemperature(Double actualAirTemperature) { Double
	 * oldActualAirTemperature = this.actualAirTemperature;
	 * this.actualAirTemperature = actualAirTemperature;
	 * 
	 * firePropertyChange(DefaultController.COMP_ACTUAL_AIR_TEMP,
	 * oldActualAirTemperature, actualAirTemperature); }
	 */

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
	/*
	 * public void setActualCCDTemperature(double actualCCDTemperature) {
	 * this.actualCCDTemperature = actualCCDTemperature; }
	 */

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
	/*
	 * public void setCameraName(String cameraName) { this.cameraName =
	 * cameraName; }
	 */

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
	public void setCameraModel(long cameraModel) {
		// this.cameraModel = cameraModel;
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
	/*
	 * public void setGain(Double gain) { Double oldGain = this.gain; this.gain
	 * = gain;
	 * 
	 * firePropertyChange(DefaultController.COMP_GAIN, oldGain, gain);
	 * 
	 * }
	 */

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
	/*
	 * public void setxPixelSize(double xPixelSize) { this.xPixelSize =
	 * xPixelSize; }
	 */

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
	/*
	 * public void setyPixelSize(double yPixelSize) { this.yPixelSize =
	 * yPixelSize; }
	 */

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
	public void setyEnd(long yEnd) {
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
	 * @param ccdModels
	 *            the ccdModels to set
	 */
	/*
	 * public void setCCDModels(String[] ccdModels) { this.ccdModels =
	 * ccdModels; }
	 */

	/**
	 * @return the ccdModels
	 */
	public String[] getCCDModels() {
		return ccdModels;
	}

	/**
	 * @param originalSize
	 *            the originalSize to set
	 */
	public void setOriginalSize(Boolean originalSize) {
		Boolean oldOriginalSize = this.originalSize;
		this.originalSize = originalSize;

		firePropertyChange(DefaultController.COMP_ORIGINAL_SIZE,
				oldOriginalSize, originalSize);
	}

	/**
	 * @return the originalSize
	 */
	public boolean isOriginalSize() {
		return originalSize;
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
}
