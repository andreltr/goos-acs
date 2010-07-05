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
import java.awt.Canvas;

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
	private AbstractAction abstractActionDisconnectComponent;
	private JLabel jLabelComponentConnected;
	private JLabel jLabelRadians;
	private JLabel jLabelWest;
	private JLabel jLabelEast;
	private JLabel jLabelSouth;
	private JLabel jLabelNorth;
	private AbstractAction abstractActionCloseSlit;
	private AbstractAction abstractActionOpenSlit;
	private AbstractAction abstractActionRotateRight;
	private AbstractAction abstractActionRotateLeft;
	private JPanel jPanelDomeImage;
	private JButton jButtonCloseSlit;
	private JButton jButtonOpenSlit;
	private JMenuItem openFileMenuItem;
	private JMenuItem newFileMenuItem;
	private JMenu jMenu3;
	private JMenuBar jMenuBar1;
	private Model d_model;
	private JLabel jLabelImgDome;
	

	public gDomeGUIview(Model controller) {
		super();
		this.d_model = controller;
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
						jButtonRotateRight.setAction(getAbstractActionRotateRight());
					}
					{
						jButtonOpenSlit = new JButton();
						jPanelOptions.add(jButtonOpenSlit,
								new GridBagConstraints(1, 3, 1, 1, 0.0, 0.0,
										GridBagConstraints.CENTER,
										GridBagConstraints.HORIZONTAL,
										new Insets(0, 0, 0, 0), 0, 0));
						jButtonOpenSlit.setText("Open Slit");
						jButtonOpenSlit.setAction(getAbstractActionOpenSlit());
					}
					{
						jButtonCloseSlit = new JButton();
						jPanelOptions.add(jButtonCloseSlit,
								new GridBagConstraints(3, 3, 1, 1, 0.0, 0.0,
										GridBagConstraints.CENTER,
										GridBagConstraints.HORIZONTAL,
										new Insets(0, 0, 0, 0), 0, 0));
						jPanelOptions.add(getJLabelRadians(), new GridBagConstraints(1, 1, 1, 1, 0.0, 0.0, GridBagConstraints.NORTHWEST, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelOptions.add(getJLabelComponentConnected(), new GridBagConstraints(1, 0, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jButtonCloseSlit.setText("Close Slit");
						jButtonCloseSlit.setAction(getAbstractActionCloseSlit());
						jButtonCloseSlit.disable();
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
						jPanelImage.add(jPanelDomeImage, new GridBagConstraints(1, 1, 2, 2, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(60, 2, 60, 2), 0, 0));
						jPanelImage.add(getJLabelNorth(), new GridBagConstraints(1, 0, 2, 1, 0.0, 0.0, GridBagConstraints.SOUTH, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelImage.add(getJLabelEast(), new GridBagConstraints(3, 1, 1, 2, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelImage.add(getJLabelWest(), new GridBagConstraints(0, 1, 1, 2, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelImage.add(getJLabelSouth(), new GridBagConstraints(1, 3, 2, 1, 0.0, 0.0, GridBagConstraints.NORTH, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelDomeImage.setBorder(BorderFactory
								.createBevelBorder(BevelBorder.LOWERED));
						
						jLabelImgDome = new javax.swing.JLabel();
						jLabelImgDome.setIcon(new javax.swing.ImageIcon("alma/views/images/domo/domo0001.jpg"));
						jPanelDomeImage.add(jLabelImgDome, new GridBagConstraints(1, 1, 2, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
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
	
	private AbstractAction getAbstractActionRotateRight() {
		if(abstractActionRotateRight == null) {
			abstractActionRotateRight = new AbstractAction("Rotate Right", null) {
				public void actionPerformed(ActionEvent evt) {
					actionPressRotateRight();
				}
			};
		}
		return abstractActionRotateRight;
	}
	
	private AbstractAction getAbstractActionOpenSlit() {
		if(abstractActionOpenSlit == null) {
			abstractActionOpenSlit = new AbstractAction("Open Slit", null) {
				public void actionPerformed(ActionEvent evt) {
					actionPressOpenSlit();
				}
			};
		}
		return abstractActionOpenSlit;
	}
	
	private AbstractAction getAbstractActionCloseSlit() {
		if(abstractActionCloseSlit == null) {
			abstractActionCloseSlit = new AbstractAction("Close Slit", null) {
				public void actionPerformed(ActionEvent evt) {
					actionPressCloseSlit();
				}
			};
		}
		return abstractActionCloseSlit;
	}
	
	private AbstractAction getAbstractActionDisconnectComponent() {
		if(abstractActionDisconnectComponent == null) {
			abstractActionDisconnectComponent = new AbstractAction("abstractActionDisconnectComponent", null) {
				public void actionPerformed(ActionEvent evt) {
					actionPressDisconnectComponent();
				}
			};
		}
		return abstractActionDisconnectComponent;
	}
	
	//Methods form Model Class
	
	private void actionPressRotateLeft(){
		d_model.rotateLeft((Double)jSpinnerDegrees.getValue());		
	}
	
	private void actionPressRotateRight(){
		d_model.rotateRight((Double)jSpinnerDegrees.getValue());
	
	}
	
	@SuppressWarnings("deprecation")
	private void actionPressOpenSlit(){
		jButtonOpenSlit.disable();
		d_model.openSlit();
		jButtonCloseSlit.enable();
	
	}
	
	@SuppressWarnings("deprecation")
	private void actionPressCloseSlit(){
		jButtonCloseSlit.disable();
		d_model.closeSlit();
		jButtonOpenSlit.enable();	
	}
	
	private void actionPressDisconnectComponent(){
		try {
			d_model.disconnectFromComponent();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private JLabel getJLabelNorth() {
		if(jLabelNorth == null) {
			jLabelNorth = new JLabel();
			jLabelNorth.setText("North");
		}
		return jLabelNorth;
	}
	
	private JLabel getJLabelSouth() {
		if(jLabelSouth == null) {
			jLabelSouth = new JLabel();
			jLabelSouth.setText("South");
		}
		return jLabelSouth;
	}
	
	private JLabel getJLabelEast() {
		if(jLabelEast == null) {
			jLabelEast = new JLabel();
			jLabelEast.setText("East");
		}
		return jLabelEast;
	}
	
	private JLabel getJLabelWest() {
		if(jLabelWest == null) {
			jLabelWest = new JLabel();
			jLabelWest.setText("West");
		}
		return jLabelWest;
	}
	
	private JLabel getJLabelRadians() {
		if(jLabelRadians == null) {
			jLabelRadians = new JLabel();
			jLabelRadians.setText("Radians:");
		}
		return jLabelRadians;
	}
	
	private JLabel getJLabelComponentConnected() {
		if(jLabelComponentConnected == null) {
			jLabelComponentConnected = new JLabel();
			jLabelComponentConnected.setText("Component Status:");
		}
		return jLabelComponentConnected;
	}

	private static class WindowCloseManager extends WindowAdapter {
		public void windowClosing(WindowEvent evt) {
			System.exit(0);
		}
	}

}