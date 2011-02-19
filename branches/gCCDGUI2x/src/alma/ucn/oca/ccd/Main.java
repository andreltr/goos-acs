package alma.ucn.oca.ccd;

import alma.ucn.oca.ccd.controller.DefaultController;
import alma.ucn.oca.ccd.model.gCCDComponentModel;
import alma.ucn.oca.ccd.views.gCCDGUI2;

/**
 * 
 * @author Robert Eckstein
 */
public class Main {

    /** Creates a new instance of Main */
    public Main() {
        DefaultController controller = new DefaultController();

        gCCDGUI2 userInterface = new gCCDGUI2(controller);

        gCCDComponentModel componentModel = null;

        try {
            componentModel = new gCCDComponentModel();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        controller.addModel(componentModel);

        controller.addView(userInterface);

        try {
            componentModel.init();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        userInterface.pack();
        userInterface.setLocationRelativeTo(null);
        userInterface.setMinimumSize(userInterface.getSize());
        userInterface.setVisible(true);
    }

    /**
     * @param args
     *            the command line arguments
     */
    public static void main(String[] args) {
        Main main = new Main();
    }
}
