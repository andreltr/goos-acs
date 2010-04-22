package alma.ucn.oca.ccd.ui;
import java.io.File;

public class FileSelectorDialog extends javax.swing.filechooser.FileFilter{
	
	public boolean accept(File f){
		if(f.isDirectory())return true;
		String name=f.getName().toLowerCase();
		return name.endsWith("fits");		
	}	
	public String getDescription(){
		return "Archivo FITS (*.FITS)";
	}
	public String getExtension(){
		return "FITS";
	}
}