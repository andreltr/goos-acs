package alma.ucn.oca.ccd.logic;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.LinkedList;

import magick.*;
import magick.util.*;

import java.util.logging.Logger;

import javax.imageio.ImageIO;

import alma.ucn.oca.ccd.ui.gCCDGUIClient;

public class gCCDCompController {
	// Reference to CCDModel
	gCCDCompModel ccd;
	String managerLoc;
	String clientName;

	// Constructor
	public gCCDCompController() throws Exception {
		managerLoc = System.getProperty("ACS.manager");
		if (managerLoc == null) {
			System.out
					.println("Java property 'ACS.manager' must be set to the corbaloc of the ACS manager!");
			System.exit(-1);
		}
		clientName = "gCCDGUIClient";

		try {
			if (ccd == null) {
				ccd = new gCCDCompModel(null, managerLoc, clientName);
			}
		} catch (Exception e) {
			throw e;
		}
	}

	// Obtains a connection to the component
	public void getConnection() throws Exception {
		if (ccd != null) {
			ccd.connectToComponent();
		}
	}

	// Drops the connection to the component
	public void dropConnection() throws Exception {
		if (ccd != null) {
			try {
				ccd.disconnectCamera();
				ccd.tearDown();
				try {
					ccd = null;
					ccd = new gCCDCompModel(null, managerLoc, clientName);
				} catch (Exception e) {
					try {
						Logger logger = ccd.getContainerServices().getLogger();
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

	// Drop the subscription to the NC
	public void disconnectConsumer() {
		if (ccd != null) {
			ccd.disconnectConsumer();
		}
	}

	// Gets the information from the Pixel structure obtained
	public void getImage(int width, int height, int acquisitionMode,
			int numberOfAcc, float exposureTime) {
		if (ccd != null) {
			ccd.getImage(width, height, acquisitionMode, numberOfAcc,
					exposureTime);
		}
	}

	// Method to save the image in the FITS format
	public void saveImage(String imagePath, String currentImage)
			throws MagickException {

		// The received image is saved as a BMP file, and then converted to FITS
		ImageInfo info2 = new ImageInfo("/diska/home/almadev/" + currentImage);
		MagickImage image2 = new MagickImage(info2);

		image2.setFileName(imagePath);
		image2.writeImage(info2);

	}

	public LinkedList<String> getFilenameList() {
		if (ccd != null) {
			return ccd.getFilenameList();
		}
		return null;
	}

	public gCCDCompNCEvent getLastNotification() {
		if (ccd != null) {
			return ccd.getLastNotification();
		}
		return null;
	}

	// Gets the status of the consumer
	public boolean isConsumerOn() {
		if (ccd != null) {
			return ccd.isConsumerOn();
		}
		return false;
	}

	public String[] getCameraModels() {
		if (ccd != null) {
			return ccd.getCameraModels();
		}
		return null;
	}

	public void setCCDModel(int model) {
		if (ccd != null) {
			ccd.setCameraModel(model);
		}
	}
}
