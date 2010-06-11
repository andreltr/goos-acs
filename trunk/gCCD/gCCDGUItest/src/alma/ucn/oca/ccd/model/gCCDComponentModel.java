package alma.ucn.oca.ccd.model;

import alma.ucn.oca.ccd.controller.DefaultController;
import java.beans.PropertyChangeEvent;

public class gCCDComponentModel extends AbstractModel
{
	//Connection properties
	private gCCDComponentDAO ccd_dao;
	private String managerLoc;
	private String clientName;  
	
	//Component properties
    private double actualAirTemperature;
    private double actualCCDTemperature;
    private double commandedCCDTemperature;
    private String cameraName;
    private long cameraModel;
    private String filterName;
    private String objectName;
    private String observerName;
	private double exposureTime;
	private long acquisitionMode;
	private long numberOfAcquisitions;
	private double focalLength;
	private double gain;
	private double xPixelSize;
	private double yPixelSize;
	private long xStart;
	private long xEnd;
	private long yStart;
	private long yEnd;
	
	//GUI properties
    private String[] ccdModels;
    private boolean originalSize;
    private int currentImage;

    /**
     * Default constructor
     */
    public gCCDComponentModel() throws Exception {
		managerLoc = System.getProperty("ACS.manager");
		if (managerLoc == null) {
			System.out
					.println("Java property 'ACS.manager' must be set to the corbaloc of the ACS manager!");
			System.exit(-1);
		}
		clientName = "gCCDGUIClient";

		try {
			if (ccd_dao == null) {
				ccd_dao = new gCCDComponentDAO(null, managerLoc, clientName);
			}
		} catch (Exception e) {
			throw e;
		}
	}
    
    /**
     * Provides the means to set or reset the model to a default state.
     */
    public void initDefault() {
        
        setName("Sample Document");
        setWidth(500);
        setHeight(500);
        
    }
    
    
    //  Accessors
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        
        String oldName = this.name;
        this.name = name;
        
        firePropertyChange(DefaultController.DOCUMENT_NAME_PROPERTY, oldName, name);
    }


    public Integer getWidth() {
        return width;
    }

    public void setWidth(Integer width) {
        
        Integer oldWidth = this.width;
        this.width = width;
        
        firePropertyChange(DefaultController.DOCUMENT_WIDTH_PROPERTY, oldWidth, width);
    }

    public Integer getHeight() {
        return height;
    }

    public void setHeight(Integer height) {
        
        Integer oldHeight = this.height;
        this.height = height;
        
        firePropertyChange(DefaultController.DOCUMENT_HEIGHT_PROPERTY, oldHeight, height);
    } 
  
}
    

