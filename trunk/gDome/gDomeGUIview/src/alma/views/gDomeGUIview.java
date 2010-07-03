package alma.views;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.*;
import javax.swing.border.BevelBorder;

import alma.model.Model;

/**
 * This code was edited or generated using CloudGarden's Jigloo SWT/Swing GUI
 * Builder, which is free for non-commercial use. If Jigloo is being used
 * commercially (ie, by a corporation, company or business for any purpose
 * whatever) then you should purchase a license for each developer using Jigloo.
 * Please visit www.cloudgarden.com for details. Use of Jigloo implies
 * acceptance of these licensing terms. A COMMERCIAL LICENSE HAS NOT BEEN
 * PURCHASED FOR THIS MACHINE, SO JIGLOO OR THIS CODE CANNOT BE USED LEGALLY FOR
 * ANY CORPORATE OR COMMERCIAL PURPOSE.
 */
public class gDomeGUIview extends javax.swing.JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JMenuItem helpMenuItem;
	private JMenu jMenu5;
	private JButton jButtonRotateRight;
	private JButton jButtonRotateLeft;
	private JSpinner jSpinnerDegrees;
	private JPanel jPanelImage;
	private JPanel jPanelOptions;
	private JPanel jPanelMain;
	private JMenuItem deleteMenuItem;
	private JSeparator jSeparator1;
	private JMenuItem pasteMenuItem;
	private JMenuItem copyMenuItem;
	private JMenuItem cutMenuItem;
	private JMenu jMenu4;
	private JMenuItem exitMenuItem;
	private JSeparator jSeparator2;
	private JMenuItem closeFileMenuItem;
	private JMenuItem saveAsMenuItem;
	private JMenuItem saveMenuItem;
	private AbstractAction abstractActionRotateLeft;
	private JPanel jPanelDomeImage;
	private JButton jButtonCloseSlit;
	private JButton jButtonOpenSlit;
	private JMenuItem openFileMenuItem;
	private JMenuItem newFileMenuItem;
	private JMenu jMenu3;
	private JMenuBar jMenuBar1;
	private Object controller;
	private Model d_model;

	public gDomeGUIview(Object controller) {
		super();
		this.controller = controller;
		initGUI();
		this.addWindowListener(new WindowCloseManager());
	}

	private void initGUI() {
		try {
			this.setSize(640, 480);
			GridBagLayout thisLayout = new GridBagLayout();
			this.setMinimumSize(new Dimension(640, 480));
			thisLayout.rowWeights = new double[] { 0.1 };
			thisLayout.rowHeights = new int[] { 7 };
			thisLayout.columnWeights = new double[] { 0.1 };
			thisLayout.columnWidths = new int[] { 7 };
			getContentPane().setLayout(thisLayout);
			{
				jPanelMain = new JPanel();
				GridBagLayout jPanelMainLayout = new GridBagLayout();
				getContentPane().add(
						jPanelMain,
						new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0,
								GridBagConstraints.CENTER,
								GridBagConstraints.BOTH,
								new Insets(0, 0, 0, 0), 0, 0));
				jPanelMainLayout.rowWeights = new double[] { 0.1 };
				jPanelMainLayout.rowHeights = new int[] { 7 };
				jPanelMainLayout.columnWeights = new double[] { 0.1, 0.1 };
				jPanelMainLayout.columnWidths = new int[] { 7, 7 };
				jPanelMain.setLayout(jPanelMainLayout);
				{
					jPanelOptions = new JPanel();
					GridBagLayout jPanelOptionsLayout = new GridBagLayout();
					jPanelMain.add(jPanelOptions, new GridBagConstraints(1, 0,
							1, 1, 0.0, 0.0, GridBagConstraints.CENTER,
							GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0,
							0));
					jPanelOptionsLayout.rowWeights = new double[] { 0.1, 0.1,
							0.1, 0.1, 0.1 };
					jPanelOptionsLayout.rowHeights = new int[] { 7, 7, 7, 7, 7 };
					jPanelOptionsLayout.columnWeights = new double[] { 0.1,
							0.1, 0.1, 0.1, 0.1 };
					jPanelOptionsLayout.columnWidths = new int[] { 7, 7, 7, 7,
							7 };
					jPanelOptions.setLayout(jPanelOptionsLayout);
					jPanelOptions.setSize(320, 426);
					jPanelOptions.setMinimumSize(new Dimension(320, 426));
					jPanelOptions.setPreferredSize(new Dimension(320, 426));
					{
						SpinnerNumberModel jSpinnerDegreesModel = new SpinnerNumberModel(
								5D, 0D, 360D, 0.1D);
						jSpinnerDegrees = new JSpinner();
						jPanelOptions.add(jSpinnerDegrees,
								new GridBagConstraints(1, 1, 3, 1, 0.0, 0.0,
										GridBagConstraints.CENTER,
										GridBagConstraints.HORIZONTAL,
										new Insets(0, 0, 0, 0), 0, 0));
						jSpinnerDegrees.setModel(jSpinnerDegreesModel);
					}
					{
						jButtonRotateLeft = new JButton();
						jPanelOptions.add(jButtonRotateLeft,
								new GridBagConstraints(1, 2, 1, 1, 0.0, 0.0,
										GridBagConstraints.CENTER,
										GridBagConstraints.HORIZONTAL,
										new Insets(0, 0, 0, 0), 0, 0));
						jButtonRotateLeft.setText("Rotate Left");
						jButtonRotateLeft.setAction(getAbstractActionRotateLeft());
					}
					{
						jButtonRotateRight = new JButton();
						jPanelOptions.add(jButtonRotateRight,
								new GridBagConstraints(3, 2, 1, 1, 0.0, 0.0,
										GridBagConstraints.CENTER,
										GridBagConstraints.HORIZONTAL,
										new Insets(0, 0, 0, 0), 0, 0));
						jButtonRotateRight.setText("Rotate Right");
					}
					{
						jButtonOpenSlit = new JButton();
						jPanelOptions.add(jButtonOpenSlit,
								new GridBagConstraints(1, 3, 1, 1, 0.0, 0.0,
										GridBagConstraints.CENTER,
										GridBagConstraints.HORIZONTAL,
										new Insets(0, 0, 0, 0), 0, 0));
						jButtonOpenSlit.setText("Open Slit");
					}
					{
						jButtonCloseSlit = new JButton();
						jPanelOptions.add(jButtonCloseSlit,
								new GridBagConstraints(3, 3, 1, 1, 0.0, 0.0,
										GridBagConstraints.CENTER,
										GridBagConstraints.HORIZONTAL,
										new Insets(0, 0, 0, 0), 0, 0));
						jButtonCloseSlit.setText("Close Slit");
					}
				}
				{
					jPanelImage = new JPanel();
					GridBagLayout jPanelImageLayout = new GridBagLayout();
					jPanelMain.add(jPanelImage, new GridBagConstraints(0, 0, 1,
							1, 0.0, 0.0, GridBagConstraints.CENTER,
							GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0,
							0));
					jPanelImage.setSize(320, 426);
					jPanelImage.setMinimumSize(new Dimension(320, 426));
					jPanelImage.setPreferredSize(new Dimension(320, 426));
					jPanelImageLayout.rowWeights = new double[] { 0.1, 0.1,
							0.1, 0.1 };
					jPanelImageLayout.rowHeights = new int[] { 7, 7, 7, 7 };
					jPanelImageLayout.columnWeights = new double[] { 0.1, 0.1,
							0.1, 0.1 };
					jPanelImageLayout.columnWidths = new int[] { 7, 7, 7, 7 };
					jPanelImage.setLayout(jPanelImageLayout);
					{
						jPanelDomeImage = new JPanel();
						jPanelImage.add(jPanelDomeImage,
								new GridBagConstraints(1, 1, 2, 2, 0.0, 0.0,
										GridBagConstraints.CENTER,
										GridBagConstraints.BOTH, new Insets(0,
												0, 0, 0), 0, 0));
						jPanelDomeImage.setBorder(BorderFactory
								.createBevelBorder(BevelBorder.LOWERED));
					}
				}
			}
			{
				jMenuBar1 = new JMenuBar();
				setJMenuBar(jMenuBar1);
				{
					jMenu3 = new JMenu();
					jMenuBar1.add(jMenu3);
					jMenu3.setText("File");
					{
						newFileMenuItem = new JMenuItem();
						jMenu3.add(newFileMenuItem);
						newFileMenuItem.setText("New");
					}
					{
						openFileMenuItem = new JMenuItem();
						jMenu3.add(openFileMenuItem);
						openFileMenuItem.setText("Open");
					}
					{
						saveMenuItem = new JMenuItem();
						jMenu3.add(saveMenuItem);
						saveMenuItem.setText("Save");
					}
					{
						saveAsMenuItem = new JMenuItem();
						jMenu3.add(saveAsMenuItem);
						saveAsMenuItem.setText("Save As ...");
					}
					{
						closeFileMenuItem = new JMenuItem();
						jMenu3.add(closeFileMenuItem);
						closeFileMenuItem.setText("Close");
					}
					{
						jSeparator2 = new JSeparator();
						jMenu3.add(jSeparator2);
					}
					{
						exitMenuItem = new JMenuItem();
						jMenu3.add(exitMenuItem);
						exitMenuItem.setText("Exit");
					}
				}
				{
					jMenu4 = new JMenu();
					jMenuBar1.add(jMenu4);
					jMenu4.setText("Edit");
					{
						cutMenuItem = new JMenuItem();
						jMenu4.add(cutMenuItem);
						cutMenuItem.setText("Cut");
					}
					{
						copyMenuItem = new JMenuItem();
						jMenu4.add(copyMenuItem);
						copyMenuItem.setText("Copy");
					}
					{
						pasteMenuItem = new JMenuItem();
						jMenu4.add(pasteMenuItem);
						pasteMenuItem.setText("Paste");
					}
					{
						jSeparator1 = new JSeparator();
						jMenu4.add(jSeparator1);
					}
					{
						deleteMenuItem = new JMenuItem();
						jMenu4.add(deleteMenuItem);
						deleteMenuItem.setText("Delete");
					}
				}
				{
					jMenu5 = new JMenu();
					jMenuBar1.add(jMenu5);
					jMenu5.setText("Help");
					{
						helpMenuItem = new JMenuItem();
						jMenu5.add(helpMenuItem);
						helpMenuItem.setText("Help");
					}
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	private AbstractAction getAbstractActionRotateLeft() {
		if(abstractActionRotateLeft == null) {
			abstractActionRotateLeft = new AbstractAction("Rotate Left", null) {
				public void actionPerformed(ActionEvent evt) {
					actionPressRotateLeft();
				}
			};
		}
		return abstractActionRotateLeft;	
	}
	
	private void actionPressRotateLeft(){
		//d_model.rotateLeft((double)3);
	
	}
		
	private static class WindowCloseManager extends WindowAdapter {
		public void windowClosing(WindowEvent evt) {
			System.exit(0);
		}
	}

}
