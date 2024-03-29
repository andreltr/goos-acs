package alma;

import alma.controller.Controller;
import alma.model.Model;
import alma.views.GUIClient;

/**
 * 
 * @author Robert Eckstein
 */
public class Main {

	/** Creates a new instance of Main */
	public Main() {
		Controller controller = new Controller();

		GUIClient userInterface = new GUIClient(controller);

		Model componentModel = null;

		try {
			componentModel = new Model();
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
		new Main();
	}

}
