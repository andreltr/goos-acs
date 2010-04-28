package alma.ucn.oca.ccd.ui;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.io.InputStream;
import java.io.ByteArrayInputStream;

import magick.*;
import magick.util.*;

//VS4E -- DO NOT REMOVE THIS LINE!

/**
 * This code was edited or generated using CloudGarden's Jigloo SWT/Swing GUI
 * Builder, which is free for non-commercial use. If Jigloo is being used
 * commercially (ie, by a corporation, company or business for any purpose
 * whatever) then you should purchase a license for each developer using Jigloo.
 * Please visit www.cloudgarden.com for details. Use of Jigloo implies
 * acceptance of these licensing terms. A COMMERCIAL LICENSE HAS NOT BEEN
 * PURCHASED FOR THIS MACHINE, SO JIGLOO OR THIS CODE CANNOT BE USED LEGALLY FOR
 * ANY CORPORATE OR COMMERCIAL PURPOSE.
 */
public class luckyClientImagePanels extends JPanel {

	private static final long serialVersionUID = 1L;
	private int width, height;
	private BufferedImage imagen;
	int preferenceWidthPanel;
	int preferenceHeightPanel;

	public luckyClientImagePanels(int widthx, int heightx, String filename) {
		try {
			preferenceHeightPanel = heightx;
			preferenceWidthPanel = widthx;
			
			//We read using ImageMagick
			ImageInfo info = new ImageInfo("/diska/home/almadev/" + filename);
			System.out.println("Filename: "+filename);
			System.out.println("File read ImageInfo: " + info.getFileName());
			MagickImage mImage = new MagickImage(info);
			byte [] imageArray = mImage.imageToBlob(info);
			ImageInfo info2 = new ImageInfo();
			MagickImage im = new MagickImage(info2, imageArray);

			im.setImageFormat("bmp");
			im.writeImage(info2);
			byte [] imageArray2 = im.imageToBlob(info2);
			System.out.println("New file MagickImage: " + im.getImageFormat());

			//We convert the byte array into a InputStream to read it using a BufferedImage
			InputStream in = new ByteArrayInputStream(imageArray2);
			imagen = ImageIO.read(in);
			/*if(ImageIO.read(in) == null)
			    {
				System.out.println("AAAAAAAAAAAAAAAAAAAAAAAaH3");
			    }			
*/
			this.width = imagen.getWidth();// the images size
			this.height = imagen.getHeight();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (MagickException ex) {
			ex.printStackTrace();
		}

		initComponents();
	}

	// Adjusts the image to the panel size
	public void adjustImage() {
		this.setSize(preferenceWidthPanel, preferenceHeightPanel);
		this.setPreferredSize(new java.awt.Dimension(preferenceWidthPanel,
				preferenceHeightPanel));
		setOpaque(false);
	}

	// Adjusts image to its original size
	public void panelToAdjustImage() {
		this.setSize(width, height);
		this.setPreferredSize(new java.awt.Dimension(width, height));
		setOpaque(false);

	}

	public void clearImage() {
		if (imagen != null) {
			Graphics imageGraphics = imagen.getGraphics();
			imageGraphics.setColor(Color.LIGHT_GRAY);
			imageGraphics.fillRect(0, 0, width, height);
			repaint();
		}
	}

	public void setImage(BufferedImage image) {
		if (image != null) {
			width = image.getWidth();
			height = image.getHeight();
			imagen = image;
			repaint();
		}
	}

	public void setImage(String filename) {
		try {			
		        //We read using ImageMagick
			ImageInfo info = new ImageInfo("/diska/home/almadev/" + filename);
			System.out.println("File read ImageInfo: " + info.getFileName());
			MagickImage mImage = new MagickImage(info);
			System.out.println("Frames: " + mImage.getNumFrames());
			byte [] imageArray = mImage.imageToBlob(info);
			ImageInfo info2 = new ImageInfo();
			MagickImage im = new MagickImage(info2, imageArray);

			im.setImageFormat("bmp");
			im.writeImage(info2);
			byte [] imageArray2 = im.imageToBlob(info2);
			System.out.println("New file MagickImage: " + im.getImageFormat());

			//We convert the byte array into a InputStream to read it using a BufferedImage
			InputStream in = new ByteArrayInputStream(imageArray2);
			imagen = ImageIO.read(in);

			width = imagen.getWidth();
			height = imagen.getHeight();
		} catch (Exception e) {

		}
	}

	private void initComponents() {
		this.setPreferredSize(new java.awt.Dimension(width, height));

	}

	@Override
	public void paint(Graphics g) {
		if (imagen != null) {
			g.drawImage(imagen, 0, 0, this.getSize().width,
					this.getSize().height, this);

			setOpaque(false);
		} else {
			setOpaque(true);
		}

		super.paint(g);
	}
}
