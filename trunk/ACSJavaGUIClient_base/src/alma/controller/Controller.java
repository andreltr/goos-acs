/*
 * DefaultController.java
 *
 * Created on January 22, 2007, 8:42 AM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package alma.controller;

/**
 * This controller implements the required methods and provides the properties
 * necessary to work with the DisplayViewPanel and PropertyViewPanel views. Each
 * of methods in this class can be called upon by the views to update to state
 * of the registered models.
 * 
 * @author Robert Eckstein
 */
public class Controller extends AbstractController {

	// Properties this controller expects to be stored in one or more registered
	// models

	/**
	 * The document's name
	 */
	public static final String COMP_ACTUAL_AIR_TEMP = "ActualAirTemperature";
	public static final String COMP_COMMANDED_CCD_TEMP = "CommandedCCDTemperature";
	public static final String COMP_CAMERA_NAME = "CameraName";
	public static final String COMP_CAMERA_MODEL = "CameraModel";

	public static final String COMP_CURRENT_IMAGE = "CurrentImage";

	public static final String COMP_CURRENT_STATE = "CurrentState";
	public static final String COMP_CAMERA_MODELS = "CCDModels";
	public static final String COMP_SELECTED_MODEL = "SelectedCamera";

	public static final String COMP_CONNECT_METHOD = "connectToCamera";
	public static final String COMP_DISCONNECT_METHOD = "disconnectFromCamera";
	public static final String COMP_START_COOLER_METHOD = "startCooler";
	public static final String COMP_GET_CCD_VALUES = "getCCDValues";

	public void changeCompActualAirTemp(double newTemp) {
		setModelProperty(COMP_ACTUAL_AIR_TEMP, newTemp);
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

	//
	public void connectToCamera() throws Exception {
		useMethod(COMP_CONNECT_METHOD);
	}

	public void disconnectFromCamera() throws Exception {
		useMethod(COMP_DISCONNECT_METHOD);
	}

	public void startCooler() throws Exception {
		useMethod(COMP_START_COOLER_METHOD);
	}
	
	public void getCCDValues() throws Exception {
		useMethod(COMP_GET_CCD_VALUES);
	}
}