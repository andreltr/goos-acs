package alma.ucn.oca.ccd;

import alma.ucn.oca.ccd.controller.DefaultController;
import alma.ucn.oca.ccd.model.gCCDComponentModel;
import alma.ucn.oca.ccd.views.gCCDGUIClient;

/**
 * 
 * @author Robert Eckstein
 */
public class Main {

	/** Creates a new instance of Main */
	public Main() {

		// TextElementModel textElementModel = new TextElementModel();
		// DocumentModel documentModel = new DocumentModel();
		gCCDComponentModel componentModel = null;
		try {
			componentModel = new gCCDComponentModel();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		DefaultController controller = new DefaultController();

		// DisplayViewPanel displayViewPanel = new DisplayViewPanel(controller);
		// PropertiesViewPanel propertiesViewPanel = new
		// PropertiesViewPanel(controller);
		gCCDGUIClient userInterface = new gCCDGUIClient(controller);

		// controller.addView(displayViewPanel);
		controller.addView(userInterface);
		// controller.addModel(textElementModel);
		controller.addModel(componentModel);

		// textElementModel.initDefault();
		// documentModel.initDefault();

		// JFrame displayFrame = new JFrame("Display (View 1)");
		// displayFrame.getContentPane().add(displayViewPanel,
		// BorderLayout.CENTER);
		// displayFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		// displayFrame.pack();

		// JDialog propertiesDialog = new JDialog(displayFrame,
		// "Properties (View 2)");
		// propertiesDialog.setModal(false);
		// propertiesDialog.getContentPane().add(propertiesViewPanel,
		// BorderLayout.CENTER);
		// propertiesDialog.pack();

		// displayFrame.setVisible(true);
		// propertiesDialog.setVisible(true);

		userInterface.pack();
		userInterface.setLocationRelativeTo(null);
		userInterface.setMinimumSize(userInterface.getSize());
		// userInterface.addWindowListener(new WindowCloseManager());
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
