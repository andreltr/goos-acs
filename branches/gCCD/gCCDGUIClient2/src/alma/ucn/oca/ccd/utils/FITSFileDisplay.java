package alma.ucn.oca.ccd.utils;

import eap.fits.*;
import eap.filter.*;

import java.io.*;

import javax.swing.*;

import java.net.*;

/*************************************************************************
 * Component for displaying a single FITS file. This class makes up the core of
 * both the standalone and applet versions of the browser. You may embed this
 * component in some other tool which needs to display or edit the contents of a
 * FITS file.
 ***************************************************************************/
public class FITSFileDisplay extends JTabbedPane {

	JMenuBar menu_bar;
	JFileChooser file_chooser;
	JTabbedPane tabs;

	FitsFile fits;

	IOException background_exception;

	FilterBroker filters;

	// Misc
	private int currentHDU;
	private int totalHDU;
	private double fileSize;

	/****************************************************************************
	 * Create a new display which does not display any file.
	 ****************************************************************************/
	public FITSFileDisplay() {

		filters = new FilterBroker();
		try {
			filters.addDefaultFilters();
		} catch (IOException e) {
		}
		filters.setPasswordProvider(new PopupPasswordProvider(this));

	} // end of constructor

	/**************************************************************************
	 * Set the password provider to be used when reading an encrypted data
	 * stream By default this class uses a
	 * {@link eap.filter.PopupPasswordProvider}.
	 **************************************************************************/
	public void setPasswordProvider(PasswordProvider password) {

		filters.setPasswordProvider(password);
	}

	/**************************************************************************
	 * Display the given file or URL.
	 * 
	 * @param string
	 *            file name or URL to be displayed
	 **************************************************************************/
	public void load(String string) throws IOException {

		try {
			load(new URL(string));
			return;
		} catch (MalformedURLException e) {
		}

		load(new File(string));

	} // end of load String method

	/**************************************************************************
	 * Display the given file.
	 * 
	 * @param file
	 *            The file to be displayed
	 **************************************************************************/
	public void load(File file) throws IOException {
		fileSize = file.length();
		if (filters.hasFilter(file.getName())) {
			/*************************************************
			 * we need to filter the data and that means using an InputStream as
			 * the data source
			 ************************************************/
			InputStream in = new FileInputStream(file);
			InputStream filtered = filters.filter(in, file.getName());
			if (filtered != in) {
				/***********************************
				 * some filtering was actually done *
				 ***********************************/
				load(filtered);
				return;
			}

		} // end if it looked like we should filter

		/***********************************************************
		 * Either there wasn't any filtering to do, or the data didn't meet the
		 * filters expectations. In either case we are reading the raw data, so
		 * we might as well do that with a random access FITS file, since that's
		 * better for FITS I/O
		 ***********************************************************/
		load(new RandomAccessFitsFile(new RandomAccessFile(file, "r")));
	} // end of openFile method

	/**************************************************************************
	 * Displays a URL
	 * 
	 * @param url
	 *            the URL of a FITS file to display
	 **************************************************************************/
	public void load(URL url) throws IOException {

		/***********************************
		 * open the URL, possibly filtering *
		 ***********************************/
		load(filters.filter(url.openStream(), url.getPath()));

	} // end of load URL method

	/**************************************************************************
	 * Display the FITS file which can be read from the given input stream.
	 * 
	 * @param in
	 *            data stream from which to read FITS data.
	 **************************************************************************/
	public void load(InputStream in) throws IOException {

		load(new InputStreamFitsFile(in));

	} // end of load InputStream method

	/*************************************************************************
	 * Write the file currently displayed.
	 * 
	 * @param file
	 *            The file to be written.
	 *************************************************************************/
	public void save(File file) throws IOException {

		fits.write(new FileOutputStream(file));

	} // end of save method

	/**************************************************************************
	 * Display a FITS file which has previously been read by some other means.
	 * 
	 * @param fits
	 *            The FITS file to display.
	 **************************************************************************/
	public void load(FitsFile fits) throws IOException {

		this.fits = fits;

		/******************************
		 * clear out any old FITS file *
		 ******************************/
		removeAll();

		/*********************
		 * loop over all HDUs *
		 *********************/
		try {
			totalHDU = 0;
			for (int i = 0;; ++i) {

				FitsHDU hdu = fits.getHDU(i);
				FitsData data = hdu.getData();
				FitsHeader header = hdu.getHeader();

				++totalHDU;

				add(i + ". " + header.getName() + " (" + header.getType() + ")",
						new HDUDisplay(hdu));
				// pack();
				// validate();
			}
		} catch (NoSuchFitsHDUException e) {
		}

	} // end of displayFitsFile method

	public double getImageWidth() {
		try {
			return fits.getHDU(currentHDU).getHeader().card("NAXIS1")
					.doubleValue();
		} catch (NoSuchFitsCardException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return -1;
	}

	public double getImageHeight() {
		try {
			return fits.getHDU(currentHDU).getHeader().card("NAXIS2")
					.doubleValue();
		} catch (NoSuchFitsCardException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return -1;
	}

	public int getFrames() {
		return totalHDU;
	}
	
	public double getFileSize() {
		return fileSize;
	}
	
	public void setCurrentHDU(int currentHDU){
		this.currentHDU = currentHDU;
	}

} // end of FITSFileDisplay class
