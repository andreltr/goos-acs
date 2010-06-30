package alma.utils;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.io.InputStream;
import java.io.ByteArrayInputStream;

import magick.*;

public class gCCDImagePanel extends JPanel {

	private static final long serialVersionUID = 1L;
	private int width;
	private int height;
	private BufferedImage bufferedImage;
	private ImageInfo magickImageInfo;
	private ImageInfo magickImageInfo2;
	private MagickImage magickImage;
	private MagickImage magickImage2;

	public gCCDImagePanel() {

	}

	public gCCDImagePanel(String filename) {
		setImage(filename);
		initComponents();
	}

	public void setImage(String filename) {
		try {
			// We read using ImageMagick
			magickImageInfo = new ImageInfo("/home/almadev/" + filename);
			magickImage = new MagickImage(magickImageInfo);

			byte[] imageArray = magickImage.imageToBlob(magickImageInfo);
			magickImageInfo2 = new ImageInfo();
			magickImage2 = new MagickImage(magickImageInfo2, imageArray);
			magickImage2.setImageFormat("bmp");
			magickImage2.writeImage(magickImageInfo2);

			byte[] imageArray2 = magickImage2.imageToBlob(magickImageInfo2);

			// We convert the byte array into a InputStream to read it using a
			// BufferedImage
			InputStream in = new ByteArrayInputStream(imageArray2);
			bufferedImage = ImageIO.read(in);

			getImageWidth();
			getImageHeight();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (MagickException ex) {
			ex.printStackTrace();
		}
	}

	public void setImage(BufferedImage image) {
		if (image != null) {
			width = image.getWidth();
			height = image.getHeight();
			bufferedImage = image;
			repaint();
		}
	}

	public void clearImage() {
		if (bufferedImage != null) {
			Graphics imageGraphics = bufferedImage.getGraphics();
			imageGraphics.setColor(Color.LIGHT_GRAY);
			imageGraphics.fillRect(0, 0, width, height);
			repaint();
		}
	}

	private void initComponents() {
		this.setPreferredSize(new Dimension(width, height));
	}

	@Override
	public void paint(Graphics g) {
		if (bufferedImage != null) {
			g.drawImage(bufferedImage, 0, 0, this.getSize().width, this
					.getSize().height, this);

			setOpaque(false);
		} else {
			setOpaque(true);
		}

		super.paint(g);
	}

	public int getImageWidth() {
		if (bufferedImage != null) {
			width = bufferedImage.getWidth();
			return width;
		}
		return 0;
	}

	public int getImageHeight() {
		if (bufferedImage != null) {
			height = bufferedImage.getHeight();
			return height;
		}
		return 0;
	}

	public Dimension getWidthHeight() {
		return new Dimension(getImageWidth(), getImageHeight());
	}

	public int getImageFrames() {
		try {
			return magickImage.getNumFrames();
		} catch (MagickException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return -1;
	}

	public int getImageSize() {
		return -1;
	}
}
