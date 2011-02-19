package alma.ucn.oca.ccd.dao;

import alma.ucn.oca.ccd.model.gCCDComponentModel;
import alma.ucn.oca.ccd.utils.gCCDNCEvent;
import java.util.logging.Logger;
import java.util.LinkedList;

public class gCCDTestDAO {

    private gCCDComponentModel model;
    // List of the received filenames
    private LinkedList<String> l_filenames;
    private gCCDNCEvent lastNotification;
    private boolean consumerOn;
    private LinkedList<String> modelsList;

    /**
     * Default constructor
     *
     * @throws Exception
     */
    public gCCDTestDAO(Logger logger, String managerLoc,
            String clientName, gCCDComponentModel model) throws Exception {

        l_filenames = null;
        lastNotification = null;
        consumerOn = false;

        setModel(model);
    }

    public void init() throws Exception {
        model.setCCDModels(getCameraModelsFromCDB());
    }

    // Obtains a connection to the ACS Component
    public void connectToComponent(String selectedCamera)
            throws Exception {
        setInitialModelValuesFromCDB();
        getCurrentState();
    }

    public void disconnectFromComponent() {
        disconnectConsumer();
        getCurrentState();
    }

    public void startCamera() {
        getCurrentState();
    }

    public void shutdownCamera() {
        getCurrentState();
    }

    public void resetCamera() {
        getCurrentState();
    }

    // This method calls the CCD component and asks for an image.
    // It also prepares the NC consumer to start receiving notifications.
    public void startExposure() throws Exception {
        getCurrentState();
    }

    public void stopExposure() {
        getCurrentState();
    }

    public void startCooler() {
        getCurrentState();
    }

    public void stopCooler() {
        getCurrentState();
    }

    public void getCurrentState() {
    }

    public void setCurrentModelValuesFromComponent() {
    }

    //
    public void setInitialModelValuesFromCDB() {
    }

    // This method disconnects the NC consumer from the channel
    public void disconnectConsumer() {
    }

    // Get method for LinkedList<String> filenames
    public LinkedList<String> getFilenameList() {
        if (l_filenames != null) {
            System.out.println("Filenames: "
                    + l_filenames.getFirst().toString());
        }
        return l_filenames;
    }

    public gCCDNCEvent getLastNotification() {
        return lastNotification;
    }

    // Returns true if the consumer is activated
    public boolean isConsumerOn() {
        return consumerOn;
    }

    public String[] getCameraModelsFromCDB() throws Exception {
        if (modelsList == null) {
            modelsList = new LinkedList<String>();
            modelsList.add("<SELECT A CAMERA MODEL>");
        }

        /*for (String s : m_containerServices.findComponents(null, null)) {
        if (m_containerServices.getComponentDescriptor(s).getType().equals(
        "IDL:alma/CCDmodule/CCDinterface:1.0")) {
        modelsList.add(m_containerServices.getComponentDescriptor(s)
        .getName());
        }
        }*/
        return modelsList.toArray(new String[0]);
    }

    private void setModel(gCCDComponentModel model) {
        this.model = model;
    }

    public gCCDComponentModel getModel() {
        return this.model;
    }

    public void tearDown() {
    }
}
