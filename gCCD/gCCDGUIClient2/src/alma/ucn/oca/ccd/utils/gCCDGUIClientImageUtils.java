package alma.ucn.oca.ccd.utils;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
public class gCCDGUIClientImageUtils {
	
	
	public static BufferedImage loadBufferedImage(String fileName) throws IOException{
		BufferedImage image = null;
		try {
			/*FileInputStream fis = new FileInputStream(fileName);JPEGImageDecoder decoder = JPEGCodec.createJPEGDecoder(fis);bi = decoder.decodeAsBufferedImage();fis.close();*/
			// MAS RAPIDO a partir de 1.4
	File archid=		new File(fileName);
	archid.isFile();
			image = ImageIO.read(archid );
		}
		catch (Exception e) {
			//	logger.debug(”error al intentar leer la imágen”);
			e.printStackTrace();
			e.getMessage();
			return null;
		}
		return image;

	}

	public static BufferedImage scaleToSize(int nMaxWidth, int nMaxHeight, BufferedImage imgSrc) {
		int nHeight = imgSrc.getHeight();
		int nWidth = imgSrc.getWidth();
		double scaleX = (double)nMaxWidth / (double)nWidth;
		double scaleY = (double)nMaxHeight / (double)nHeight;
		double fScale = Math.min(scaleX, scaleY);
		return scale(fScale, imgSrc);
	}


	public static BufferedImage scale(double scale, BufferedImage srcImg) {
		if (scale == 1 ) {
			return srcImg;
		}
		AffineTransformOp op = new AffineTransformOp
		(AffineTransform.getScaleInstance(scale, scale), null);

		return op.filter(srcImg, null);

	}
}
