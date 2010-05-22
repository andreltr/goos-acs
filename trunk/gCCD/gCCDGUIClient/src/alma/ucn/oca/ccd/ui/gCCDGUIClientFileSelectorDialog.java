package alma.ucn.oca.ccd.ui;
import java.io.File;

public class gCCDGUIClientFileSelectorDialog extends javax.swing.filechooser.FileFilter{
	
	public boolean accept(File f){
		if(f.isDirectory())return true;
		String name=f.getName().toLowerCase();
		return name.endsWith("fits");		
	}	
	public String getDescription(){
		return "FITS file (*.FITS)";
	}
	public String getExtension(){
		return "FITS";
	}
}
