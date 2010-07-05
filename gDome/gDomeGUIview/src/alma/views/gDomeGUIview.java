package alma.views;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;

import java.io.*;
import java.awt.*;
import javax.swing.*;
import javax.imageio.*;

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
	private JButton jButtonRotateRight;
	private JButton jButtonRotateLeft;
	private JSpinner jSpinnerDegrees;
	private JPanel jPanelImage;
	private JPanel jPanelOptions;
	private JPanel jPanelMain;
	private AbstractAction abstractActionDisconnectComponent;
	private JLabel systemMessage;
	private JLabel jLabel1;
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
	private Model d_model;
	private JLabel jLabelImgDome;
	private JLabel indicadorComponente;
	private JLabel indicadorSlit;
	
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
			this.setTitle("ACS gDome Client");
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
					jPanelOptionsLayout.rowWeights = new double[] {0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
					jPanelOptionsLayout.rowHeights = new int[] {7, 7, 7, 7, 7, 20};
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
								0.2D, 0D, 360D, 0.1D);
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
						jPanelOptions.add(jButtonOpenSlit, new GridBagConstraints(1, 4, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0, 0), 0, 0));
						jButtonOpenSlit.setText("Open Slit");
						jButtonOpenSlit.setAction(getAbstractActionOpenSlit());
					}
					{
						jButtonCloseSlit = new JButton();
						jPanelOptions.add(jButtonCloseSlit, new GridBagConstraints(3, 4, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0, 0), 0, 0));
						jPanelOptions.add(getJLabelRadians(), new GridBagConstraints(1, 1, 1, 1, 0.0, 0.0, GridBagConstraints.NORTHWEST, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelOptions.add(getJLabelComponentConnected(), new GridBagConstraints(1, 0, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						
						indicadorComponente = new javax.swing.JLabel();
						indicadorComponente.setIcon(new javax.swing.ImageIcon("alma/views/images/green_light.gif"));
						jPanelOptions.add(indicadorComponente, new GridBagConstraints(2, 0, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						
						
						indicadorSlit = new javax.swing.JLabel();
						indicadorSlit.setIcon(new javax.swing.ImageIcon("alma/views/images/green_light.gif"));
						jPanelOptions.add(indicadorSlit, new GridBagConstraints(2, 3, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelOptions.add(getJLabel1(), new GridBagConstraints(1, 3, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						
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
						jPanelImage.add(getJLabelNorth(), new GridBagConstraints(1, 0, 2, 1, 0.0, 0.0, GridBagConstraints.SOUTH, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelImage.add(getJLabelEast(), new GridBagConstraints(3, 1, 1, 2, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelImage.add(getJLabelWest(), new GridBagConstraints(0, 1, 1, 2, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						jPanelImage.add(getJLabelSouth(), new GridBagConstraints(1, 3, 2, 1, 0.0, 0.0, GridBagConstraints.NORTH, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
						
						jPanelDomeImage = new JPanel();
						jPanelDomeImage.setBorder(BorderFactory
								.createBevelBorder(BevelBorder.LOWERED));
						jPanelImage.add(jPanelDomeImage, new GridBagConstraints(1, 1, 2, 2, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.BOTH, new Insets(60, 2, 60, 2), 0, 0));
						
						jLabelImgDome = new javax.swing.JLabel();
						jLabelImgDome.setIcon(new javax.swing.ImageIcon("alma/views/images/domo/domo0001.jpg"));
						jPanelDomeImage.add(jLabelImgDome);
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
	
	//Methods form Model Class
	
	private void actionPressRotateLeft(){
		double initialposition = d_model.getCurrentPositionDome();
		double finalposition = d_model.getCurrentPositionDome()+(Double)jSpinnerDegrees.getValue();
		int in = (int)(initialposition*90/1.5708);
		int fn = (int)(finalposition*90/1.5708);
		
		try {
			Thread.sleep(10*Math.abs(fn-in));
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		while (fn < 0) {
			fn += 360;
		};
		while (fn >= 360) {
			fn -= 360;
		};
		
		String paddingString = "";
		if (fn >= 0 && fn < 10) {
			paddingString = "00";
		} else if (fn >= 10 && fn < 100) {
			paddingString = "0";
		};
		jLabelImgDome.setIcon(new javax.swing.ImageIcon("alma/views/images/domo/domo0" + paddingString + fn +".jpg"));
		jLabelImgDome.repaint();
		jPanelDomeImage.add(jLabelImgDome);
		
		d_model.rotateLeft((Double)jSpinnerDegrees.getValue());
	}
	
	private void actionPressRotateRight(){		
		double initialposition = d_model.getCurrentPositionDome();
		double finalposition = d_model.getCurrentPositionDome()-(Double)jSpinnerDegrees.getValue();
		int in = (int)(initialposition*90/1.5708);
		int fn = (int)(finalposition*90/1.5708);
		
		try {
			Thread.sleep(10*Math.abs(in-fn));
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		while (fn < 0) {
			fn += 360;
		};
		while (fn >= 360) {
			fn -= 360;
		};
		//if (fn >= 359) fn = 359;
		
		String paddingString = "";
		if (fn >= 0 && fn < 10) {
			paddingString = "00";
		} else if (fn >= 10 && fn < 100) {
			paddingString = "0";
		};
		jLabelImgDome.setIcon(new javax.swing.ImageIcon("alma/views/images/domo/domo0" + paddingString + fn +".jpg"));
		jLabelImgDome.repaint();
		jPanelDomeImage.add(jLabelImgDome);
		
		d_model.rotateRight((Double)jSpinnerDegrees.getValue());
	
	}
	
	@SuppressWarnings("deprecation")
	private void actionPressOpenSlit(){
		jButtonOpenSlit.disable();
		d_model.openSlit();
		jButtonCloseSlit.enable();
		indicadorSlit.setIcon(new javax.swing.ImageIcon("alma/views/images/green_light.gif"));
	}
	
	@SuppressWarnings("deprecation")
	private void actionPressCloseSlit(){
		jButtonCloseSlit.disable();
		d_model.closeSlit();
		jButtonOpenSlit.enable();
		indicadorSlit.setIcon(new javax.swing.ImageIcon("alma/views/images/red_light.gif"));
	}
	
	private void actionPressDisconnectComponent(){
		try {
			d_model.disconnectFromComponent();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private void actionPressConnectComponent(){
		try {
			d_model.connectToComponent();
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
	
	private JLabel getJLabel1() {
		if(jLabel1 == null) {
			jLabel1 = new JLabel();
			jLabel1.setText("Slit Status:");
		}
		return jLabel1;
	}
	
	private JLabel getJLabel2() {
		if(systemMessage == null) {
			systemMessage = new JLabel();
			systemMessage.setText("System Message:");
		}
		return systemMessage;
	}

	private static class WindowCloseManager extends WindowAdapter {
		public void windowClosing(WindowEvent evt) {
			System.exit(0);
		}
	}

}
