package alma.ucn.oca.ccd.utils;

//import java.awt.image.BufferedImage;
//import java.io.File;
//import java.io.IOException;

//import javax.imageio.ImageIO;

//import alma.ucn.oca.ccd.ui.CCDGUI;

/*
 * 
 * CCDControllerGetImage
 * 
 * This class executes in a new thread when the getImage() method
 * is called from OcaCCDCOntroller. This makes the GUI available
 * for interaction.
 * 
 */

public class gCCDCompControllerGetImage implements Runnable {
	//Array to save the received data
	int[] imgData = new int[640 * 480 * 3];

	//Reference to the controller object
	//gCCDCompController controller;

	@Override
	public void run() {
		
		//if(controller.getFilenameList() != null){
			
			
		}
	    /*		
	    //Each pixel is obtained in sequence and is stored into the array imgData
		for (int imageIndex = 0; imageIndex < 640 * 480; ++imageIndex) {
			alma.CCDmodule.Pixel currentPixel;
			currentPixel = ccd.getPixel(imageIndex);

			//composite image, it has the channels R, G and B
			imgData[imageIndex] = (int) currentPixel.R;
			imgData[imageIndex + 640 * 480] = (int) currentPixel.G;
			imgData[imageIndex + 640 * 480 * 2] = (int) currentPixel.B;
			
			//The static variable percentageIndex is updated to calculate
			//the completed percentage
			CCDGUI.percentageIndex = imageIndex;
		}
		
		//When the function ends, we set percentageIndex so that it calculates a 100%
		CCDGUI.percentageIndex = 640 * 480;

		//The data is sent back to OcaCCDController
		CCDController.setImgData(imgData);
		
		//RGB image is saved
		int width = 640;
		int height = 480;
		BufferedImage image3 = new BufferedImage(width, height,
				BufferedImage.TYPE_INT_RGB);
		image3.setRGB(0, 0, width, height, imgData, 0, width);

		try {
			ImageIO.write(image3, "bmp", new File(
					"/diska/home/almadev/Desktop/imagenRecibida.bmp"));
		} catch (IOException e) {
			e.printStackTrace();
			}*/
	//}

	//Set method to get the CCD connection reference
	//public void setController(gCCDCompController _controller) {
	    //controller = _controller;
	//}

}
