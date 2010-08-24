/*
 * DefaultController.java
 *
 * Created on January 22, 2007, 8:42 AM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package alma.ucn.oca.ccd.controller;

/**
 * This controller implements the required methods and provides the properties
 * necessary to work with the DisplayViewPanel and PropertyViewPanel views. Each
 * of methods in this class can be called upon by the views to update to state
 * of the registered models.
 * 
 * @author Robert Eckstein
 */
public class DefaultController extends AbstractController {

	// Properties this controller expects to be stored in one or more registered
	// models

	/**
	 * The document's name
	 */
	public static final String COMP_ACTUAL_AIR_TEMP = "ActualAirTemperature";
	public static final String COMP_ACTUAL_CCD_TEMP = "ActualCCDTemperature";
	public static final String COMP_COMMANDED_CCD_TEMP = "CommandedCCDTemperature";
	public static final String COMP_CAMERA_NAME = "CameraName";
	public static final String COMP_CAMERA_MODEL = "CameraModel";
	public static final String COMP_FILTER_NAME = "FilterName";
	public static final String COMP_OBJECT_NAME = "ObjectName";
	public static final String COMP_OBSERVER_NAME = "ObserverName";
	public static final String COMP_EXPOSURE_TIME = "ExposureTime";
	public static final String COMP_ACQ_MODE = "AcquisitionMode";
	public static final String COMP_NUMBER_ACQ = "NumberOfAcquisitions";
	public static final String COMP_FOCAL_LENGTH = "FocalLength";
	public static final String COMP_GAIN = "Gain";
	public static final String COMP_XPIXEL_SIZE = "xPixelSize";
	public static final String COMP_YPIXEL_SIZE = "yPixelSize";
	public static final String COMP_X_START = "xStart";
	public static final String COMP_X_END = "xEnd";
	public static final String COMP_Y_START = "yStart";
	public static final String COMP_Y_END = "yEnd";
	public static final String COMP_TELESCOPE_NAME = "TelescopeName";
	public static final String COMP_ORIGINAL_SIZE = "OriginalSize";
	public static final String COMP_CURRENT_IMAGE = "CurrentImage";

	public static final String COMP_CURRENT_STATE = "CurrentState";
	public static final String COMP_CAMERA_MODELS = "CCDModels";
	public static final String COMP_SELECTED_MODEL = "SelectedCamera";
	public static final String COMP_LIST_FILES = "ListFiles";
	
	public static final String COMP_IP_ADDRESS = "IP";
	public static final String COMP_DEVICE_TYPE = "DeviceType";
	
	public static final String COMP_FILE_RECEIVED = "fileReceived";
	public static final String COMP_END_SUBSCRIPTION = "endSubscription";

	public static final String COMP_CONNECT_METHOD = "connectToCamera";
	public static final String COMP_DISCONNECT_METHOD = "disconnectFromCamera";

	public static final String COMP_START_CCD_METHOD = "startCamera";
	public static final String COMP_SHUTDOWN_CCD_METHOD = "shutdownCamera";
	public static final String COMP_RESET_CCD_METHOD = "resetCamera";
	public static final String COMP_START_EXP_METHOD = "startExposure";
	public static final String COMP_STOP_EXP_METHOD = "stopExposure";
	public static final String COMP_START_COOLER_METHOD = "startCooler";
	public static final String COMP_STOP_COOLER_METHOD = "stopCooler";
	public static final String COMP_GET_CCD_VALUES = "getCCDValues";

	public void changeCompActualAirTemp(double newTemp) {
		setModelProperty(COMP_ACTUAL_AIR_TEMP, newTemp);
	}

	public void changeCompActualCCDTemp(double newTemp) {
		setModelProperty(COMP_ACTUAL_CCD_TEMP, newTemp);
	}

	public void changeCompCCDTemp(double newTemp) {
		setModelProperty(COMP_COMMANDED_CCD_TEMP, newTemp);
	}

	public void changeCompCameraName(String newCameraName) {
		setModelProperty(COMP_CAMERA_NAME, newCameraName);
	}

	public void changeCompCameraModel(long newCameraModel) {
		setModelProperty(COMP_CAMERA_MODEL, newCameraModel);
	}

	public void changeCompFilterName(String newFilterName) {
		setModelProperty(COMP_FILTER_NAME, newFilterName);
	}

	public void changeCompObjectName(String newObjectName) {
		setModelProperty(COMP_OBJECT_NAME, newObjectName);
	}

	public void changeCompObserverName(String newObserverName) {
		setModelProperty(COMP_OBSERVER_NAME, newObserverName);
	}

	public void changeCompExposureTime(double newExposureTime) {
		setModelProperty(COMP_EXPOSURE_TIME, newExposureTime);
	}

	public void changeCompAcquisitionMode(long newAcqMode) {
		setModelProperty(COMP_ACQ_MODE, newAcqMode);
	}

	public void changeCompNumberAcquisitions(long newNumberAcq) {
		setModelProperty(COMP_NUMBER_ACQ, newNumberAcq);
	}

	public void changeCompFocalLength(double newFocalLength) {
		setModelProperty(COMP_FOCAL_LENGTH, newFocalLength);
	}

	public void changeCompGain(double newGain) {
		setModelProperty(COMP_GAIN, newGain);
	}

	public void changeCompXPixelSize(double newXPixelSize) {
		setModelProperty(COMP_XPIXEL_SIZE, newXPixelSize);
	}

	public void changeCompYPixelSize(double newYPixelSize) {
		setModelProperty(COMP_YPIXEL_SIZE, newYPixelSize);
	}

	public void changeCompxStart(long newxStart) {
		setModelProperty(COMP_X_START, newxStart);
	}

	public void changeCompxEnd(long newxEnd) {
		setModelProperty(COMP_X_END, newxEnd);
	}

	public void changeCompyStart(long newyStart) {
		setModelProperty(COMP_Y_START, newyStart);
	}

	public void changeCompyEnd(long newyEnd) {
		setModelProperty(COMP_Y_END, newyEnd);
	}
	
	public void changeCompTelescopeName(String newTelescopeName) {
		setModelProperty(COMP_TELESCOPE_NAME, newTelescopeName);
	}

	public void changeCompOriginalSize(boolean newOriginalSize) {
		setModelProperty(COMP_ORIGINAL_SIZE, newOriginalSize);
	}

	public void changeCompCurrentImage(int newCurrentImage) {
		setModelProperty(COMP_CURRENT_IMAGE, newCurrentImage);
	}

	public void changeCompCurrentState(int newCurrentState) {
		setModelProperty(COMP_CURRENT_STATE, newCurrentState);
	}

	public void changeCompCCDModels(String newCCDModels) {
		setModelProperty(COMP_CAMERA_MODELS, newCCDModels);
	}

	public void changeCompSelectedCamera(int newSelectedCamera) {
		setModelProperty(COMP_SELECTED_MODEL, newSelectedCamera);
	}

	public void changeCompListFiles(int newListFiles) {
		setModelProperty(COMP_LIST_FILES, newListFiles);
	}
	
	public void changeIP(String newIP) {
		setModelProperty(COMP_IP_ADDRESS, newIP);
	}
	
	public void changeDeviceType(int newDeviceType) {
		setModelProperty(COMP_DEVICE_TYPE, newDeviceType);
	}
	
	public void changeCompFileReceived() throws Exception {
		useMethod(COMP_FILE_RECEIVED);
	}

	public void changeCompEndSubscription() throws Exception {
		useMethod(COMP_END_SUBSCRIPTION);
	}

	//
	public void connectToCamera() throws Exception {
		useMethod(COMP_CONNECT_METHOD);
	}

	public void disconnectFromCamera() throws Exception {
		useMethod(COMP_DISCONNECT_METHOD);
	}

	public void startCamera() throws Exception {
		useMethod(COMP_START_CCD_METHOD);
	}

	public void shutdownCamera() throws Exception {
		useMethod(COMP_SHUTDOWN_CCD_METHOD);
	}

	public void resetCamera() throws Exception {
		useMethod(COMP_RESET_CCD_METHOD);
	}

	public void startExposure() throws Exception {
		useMethod(COMP_START_EXP_METHOD);
	}

	public void stopExposure() throws Exception {
		useMethod(COMP_STOP_EXP_METHOD);
	}

	public void startCooler() throws Exception {
		useMethod(COMP_START_COOLER_METHOD);
	}

	public void stopCooler() throws Exception {
		useMethod(COMP_STOP_COOLER_METHOD);
	}

	public void getCCDValues() throws Exception {
		useMethod(COMP_GET_CCD_VALUES);
	}
}
