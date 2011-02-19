package alma.ucn.oca.ccd.utils;

import java.io.File;
import javax.swing.filechooser.FileFilter;

public class FITSFileFilter extends FileFilter {

    @Override
    public boolean accept(File f) {
        if (f.isDirectory()) {
            return true;
        }
        String name = f.getName().toLowerCase();
        return name.endsWith(".fits");
    }

    @Override
    public String getDescription() {
        return "FITS file (*.FITS)";
    }

    public String getExtension() {
        return "FITS";
    }
}
