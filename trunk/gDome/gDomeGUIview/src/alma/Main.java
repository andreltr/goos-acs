
package alma;
//package alma.views;

import alma.model.Model;
import alma.views.gDomeGUIview;

/**
 * 
 * @author Robert Eckstein
 */
public class Main {

	/** Creates a new instance of Main */
	public Main() {
		Model d_model = null;
		try {
			d_model = new Model();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		

		gDomeGUIview userInterface = new gDomeGUIview(d_model); //Enviar controller
		
		try {
			d_model.connectToComponent();
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
