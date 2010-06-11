/*
 * DefaultController.java
 *
 * Created on January 22, 2007, 8:42 AM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package alma.ucn.oca.ccd.controller;

import java.awt.Font;

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
	public static final String COMP_COMMANDED_CCD_TEMP = "CommandedCCDTemperature";
	public static final String COMP_FILTER_NAME = "FilterName";
	public static final String COMP_OBJECT_NAME = "ObjectName";
	public static final String COMP_OBSERVER_NAME = "ObserverName";
	public static final String COMP_EXPOSURE_TIME = "ExposureTime";
	public static final String COMP_ACQ_MODE = "AcquisitionMode";
	public static final String COMP_NUMBER_ACQ = "NumberOfAcquisitions";
	public static final String COMP_FOCAL_LENGTH = "FocalLength";
	public static final String COMP_X_START = "xStart";
	public static final String COMP_X_END = "xEnd";
	public static final String COMP_Y_START = "yStart";
	public static final String COMP_Y_END = "yEnd";
	public static final String COMP_ORIGINAL_SIZE = "OriginalSize";
	public static final String COMP_CURRENT_IMAGE = "CurrentImage";
	public static final String COMP_CURRENT_STATE = "CurrentState";

	public void changeCompCCDTemp(double newTemp) {
		setModelProperty(COMP_COMMANDED_CCD_TEMP, newTemp);
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

	public void changeCompOriginalSize(boolean newOriginalSize) {
		setModelProperty(COMP_ORIGINAL_SIZE, newOriginalSize);
	}

	public void changeCompCurrentImage(int newCurrentImage) {
		setModelProperty(COMP_CURRENT_IMAGE, newCurrentImage);
	}
	
	public void changeCompCurrentState(String newCurrentState) {
		setModelProperty(COMP_CURRENT_STATE, newCurrentState);
	}

}
