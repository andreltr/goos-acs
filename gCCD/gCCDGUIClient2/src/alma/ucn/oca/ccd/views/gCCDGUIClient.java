package alma.ucn.oca.ccd.views;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Dialog.ModalityType;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.beans.PropertyChangeEvent;

import javax.swing.*;
import javax.swing.border.BevelBorder;

import alma.ucn.oca.ccd.controller.DefaultController;

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
public class gCCDGUIClient extends javax.swing.JFrame {

	/**
	 * 
	 */

	// The controller used by this view

	private DefaultController controller;

	private static final long serialVersionUID = 1L;

	private JMenuItem helpMenuItem;
	private JMenu jMenuHelp;
	private JPanel jPanelCCDSetup;
	private JPanel jPanelImageInfo;
	private JScrollPane jScrollPaneImage;
	private JSplitPane jSplitPaneHorizontal;
	private JTabbedPane jTabbedPaneOptions;
	private JSplitPane jSplitPaneVertical;
	private JMenuItem deleteMenuItem;
	private JSeparator jSeparator1;
	private JMenuItem pasteMenuItem;
	private JMenuItem copyMenuItem;
	private JMenuItem cutMenuItem;
	private JMenu jMenuEdit;
	private JRadioButton jRadioButtonCCDScanTypeAcc;
	private JRadioButton jRadioButtonCCDScanTypeSingle;
	private ButtonGroup buttonGroupCCDSettingsMenuScanType;
	private JLabel jLabelCCDScanType;
	private JSpinner jSpinnerCCDNAcc;
	private JLabel jLabelCCDNAcc;
	private JSpinner jSpinnerCCDExpTime;
	private JLabel jLabelCCDExpTime;
	private JSpinner jSpinnerCCDTemp;
	private JLabel jLabelCCDTemp;
	private JLabel jLabelCCDModels;
	private JButton jButtonCCDOn;
	private JDialog jDialogAbout;
	private JDialog jDialogError;
	private JDialog jDialogSelectCamera;
	private JDialog jDialogExposureTime;
	private JDialog jDialogAccumulations;
	private JDialog jDialogCoolerTemp;
	private JPanel jPanel2;
	private JPanel jPanel1;
	private JMenuItem jMenuItemHelpAbout;
	private JSeparator jSeparator8;
	private JMenuItem jMenuItemImageOptionsNext;
	private JMenuItem jMenuItemImageOptionsPrev;
	private JSeparator jSeparator7;
	private JMenuItem jMenuItemImageOptionsSaveAs;
	private JSeparator jSeparator6;
	private JRadioButtonMenuItem jRadioButtonMenuItemImageOptionsNormalSize;
	private JRadioButtonMenuItem jRadioButtonMenuItemImageOptionsFitSize;
	private ButtonGroup buttonGroupImageOptionsMenuImageSize;
	private JMenuItem jMenuItemCCDControlStopCooler;
	private JMenuItem jMenuItemCCDControlStartCooler;
	private JSeparator jSeparator5;
	private JMenuItem jMenuItemCCDControlStopExp;
	private JMenuItem jMenuItemCCDControlStartExp;
	private JSeparator jSeparator4;
	private JMenuItem jMenuItemCCDControlReset;
	private JSeparator jSeparator3;
	private JMenuItem jMenuItemCCDControlOff;
	private JMenuItem jMenuItemCCDControlOn;
	private ButtonGroup buttonGroupCCDSettingsTabScanType;
	private JRadioButtonMenuItem jRadioButtonCCDSettingsScanTypeAccumulative;
	private JRadioButtonMenuItem jRadioButtonCCDSettingsScanTypeSingle;
	private JMenu jMenuCCDSettingsScanType;
	private JMenuItem jMenuItemCCDSettingsNAcc;
	private JMenuItem jMenuItemCCDSettingsExpTime;
	private JMenuItem jMenuItemCCDSettingsCoolerTemp;
	private JMenuItem jMenuItemCCDSetupDisconnect;
	private JMenuItem jMenuItemCCDSetupConnect;
	private JMenuItem jMenuItemCCDSetupModels;
	private JLabel jLabelCCDInfoCameaSt;
	private JLabel jLabelCCDInfoCameraState;
	private JLabel jLabelCCDInfoCoolerSt;
	private JLabel jLabelCCDInfoCoolerState;
	private JLabel jLabelCCDInfoCurrT;
	private JLabel jLabelCCDInfoCurrTemp;
	private JLabel jLabelCCDInfo;
	private JLabel jLabelImageInfoFr;
	private JLabel jLabelImageInfoFrames;
	private JLabel jLabelImageInfoFileSz;
	private JLabel jLabelImageInfoFileSize;
	private JLabel jLabelImageInfoH;
	private JLabel jLabelImageInfoHeight;
	private JLabel jLabelImageInfoW;
	private JLabel jLabelImageInfoWidth;
	private JLabel jLabelImageInfo;
	private JButton jButtonImagePrev;
	private JButton jButtonImageNext;
	private JButton jButtonImageSaveAs;
	private JButton jButtonImageNormalSize;
	private JButton jButtonImageFitSize;
	private JButton jButtonCCDStopCooler;
	private JButton jButtonCCDStartCooler;
	private JButton jButtonCCDStopExp;
	private JButton jButtonCCDStartExp;
	private JButton jButtonCCDReset;
	private JButton jButtonCCDOff;
	private JButton jButtonDisconnect;
	private JButton jButtonCCDConnect;
	private JComboBox jComboBoxCCDModels;
	private JMenu jMenuImageOptions;
	private JLabel jLabelImageOptions;
	private JPanel jPanelImageOptions;
	private JMenu jMenuCCDControl;
	private JMenu jMenuCCDSettings;
	private JMenu jMenuCCDSetup;
	private JLabel jLabelCCDControl;
	private JLabel jLabelCCDSettings;
	private JLabel jLabelCCDSetup;
	private JPanel jPanelCCDControl;
	private JPanel jPanelCCDSettings;
	private JMenuItem exitMenuItem;
	private JSeparator jSeparator2;
	private JMenuItem closeFileMenuItem;
	private JMenuItem saveAsMenuItem;
	private JMenuItem saveMenuItem;
	private JMenuItem openFileMenuItem;
	private JMenuItem newFileMenuItem;
	private JMenu jMenuFile;
	private JMenuBar jMenuBar;

	/**
	 * Auto-generated main method to display this JFrame
	 */
	/*
	 * public static void main(String[] args) { SwingUtilities.invokeLater(new
	 * Runnable() { public void run() { gCCDGUIClient inst = new
	 * gCCDGUIClient(); inst.pack(); inst.setLocationRelativeTo(null);
	 * inst.setMinimumSize(inst.getSize()); inst.addWindowListener(new
	 * WindowCloseManager()); inst.setVisible(true); } }); }
	 */

	public gCCDGUIClient(DefaultController controller) {
		super();
		this.controller = controller;
		initGUI();
		this.addWindowListener(new WindowCloseManager());
	}

	private void initGUI() {
		try {
			{
				GridBagLayout thisLayout = new GridBagLayout();
				thisLayout.rowWeights = new double[] { 0.1 };
				thisLayout.rowHeights = new int[] { 7 };
				thisLayout.columnWeights = new double[] { 0.1 };
				thisLayout.columnWidths = new int[] { 7 };
				getContentPane().setLayout(thisLayout);
				this.setTitle("gCCD - [No camera selected]");
				{
					jSplitPaneVertical = new JSplitPane();
					getContentPane().add(
							jSplitPaneVertical,
							new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0,
									GridBagConstraints.CENTER,
									GridBagConstraints.BOTH, new Insets(0, 0,
											0, 0), 0, 0));
					jSplitPaneVertical
							.setOrientation(JSplitPane.VERTICAL_SPLIT);
					jSplitPaneVertical.setOneTouchExpandable(true);
					jSplitPaneVertical.setResizeWeight(1.0);
					{
						jTabbedPaneOptions = new JTabbedPane();
						jSplitPaneVertical.add(jTabbedPaneOptions,
								JSplitPane.RIGHT);
						jTabbedPaneOptions
								.setMinimumSize(new java.awt.Dimension(800, 200));
						jTabbedPaneOptions.setSize(800, 200);
						jTabbedPaneOptions
								.setPreferredSize(new java.awt.Dimension(800,
										200));
						jTabbedPaneOptions
								.setMaximumSize(new java.awt.Dimension(32767,
										200));
						{
							jPanelCCDSetup = new JPanel();
							GridBagLayout jPanelCCDSetupLayout = new GridBagLayout();
							jTabbedPaneOptions.addTab("CCD Setup", null,
									jPanelCCDSetup, null);
							jPanelCCDSetupLayout.rowWeights = new double[] {
									0.1, 0.1, 0.1, 0.1 };
							jPanelCCDSetupLayout.rowHeights = new int[] { 7, 7,
									7, 7 };
							jPanelCCDSetupLayout.columnWeights = new double[] {
									0.1, 0.1, 0.1, 0.1 };
							jPanelCCDSetupLayout.columnWidths = new int[] { 7,
									7, 7, 7 };
							jPanelCCDSetup.setLayout(jPanelCCDSetupLayout);
							{
								jLabelCCDSetup = new JLabel();
								jPanelCCDSetup.add(jLabelCCDSetup,
										new GridBagConstraints(0, 0, 4, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelCCDSetup.setText("CCD Setup");
							}
							{
								jLabelCCDModels = new JLabel();
								jPanelCCDSetup.add(jLabelCCDModels,
										new GridBagConstraints(0, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelCCDModels.setText("Select CCD Model:");
							}
							{
								ComboBoxModel jComboBoxCCDModelsModel = new DefaultComboBoxModel(
										new String[] { "Item One", "Item Two" });
								jComboBoxCCDModels = new JComboBox();
								jPanelCCDSetup.add(jComboBoxCCDModels,
										new GridBagConstraints(1, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jComboBoxCCDModels
										.setModel(jComboBoxCCDModelsModel);
								jComboBoxCCDModels
										.addActionListener(new ActionListener() {
											@Override
											public void actionPerformed(
													ActionEvent e) {
												changeCCD(e);
											}
										});
							}
							{
								jButtonCCDConnect = new JButton();
								jPanelCCDSetup.add(jButtonCCDConnect,
										new GridBagConstraints(0, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jButtonCCDConnect.setText("Connect");
								jButtonCCDConnect
										.addActionListener(new ActionListener() {
											@Override
											public void actionPerformed(
													ActionEvent e) {
												connectAction(e);
											}
										});
							}
							{
								jButtonDisconnect = new JButton();
								jPanelCCDSetup.add(jButtonDisconnect,
										new GridBagConstraints(1, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jButtonDisconnect.setText("Disconnect");
								jButtonDisconnect.setEnabled(false);
								jButtonDisconnect
										.addActionListener(new ActionListener() {
											@Override
											public void actionPerformed(
													ActionEvent e) {
												disconnectAction(e);
											}
										});
							}
						}
						{
							jPanelCCDSettings = new JPanel();
							GridBagLayout jPanelCCDSettingsLayout = new GridBagLayout();
							jTabbedPaneOptions.addTab("CCD Settings", null,
									jPanelCCDSettings, null);
							jPanelCCDSettingsLayout.rowWeights = new double[] {
									0.1, 0.1, 0.1, 0.1 };
							jPanelCCDSettingsLayout.rowHeights = new int[] { 7,
									7, 7, 7 };
							jPanelCCDSettingsLayout.columnWeights = new double[] {
									0.1, 0.1, 0.1, 0.1 };
							jPanelCCDSettingsLayout.columnWidths = new int[] {
									7, 7, 7, 7 };
							jPanelCCDSettings
									.setLayout(jPanelCCDSettingsLayout);
							{
								jLabelCCDSettings = new JLabel();
								jPanelCCDSettings.add(jLabelCCDSettings,
										new GridBagConstraints(0, 0, 4, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelCCDSettings.setText("CCD Settings");
							}
							{
								jLabelCCDTemp = new JLabel();
								jPanelCCDSettings.add(jLabelCCDTemp,
										new GridBagConstraints(0, 3, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelCCDTemp
										.setText("Cooling Temperature (ºC):");
							}
							{
								SpinnerListModel jSpinnerCCDTempModel = new SpinnerListModel(
										new String[] { "Sun", "Mon", "Tue",
												"Wed", "Thu", "Fri", "Sat" });
								jSpinnerCCDTemp = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDTemp,
										new GridBagConstraints(1, 3, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jSpinnerCCDTemp.setModel(jSpinnerCCDTempModel);
							}
							{
								jLabelCCDExpTime = new JLabel();
								jPanelCCDSettings.add(jLabelCCDExpTime,
										new GridBagConstraints(0, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelCCDExpTime.setText("Exposure Time (s):");
							}
							{
								SpinnerListModel jSpinnerCCDExpTimeModel = new SpinnerListModel(
										new String[] { "Sun", "Mon", "Tue",
												"Wed", "Thu", "Fri", "Sat" });
								jSpinnerCCDExpTime = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDExpTime,
										new GridBagConstraints(1, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jSpinnerCCDExpTime
										.setModel(jSpinnerCCDExpTimeModel);
								jSpinnerCCDExpTime
										.addChangeListener(new javax.swing.event.ChangeListener() {
											public void stateChanged(
													javax.swing.event.ChangeEvent evt) {
												exposureTimeSpinnerStateChanged(evt);
											}
										});
							}
							{
								jLabelCCDNAcc = new JLabel();
								jPanelCCDSettings.add(jLabelCCDNAcc,
										new GridBagConstraints(0, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelCCDNAcc.setText("Accumulations:");
							}
							{
								SpinnerListModel jSpinnerCCDNAccModel = new SpinnerListModel(
										new String[] { "Sun", "Mon", "Tue",
												"Wed", "Thu", "Fri", "Sat" });
								jSpinnerCCDNAcc = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDNAcc,
										new GridBagConstraints(1, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jSpinnerCCDNAcc.setModel(jSpinnerCCDNAccModel);
								jSpinnerCCDNAcc
										.addChangeListener(new javax.swing.event.ChangeListener() {
											public void stateChanged(
													javax.swing.event.ChangeEvent evt) {
												numberAccSpinnerStateChanged(evt);
											}
										});
							}
							{
								jLabelCCDScanType = new JLabel();
								jPanelCCDSettings.add(jLabelCCDScanType,
										new GridBagConstraints(2, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDSettings.add(
										getJRadioButtonCCDScanTypeSingle(),
										new GridBagConstraints(3, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDSettings.add(
										getJRadioButtonCCDScanTypeAcc(),
										new GridBagConstraints(3, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelCCDScanType.setText("Scan Type:");
							}
						}
						{
							jPanelCCDControl = new JPanel();
							GridBagLayout jPanelCCDControlLayout = new GridBagLayout();
							jTabbedPaneOptions.addTab("CCD Control", null,
									jPanelCCDControl, null);
							jPanelCCDControlLayout.rowWeights = new double[] {
									0.1, 0.1, 0.1, 0.1 };
							jPanelCCDControlLayout.rowHeights = new int[] { 7,
									7, 7, 7 };
							jPanelCCDControlLayout.columnWeights = new double[] {
									0.1, 0.1, 0.1, 0.1 };
							jPanelCCDControlLayout.columnWidths = new int[] {
									7, 7, 7, 7 };
							jPanelCCDControl.setLayout(jPanelCCDControlLayout);
							{
								jLabelCCDControl = new JLabel();
								jPanelCCDControl.add(jLabelCCDControl,
										new GridBagConstraints(0, 0, 4, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDControl.add(getJButtonCCDOn(),
										new GridBagConstraints(0, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDControl.add(getJButtonCCDOff(),
										new GridBagConstraints(0, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDControl.add(getJButtonCCDReset(),
										new GridBagConstraints(0, 3, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDControl.add(getJButtonCCDStartExp(),
										new GridBagConstraints(2, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDControl.add(getJButtonCCDStopExp(),
										new GridBagConstraints(2, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDControl.add(
										getJButtonCCDStartCooler(),
										new GridBagConstraints(3, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDControl.add(getJButtonCCDStopCooler(),
										new GridBagConstraints(3, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelCCDControl.setText("CCD Control");
							}
						}
						{
							jPanelImageOptions = new JPanel();
							GridBagLayout jPanelImageOptionsLayout = new GridBagLayout();
							jTabbedPaneOptions.addTab("Image Options", null,
									jPanelImageOptions, null);

							jTabbedPaneOptions.setEnabledAt(1, false);
							jTabbedPaneOptions.setEnabledAt(2, false);
							jTabbedPaneOptions.setEnabledAt(3, false);

							jPanelImageOptionsLayout.rowWeights = new double[] {
									0.1, 0.1, 0.1, 0.1 };
							jPanelImageOptionsLayout.rowHeights = new int[] {
									7, 7, 7, 7 };
							jPanelImageOptionsLayout.columnWeights = new double[] {
									0.1, 0.1, 0.1, 0.1 };
							jPanelImageOptionsLayout.columnWidths = new int[] {
									7, 7, 7, 7 };
							jPanelImageOptions
									.setLayout(jPanelImageOptionsLayout);
							{
								jLabelImageOptions = new JLabel();
								jPanelImageOptions.add(jLabelImageOptions,
										new GridBagConstraints(0, 0, 4, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelImageOptions.add(
										getJButtonImageFitSize(),
										new GridBagConstraints(0, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelImageOptions.add(
										getJButtonImageNormalSize(),
										new GridBagConstraints(0, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelImageOptions.add(getJButtonImageSaveAs(),
										new GridBagConstraints(1, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelImageOptions.add(getJButtonImagePrev(),
										new GridBagConstraints(2, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelImageOptions.add(getJButtonImageNext(),
										new GridBagConstraints(3, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jLabelImageOptions.setText("Image Options");
							}
						}
					}
					{
						jSplitPaneHorizontal = new JSplitPane();
						jSplitPaneVertical.add(jSplitPaneHorizontal,
								JSplitPane.LEFT);
						jSplitPaneHorizontal.setOneTouchExpandable(true);
						jSplitPaneHorizontal.setResizeWeight(1.0);
						{
							jPanelImageInfo = new JPanel();
							BoxLayout jPanelImageInfoLayout = new BoxLayout(
									jPanelImageInfo,
									javax.swing.BoxLayout.Y_AXIS);
							jPanelImageInfo.setLayout(jPanelImageInfoLayout);
							jSplitPaneHorizontal.add(jPanelImageInfo,
									JSplitPane.RIGHT);
							jPanelImageInfo
									.setMinimumSize(new java.awt.Dimension(200,
											400));
							jPanelImageInfo.setSize(200, 400);
							jPanelImageInfo
									.setPreferredSize(new java.awt.Dimension(
											200, 400));
							jPanelImageInfo
									.setMaximumSize(new java.awt.Dimension(200,
											32767));
							jPanelImageInfo.add(getJPanel2());
							jPanelImageInfo.add(getJPanel1());
						}
						{
							jScrollPaneImage = new JScrollPane();
							jSplitPaneHorizontal.add(jScrollPaneImage,
									JSplitPane.LEFT);
							jScrollPaneImage
									.setMinimumSize(new java.awt.Dimension(600,
											400));
							jScrollPaneImage.setSize(600, 400);
							jScrollPaneImage
									.setPreferredSize(new java.awt.Dimension(
											600, 400));
							jScrollPaneImage
									.setMaximumSize(new java.awt.Dimension(
											32767, 32767));
						}
					}
				}
			}
			{
				jMenuBar = new JMenuBar();
				setJMenuBar(jMenuBar);
				{
					jMenuFile = new JMenu();
					jMenuBar.add(jMenuFile);
					jMenuFile.setText("File");
					{
						newFileMenuItem = new JMenuItem();
						jMenuFile.add(newFileMenuItem);
						newFileMenuItem.setText("New");
					}
					{
						openFileMenuItem = new JMenuItem();
						jMenuFile.add(openFileMenuItem);
						openFileMenuItem.setText("Open");
					}
					{
						saveMenuItem = new JMenuItem();
						jMenuFile.add(saveMenuItem);
						saveMenuItem.setText("Save");
					}
					{
						saveAsMenuItem = new JMenuItem();
						jMenuFile.add(saveAsMenuItem);
						saveAsMenuItem.setText("Save As ...");
					}
					{
						closeFileMenuItem = new JMenuItem();
						jMenuFile.add(closeFileMenuItem);
						closeFileMenuItem.setText("Close");
					}
					{
						jSeparator2 = new JSeparator();
						jMenuFile.add(jSeparator2);
					}
					{
						exitMenuItem = new JMenuItem();
						jMenuFile.add(exitMenuItem);
						exitMenuItem.setText("Exit");
					}
				}
				{
					jMenuEdit = new JMenu();
					jMenuBar.add(jMenuEdit);
					jMenuEdit.setText("Edit");
					{
						cutMenuItem = new JMenuItem();
						jMenuEdit.add(cutMenuItem);
						cutMenuItem.setText("Cut");
					}
					{
						copyMenuItem = new JMenuItem();
						jMenuEdit.add(copyMenuItem);
						copyMenuItem.setText("Copy");
					}
					{
						pasteMenuItem = new JMenuItem();
						jMenuEdit.add(pasteMenuItem);
						pasteMenuItem.setText("Paste");
					}
					{
						jSeparator1 = new JSeparator();
						jMenuEdit.add(jSeparator1);
					}
					{
						deleteMenuItem = new JMenuItem();
						jMenuEdit.add(deleteMenuItem);
						deleteMenuItem.setText("Delete");
					}
				}
				{
					jMenuCCDSetup = new JMenu();
					jMenuBar.add(jMenuCCDSetup);
					jMenuCCDSetup.setText("CCD Setup");
					jMenuCCDSetup.add(getJMenuCCDSetupModels());
					jMenuCCDSetup.add(getJMenuItemCCDSetupConnect());
					jMenuCCDSetup.add(getJMenuItemCCDSetupDisconnect());
				}
				{
					jMenuCCDSettings = new JMenu();
					jMenuBar.add(jMenuCCDSettings);
					jMenuCCDSettings.setText("CCD Settings");
					jMenuCCDSettings.add(getJMenuItemCCDSettingsExpTime());
					jMenuCCDSettings.add(getJMenuItemCCDSettingsNAcc());
					jMenuCCDSettings.add(getJMenuCCDSettingsScanType());
					jMenuCCDSettings.add(getJMenuItemCCDSettingsCoolerTemp());
				}
				{
					jMenuCCDControl = new JMenu();
					jMenuBar.add(jMenuCCDControl);
					jMenuCCDControl.setText("CCDControl");
					jMenuCCDControl.add(getJMenuItemCCDControlOn());
					jMenuCCDControl.add(getJMenuItemCCDControlOff());
					jMenuCCDControl.add(getJSeparator3());
					jMenuCCDControl.add(getJMenuItemCCDControlReset());
					jMenuCCDControl.add(getJSeparator4());
					jMenuCCDControl.add(getJMenuItemCCDControlStartExp());
					jMenuCCDControl.add(getJMenuItemCCDControlStopExp());
					jMenuCCDControl.add(getJSeparator5());
					jMenuCCDControl.add(getJMenuItemCCDControlStartCooler());
					jMenuCCDControl.add(getJMenuItemCCDControlStopCooler());
				}
				{
					jMenuImageOptions = new JMenu();
					jMenuBar.add(jMenuImageOptions);
					jMenuImageOptions.setText("Image Options");
					jMenuImageOptions
							.add(getJRadioButtonMenuItemImageOptionsFitImage());
					jMenuImageOptions
							.add(getJRadioButtonMenuItemImageOptionsNormalSize());
					jMenuImageOptions.add(getJSeparator6());
					jMenuImageOptions.add(getJMenuItemImageOptionsSaveAs());
					jMenuImageOptions.add(getJSeparator7());
					jMenuImageOptions.add(getJMenuItemImageOptionsPrev());
					jMenuImageOptions.add(getJMenuItemImageOptionsNext());
				}

				jMenuCCDSettings.setEnabled(false);
				jMenuCCDControl.setEnabled(false);
				jMenuImageOptions.setEnabled(false);

				{
					jMenuHelp = new JMenu();
					jMenuBar.add(jMenuHelp);
					jMenuHelp.setText("Help");
					{
						helpMenuItem = new JMenuItem();
						jMenuHelp.add(helpMenuItem);
						jMenuHelp.add(getJSeparator8());
						jMenuHelp.add(getJMenuItemHelpAbout());
						helpMenuItem.setText("Help");
					}
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private ButtonGroup getButtonGroupCCDSettingsMenuScanType() {
		if (buttonGroupCCDSettingsMenuScanType == null) {
			buttonGroupCCDSettingsMenuScanType = new ButtonGroup();
		}
		return buttonGroupCCDSettingsMenuScanType;
	}

	private JRadioButton getJRadioButtonCCDScanTypeSingle() {
		if (jRadioButtonCCDScanTypeSingle == null) {
			jRadioButtonCCDScanTypeSingle = new JRadioButton();
			jRadioButtonCCDScanTypeSingle.setText("Single Scan");
			getButtonGroupCCDSettingsTabScanType().add(
					jRadioButtonCCDScanTypeSingle);
		}
		return jRadioButtonCCDScanTypeSingle;
	}

	private JRadioButton getJRadioButtonCCDScanTypeAcc() {
		if (jRadioButtonCCDScanTypeAcc == null) {
			jRadioButtonCCDScanTypeAcc = new JRadioButton();
			jRadioButtonCCDScanTypeAcc.setText("Accumulative");
			getButtonGroupCCDSettingsTabScanType().add(
					jRadioButtonCCDScanTypeAcc);
		}
		return jRadioButtonCCDScanTypeAcc;
	}

	private JButton getJButtonCCDOn() {
		if (jButtonCCDOn == null) {
			jButtonCCDOn = new JButton();
			jButtonCCDOn.setText("Start CCD");
			jButtonCCDOn.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					startCameraAction(e);
				}
			});
		}
		return jButtonCCDOn;
	}

	private JButton getJButtonCCDOff() {
		if (jButtonCCDOff == null) {
			jButtonCCDOff = new JButton();
			jButtonCCDOff.setText("Shutdown CCD");
			jButtonCCDOff.setEnabled(false);
			jButtonCCDOff.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					shutdownCameraAction(e);
				}
			});
		}
		return jButtonCCDOff;
	}

	private JButton getJButtonCCDReset() {
		if (jButtonCCDReset == null) {
			jButtonCCDReset = new JButton();
			jButtonCCDReset.setText("Reset CCD");
			jButtonCCDReset.setEnabled(false);
			jButtonCCDReset.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					resetCameraAction(e);
				}
			});
		}
		return jButtonCCDReset;
	}

	private JButton getJButtonCCDStartExp() {
		if (jButtonCCDStartExp == null) {
			jButtonCCDStartExp = new JButton();
			jButtonCCDStartExp.setText("Start Exposure");
			jButtonCCDStartExp.setEnabled(false);
			jButtonCCDStartExp.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					startExposureAction(e);
				}
			});
		}
		return jButtonCCDStartExp;
	}

	private JButton getJButtonCCDStopExp() {
		if (jButtonCCDStopExp == null) {
			jButtonCCDStopExp = new JButton();
			jButtonCCDStopExp.setText("Stop Exposure");
			jButtonCCDStopExp.setEnabled(false);
			jButtonCCDStopExp.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					stopExposureAction(e);
				}
			});
		}
		return jButtonCCDStopExp;
	}

	private JButton getJButtonCCDStartCooler() {
		if (jButtonCCDStartCooler == null) {
			jButtonCCDStartCooler = new JButton();
			jButtonCCDStartCooler.setText("Start Cooler");
			jButtonCCDStartCooler.setEnabled(false);
			jButtonCCDStartCooler.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					startCoolerAction(e);
				}
			});
		}
		return jButtonCCDStartCooler;
	}

	private JButton getJButtonCCDStopCooler() {
		if (jButtonCCDStopCooler == null) {
			jButtonCCDStopCooler = new JButton();
			jButtonCCDStopCooler.setText("Stop Cooler");
			jButtonCCDStopCooler.setEnabled(false);
			jButtonCCDStopCooler.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					stopCoolerAction(e);
				}
			});
		}
		return jButtonCCDStopCooler;
	}

	private JButton getJButtonImageFitSize() {
		if (jButtonImageFitSize == null) {
			jButtonImageFitSize = new JButton();
			jButtonImageFitSize.setText("Fit Image To Panel");
		}
		return jButtonImageFitSize;
	}

	private JButton getJButtonImageNormalSize() {
		if (jButtonImageNormalSize == null) {
			jButtonImageNormalSize = new JButton();
			jButtonImageNormalSize.setText("Original Image Size");
		}
		return jButtonImageNormalSize;
	}

	private JButton getJButtonImageSaveAs() {
		if (jButtonImageSaveAs == null) {
			jButtonImageSaveAs = new JButton();
			jButtonImageSaveAs.setText("Save Image As...");
		}
		return jButtonImageSaveAs;
	}

	private JButton getJButtonImageNext() {
		if (jButtonImageNext == null) {
			jButtonImageNext = new JButton();
			jButtonImageNext.setText("Next Image");
		}
		return jButtonImageNext;
	}

	private JButton getJButtonImagePrev() {
		if (jButtonImagePrev == null) {
			jButtonImagePrev = new JButton();
			jButtonImagePrev.setText("Previous Image");
		}
		return jButtonImagePrev;
	}

	private JLabel getJLabelImageInfo() {
		if (jLabelImageInfo == null) {
			jLabelImageInfo = new JLabel();
			jLabelImageInfo.setText("Image Information");
		}
		return jLabelImageInfo;
	}

	private JLabel getJLabelImageInfoWidth() {
		if (jLabelImageInfoWidth == null) {
			jLabelImageInfoWidth = new JLabel();
			jLabelImageInfoWidth.setText("Width (px):");
		}
		return jLabelImageInfoWidth;
	}

	private JLabel getJLabelImageInfoW() {
		if (jLabelImageInfoW == null) {
			jLabelImageInfoW = new JLabel();
			jLabelImageInfoW.setText("999");
		}
		return jLabelImageInfoW;
	}

	private JLabel getJLabelImageInfoHeight() {
		if (jLabelImageInfoHeight == null) {
			jLabelImageInfoHeight = new JLabel();
			jLabelImageInfoHeight.setText("Height (px):");
		}
		return jLabelImageInfoHeight;
	}

	private JLabel getJLabelImageInfoH() {
		if (jLabelImageInfoH == null) {
			jLabelImageInfoH = new JLabel();
			jLabelImageInfoH.setText("999");
		}
		return jLabelImageInfoH;
	}

	private JLabel getJLabelImageInfoFileSize() {
		if (jLabelImageInfoFileSize == null) {
			jLabelImageInfoFileSize = new JLabel();
			jLabelImageInfoFileSize.setText("File Size (kB):");
		}
		return jLabelImageInfoFileSize;
	}

	private JLabel getJLabelImageInfoFileSz() {
		if (jLabelImageInfoFileSz == null) {
			jLabelImageInfoFileSz = new JLabel();
			jLabelImageInfoFileSz.setText("999");
		}
		return jLabelImageInfoFileSz;
	}

	private JLabel getJLabelImageInfoFrames() {
		if (jLabelImageInfoFrames == null) {
			jLabelImageInfoFrames = new JLabel();
			jLabelImageInfoFrames.setText("Frames:");
		}
		return jLabelImageInfoFrames;
	}

	private JLabel getJLabelImageInfoFr() {
		if (jLabelImageInfoFr == null) {
			jLabelImageInfoFr = new JLabel();
			jLabelImageInfoFr.setText("999");
		}
		return jLabelImageInfoFr;
	}

	private JLabel getJLabelCCDInfo() {
		if (jLabelCCDInfo == null) {
			jLabelCCDInfo = new JLabel();
			jLabelCCDInfo.setText("CCD Information");
		}
		return jLabelCCDInfo;
	}

	private JLabel getJLabelCCDInfoCurrTemp() {
		if (jLabelCCDInfoCurrTemp == null) {
			jLabelCCDInfoCurrTemp = new JLabel();
			jLabelCCDInfoCurrTemp.setText("Current Temperature (ºC):");
		}
		return jLabelCCDInfoCurrTemp;
	}

	private JLabel getJLabelCCDInfoCurrT() {
		if (jLabelCCDInfoCurrT == null) {
			jLabelCCDInfoCurrT = new JLabel();
			jLabelCCDInfoCurrT.setText("999");
		}
		return jLabelCCDInfoCurrT;
	}

	private JLabel getJLabelCCDInfoCoolerState() {
		if (jLabelCCDInfoCoolerState == null) {
			jLabelCCDInfoCoolerState = new JLabel();
			jLabelCCDInfoCoolerState.setText("Cooler State:");
		}
		return jLabelCCDInfoCoolerState;
	}

	private JLabel getJLabelCCDInfoCoolerSt() {
		if (jLabelCCDInfoCoolerSt == null) {
			jLabelCCDInfoCoolerSt = new JLabel();
			jLabelCCDInfoCoolerSt.setText("Off");
			jLabelCCDInfoCoolerSt.setToolTipText("On/Off");
		}
		return jLabelCCDInfoCoolerSt;
	}

	private JLabel getJLabelCCDInfoCameraState() {
		if (jLabelCCDInfoCameraState == null) {
			jLabelCCDInfoCameraState = new JLabel();
			jLabelCCDInfoCameraState.setText("Camera State:");
		}
		return jLabelCCDInfoCameraState;
	}

	private JLabel getJLabelCCDInfoCameaSt() {
		if (jLabelCCDInfoCameaSt == null) {
			jLabelCCDInfoCameaSt = new JLabel();
			jLabelCCDInfoCameaSt.setText("---");
			jLabelCCDInfoCameaSt
					.setToolTipText("Working/On/Off/Disconnected/Connected");
		}
		return jLabelCCDInfoCameaSt;
	}

	private JMenuItem getJMenuCCDSetupModels() {
		if (jMenuItemCCDSetupModels == null) {
			jMenuItemCCDSetupModels = new JMenuItem();
			jMenuItemCCDSetupModels.setText("Select camera model...");
			jMenuItemCCDSetupModels.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent evt) {
					getJDialogSelectCamera();
				}
			});
		}
		return jMenuItemCCDSetupModels;
	}

	private JMenuItem getJMenuItemCCDSetupConnect() {
		if (jMenuItemCCDSetupConnect == null) {
			jMenuItemCCDSetupConnect = new JMenuItem();
			jMenuItemCCDSetupConnect.setText("Connect");
			jMenuItemCCDSetupConnect.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					connectAction(e);
				}
			});
		}
		return jMenuItemCCDSetupConnect;
	}

	private JMenuItem getJMenuItemCCDSetupDisconnect() {
		if (jMenuItemCCDSetupDisconnect == null) {
			jMenuItemCCDSetupDisconnect = new JMenuItem();
			jMenuItemCCDSetupDisconnect.setText("Disconnect");
			jMenuItemCCDSetupDisconnect.setEnabled(false);
			jMenuItemCCDSetupDisconnect.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					disconnectAction(e);
				}
			});
		}
		return jMenuItemCCDSetupDisconnect;
	}

	private JMenuItem getJMenuItemCCDSettingsCoolerTemp() {
		if (jMenuItemCCDSettingsCoolerTemp == null) {
			jMenuItemCCDSettingsCoolerTemp = new JMenuItem();
			jMenuItemCCDSettingsCoolerTemp.setText("Cooler Temperature...");
			jMenuItemCCDSettingsCoolerTemp.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent evt) {
					getJDialogCoolerTemp();
				}
			});
		}
		return jMenuItemCCDSettingsCoolerTemp;
	}

	private JMenuItem getJMenuItemCCDSettingsExpTime() {
		if (jMenuItemCCDSettingsExpTime == null) {
			jMenuItemCCDSettingsExpTime = new JMenuItem();
			jMenuItemCCDSettingsExpTime.setText("Exposure Time...");
			jMenuItemCCDSettingsExpTime.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent evt) {
					getJDialogExposureTime();
				}
			});
		}
		return jMenuItemCCDSettingsExpTime;
	}

	private JMenuItem getJMenuItemCCDSettingsNAcc() {
		if (jMenuItemCCDSettingsNAcc == null) {
			jMenuItemCCDSettingsNAcc = new JMenuItem();
			jMenuItemCCDSettingsNAcc.setText("Accumulations...");
			jMenuItemCCDSettingsNAcc.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent evt) {
					getJDialogAccumulations();
				}
			});
		}
		return jMenuItemCCDSettingsNAcc;
	}

	private JMenu getJMenuCCDSettingsScanType() {
		if (jMenuCCDSettingsScanType == null) {
			jMenuCCDSettingsScanType = new JMenu();
			jMenuCCDSettingsScanType.setText("Scan Type");
			jMenuCCDSettingsScanType
					.add(getJRadioButtonCCDSettingsScanTypeSingle());
			jMenuCCDSettingsScanType
					.add(getJRadioButtonCCDSettingsScanTypeAccumulated());
		}
		return jMenuCCDSettingsScanType;
	}

	private ButtonGroup getButtonGroupCCDSettingsTabScanType() {
		if (buttonGroupCCDSettingsTabScanType == null) {
			buttonGroupCCDSettingsTabScanType = new ButtonGroup();
		}
		return buttonGroupCCDSettingsTabScanType;
	}

	private JRadioButtonMenuItem getJRadioButtonCCDSettingsScanTypeSingle() {
		if (jRadioButtonCCDSettingsScanTypeSingle == null) {
			jRadioButtonCCDSettingsScanTypeSingle = new JRadioButtonMenuItem();
			jRadioButtonCCDSettingsScanTypeSingle.setText("Single Scan");
			getButtonGroupCCDSettingsMenuScanType().add(
					jRadioButtonCCDSettingsScanTypeSingle);
		}
		return jRadioButtonCCDSettingsScanTypeSingle;
	}

	private JRadioButtonMenuItem getJRadioButtonCCDSettingsScanTypeAccumulated() {
		if (jRadioButtonCCDSettingsScanTypeAccumulative == null) {
			jRadioButtonCCDSettingsScanTypeAccumulative = new JRadioButtonMenuItem();
			jRadioButtonCCDSettingsScanTypeAccumulative.setText("Accumulative");
			getButtonGroupCCDSettingsMenuScanType().add(
					jRadioButtonCCDSettingsScanTypeAccumulative);
		}
		return jRadioButtonCCDSettingsScanTypeAccumulative;
	}

	private JMenuItem getJMenuItemCCDControlOn() {
		if (jMenuItemCCDControlOn == null) {
			jMenuItemCCDControlOn = new JMenuItem();
			jMenuItemCCDControlOn.setText("Start CCD");
			jMenuItemCCDControlOn.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					startCameraAction(e);
				}
			});
		}
		return jMenuItemCCDControlOn;
	}

	private JMenuItem getJMenuItemCCDControlOff() {
		if (jMenuItemCCDControlOff == null) {
			jMenuItemCCDControlOff = new JMenuItem();
			jMenuItemCCDControlOff.setText("Shutdown CCD");
			jMenuItemCCDControlOff.setEnabled(false);
			jMenuItemCCDControlOff.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					shutdownCameraAction(e);
				}
			});
		}
		return jMenuItemCCDControlOff;
	}

	private JSeparator getJSeparator3() {
		if (jSeparator3 == null) {
			jSeparator3 = new JSeparator();
		}
		return jSeparator3;
	}

	private JMenuItem getJMenuItemCCDControlReset() {
		if (jMenuItemCCDControlReset == null) {
			jMenuItemCCDControlReset = new JMenuItem();
			jMenuItemCCDControlReset.setText("Reset CCD");
			jMenuItemCCDControlReset.setEnabled(false);
			jMenuItemCCDControlReset.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					resetCameraAction(e);
				}
			});
		}
		return jMenuItemCCDControlReset;
	}

	private JSeparator getJSeparator4() {
		if (jSeparator4 == null) {
			jSeparator4 = new JSeparator();
		}
		return jSeparator4;
	}

	private JMenuItem getJMenuItemCCDControlStartExp() {
		if (jMenuItemCCDControlStartExp == null) {
			jMenuItemCCDControlStartExp = new JMenuItem();
			jMenuItemCCDControlStartExp.setText("Start Exposure");
			jMenuItemCCDControlStartExp.setEnabled(false);
			jMenuItemCCDControlStartExp.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					startExposureAction(e);
				}
			});
		}
		return jMenuItemCCDControlStartExp;
	}

	private JMenuItem getJMenuItemCCDControlStopExp() {
		if (jMenuItemCCDControlStopExp == null) {
			jMenuItemCCDControlStopExp = new JMenuItem();
			jMenuItemCCDControlStopExp.setText("Stop Exposure");
			jMenuItemCCDControlStopExp.setEnabled(false);
			jMenuItemCCDControlStopExp.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					stopExposureAction(e);
				}
			});
		}
		return jMenuItemCCDControlStopExp;
	}

	private JSeparator getJSeparator5() {
		if (jSeparator5 == null) {
			jSeparator5 = new JSeparator();
		}
		return jSeparator5;
	}

	private JMenuItem getJMenuItemCCDControlStartCooler() {
		if (jMenuItemCCDControlStartCooler == null) {
			jMenuItemCCDControlStartCooler = new JMenuItem();
			jMenuItemCCDControlStartCooler.setText("Start Cooler");
			jMenuItemCCDControlStartCooler.setEnabled(false);
			jMenuItemCCDControlStartCooler
					.addActionListener(new ActionListener() {
						@Override
						public void actionPerformed(ActionEvent e) {
							startCoolerAction(e);
						}
					});
		}
		return jMenuItemCCDControlStartCooler;
	}

	private JMenuItem getJMenuItemCCDControlStopCooler() {
		if (jMenuItemCCDControlStopCooler == null) {
			jMenuItemCCDControlStopCooler = new JMenuItem();
			jMenuItemCCDControlStopCooler.setText("Stop Cooler");
			jMenuItemCCDControlStopCooler.setEnabled(false);
			jMenuItemCCDControlStopCooler
					.addActionListener(new ActionListener() {
						@Override
						public void actionPerformed(ActionEvent e) {
							stopCoolerAction(e);
						}
					});
		}
		return jMenuItemCCDControlStopCooler;
	}

	private ButtonGroup getButtonGroupImageOptionsMenuImageSize() {
		if (buttonGroupImageOptionsMenuImageSize == null) {
			buttonGroupImageOptionsMenuImageSize = new ButtonGroup();
		}
		return buttonGroupImageOptionsMenuImageSize;
	}

	private JRadioButtonMenuItem getJRadioButtonMenuItemImageOptionsFitImage() {
		if (jRadioButtonMenuItemImageOptionsFitSize == null) {
			jRadioButtonMenuItemImageOptionsFitSize = new JRadioButtonMenuItem();
			jRadioButtonMenuItemImageOptionsFitSize
					.setText("Fit Image To Panel");
			getButtonGroupImageOptionsMenuImageSize().add(
					jRadioButtonMenuItemImageOptionsFitSize);
		}
		return jRadioButtonMenuItemImageOptionsFitSize;
	}

	private JRadioButtonMenuItem getJRadioButtonMenuItemImageOptionsNormalSize() {
		if (jRadioButtonMenuItemImageOptionsNormalSize == null) {
			jRadioButtonMenuItemImageOptionsNormalSize = new JRadioButtonMenuItem();
			jRadioButtonMenuItemImageOptionsNormalSize
					.setText("Original Image Size");
			getButtonGroupImageOptionsMenuImageSize().add(
					jRadioButtonMenuItemImageOptionsNormalSize);
		}
		return jRadioButtonMenuItemImageOptionsNormalSize;
	}

	private JSeparator getJSeparator6() {
		if (jSeparator6 == null) {
			jSeparator6 = new JSeparator();
		}
		return jSeparator6;
	}

	private JMenuItem getJMenuItemImageOptionsSaveAs() {
		if (jMenuItemImageOptionsSaveAs == null) {
			jMenuItemImageOptionsSaveAs = new JMenuItem();
			jMenuItemImageOptionsSaveAs.setText("Save Image As...");
		}
		return jMenuItemImageOptionsSaveAs;
	}

	private JSeparator getJSeparator7() {
		if (jSeparator7 == null) {
			jSeparator7 = new JSeparator();
		}
		return jSeparator7;
	}

	private JMenuItem getJMenuItemImageOptionsPrev() {
		if (jMenuItemImageOptionsPrev == null) {
			jMenuItemImageOptionsPrev = new JMenuItem();
			jMenuItemImageOptionsPrev.setText("Previous Image");
		}
		return jMenuItemImageOptionsPrev;
	}

	private JMenuItem getJMenuItemImageOptionsNext() {
		if (jMenuItemImageOptionsNext == null) {
			jMenuItemImageOptionsNext = new JMenuItem();
			jMenuItemImageOptionsNext.setText("Next Image");
		}
		return jMenuItemImageOptionsNext;
	}

	private JSeparator getJSeparator8() {
		if (jSeparator8 == null) {
			jSeparator8 = new JSeparator();
		}
		return jSeparator8;
	}

	private JMenuItem getJMenuItemHelpAbout() {
		if (jMenuItemHelpAbout == null) {
			jMenuItemHelpAbout = new JMenuItem();
			jMenuItemHelpAbout.setText("About gCCD...");
			jMenuItemHelpAbout.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent evt) {
					getJDialogAbout();
				}
			});
		}
		return jMenuItemHelpAbout;
	}

	private JPanel getJPanel1() {
		if (jPanel1 == null) {
			jPanel1 = new JPanel();
			GridBagLayout jPanel1Layout = new GridBagLayout();
			jPanel1.setPreferredSize(new java.awt.Dimension(200, 112));
			jPanel1Layout.rowWeights = new double[] { 0.1, 0.1, 0.1, 0.1 };
			jPanel1Layout.rowHeights = new int[] { 7, 7, 7, 7 };
			jPanel1Layout.columnWeights = new double[] { 0.1, 0.1 };
			jPanel1Layout.columnWidths = new int[] { 7, 7 };
			jPanel1.setLayout(jPanel1Layout);
			jPanel1.setBorder(BorderFactory
					.createBevelBorder(BevelBorder.LOWERED));
			jPanel1.add(getJLabelCCDInfoCameaSt(), new GridBagConstraints(1, 1,
					1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel1.add(getJLabelCCDInfoCameraState(), new GridBagConstraints(
					0, 1, 1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel1.add(getJLabelCCDInfoCoolerSt(), new GridBagConstraints(1,
					2, 1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel1.add(getJLabelCCDInfoCoolerState(), new GridBagConstraints(
					0, 2, 1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel1.add(getJLabelCCDInfoCurrT(), new GridBagConstraints(1, 3,
					1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel1.add(getJLabelCCDInfoCurrTemp(), new GridBagConstraints(0,
					3, 1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel1.add(getJLabelCCDInfo(), new GridBagConstraints(0, 0, 2, 1,
					0.0, 0.0, GridBagConstraints.CENTER,
					GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
		}
		return jPanel1;
	}

	private JPanel getJPanel2() {
		if (jPanel2 == null) {
			jPanel2 = new JPanel();
			GridBagLayout jPanel2Layout = new GridBagLayout();
			jPanel2.setPreferredSize(new java.awt.Dimension(99, 144));
			jPanel2Layout.rowWeights = new double[] { 0.1, 0.1, 0.1, 0.1, 0.1 };
			jPanel2Layout.rowHeights = new int[] { 7, 7, 7, 7, 7 };
			jPanel2Layout.columnWeights = new double[] { 0.1, 0.1 };
			jPanel2Layout.columnWidths = new int[] { 7, 7 };
			jPanel2.setLayout(jPanel2Layout);
			jPanel2.setBorder(BorderFactory
					.createBevelBorder(BevelBorder.LOWERED));
			jPanel2.add(getJLabelImageInfoFr(), new GridBagConstraints(1, 3, 1,
					1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel2.add(getJLabelImageInfoFrames(), new GridBagConstraints(0,
					3, 1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel2.add(getJLabelImageInfoFileSz(), new GridBagConstraints(1,
					4, 1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel2.add(getJLabelImageInfoFileSize(), new GridBagConstraints(0,
					4, 1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel2.add(getJLabelImageInfoH(), new GridBagConstraints(1, 2, 1,
					1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel2.add(getJLabelImageInfoHeight(), new GridBagConstraints(0,
					2, 1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel2.add(getJLabelImageInfoW(), new GridBagConstraints(1, 1, 1,
					1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel2.add(getJLabelImageInfoWidth(), new GridBagConstraints(0, 1,
					1, 1, 0.0, 0.0, GridBagConstraints.WEST,
					GridBagConstraints.NONE, new Insets(0, 10, 0, 0), 0, 0));
			jPanel2.add(getJLabelImageInfo(), new GridBagConstraints(0, 0, 2,
					1, 0.0, 0.0, GridBagConstraints.CENTER,
					GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
		}
		return jPanel2;
	}

	private JDialog getJDialogAbout() {
		if (jDialogAbout == null) {
			jDialogAbout = new JDialog(this);
			jDialogAbout.setTitle("About gCCD...");
			jDialogAbout.setMinimumSize(new java.awt.Dimension(300, 200));
			jDialogAbout.setMaximumSize(new java.awt.Dimension(300, 200));
			jDialogAbout.setSize(300, 200);
		}
		jDialogAbout.setModalityType(ModalityType.APPLICATION_MODAL);
		jDialogAbout.pack();
		jDialogAbout.setLocationRelativeTo(null);
		jDialogAbout.setVisible(true);
		return jDialogAbout;
	}

	private JDialog getJDialogError() {
		if (jDialogError == null) {
			jDialogError = new JDialog(this);
			jDialogError.setTitle("An error has ocurred...");
			jDialogError.setMinimumSize(new java.awt.Dimension(300, 200));
			jDialogError.setMaximumSize(new java.awt.Dimension(300, 200));
			jDialogError.setSize(300, 200);
		}
		jDialogError.setModalityType(ModalityType.APPLICATION_MODAL);
		jDialogError.pack();
		jDialogError.setLocationRelativeTo(null);
		jDialogError.setVisible(true);
		return jDialogError;
	}

	private JDialog getJDialogSelectCamera() {
		if (jDialogSelectCamera == null) {
			jDialogSelectCamera = new JDialog(this);
			jDialogSelectCamera.setTitle("Select camera model...");
			jDialogSelectCamera
					.setMinimumSize(new java.awt.Dimension(300, 200));
			jDialogSelectCamera
					.setMaximumSize(new java.awt.Dimension(300, 200));
			jDialogSelectCamera.setSize(300, 200);
		}
		jDialogSelectCamera.setModalityType(ModalityType.APPLICATION_MODAL);
		jDialogSelectCamera.pack();
		jDialogSelectCamera.setLocationRelativeTo(null);
		jDialogSelectCamera.setVisible(true);
		return jDialogSelectCamera;
	}

	private JDialog getJDialogCoolerTemp() {
		if (jDialogCoolerTemp == null) {
			jDialogCoolerTemp = new JDialog(this);
			jDialogCoolerTemp.setTitle("Set cooler temperature...");
			jDialogCoolerTemp.setMinimumSize(new java.awt.Dimension(300, 200));
			jDialogCoolerTemp.setMaximumSize(new java.awt.Dimension(300, 200));
			jDialogCoolerTemp.setSize(300, 200);
		}
		jDialogCoolerTemp.setModalityType(ModalityType.APPLICATION_MODAL);
		jDialogCoolerTemp.pack();
		jDialogCoolerTemp.setLocationRelativeTo(null);
		jDialogCoolerTemp.setVisible(true);
		return jDialogCoolerTemp;
	}

	private JDialog getJDialogExposureTime() {
		if (jDialogExposureTime == null) {
			jDialogExposureTime = new JDialog(this);
			jDialogExposureTime.setTitle("Set exposure time...");
			jDialogExposureTime
					.setMinimumSize(new java.awt.Dimension(300, 200));
			jDialogExposureTime
					.setMaximumSize(new java.awt.Dimension(300, 200));
			jDialogExposureTime.setSize(300, 200);
		}
		jDialogExposureTime.setModalityType(ModalityType.APPLICATION_MODAL);
		jDialogExposureTime.pack();
		jDialogExposureTime.setLocationRelativeTo(null);
		jDialogExposureTime.setVisible(true);
		return jDialogExposureTime;
	}

	private JDialog getJDialogAccumulations() {
		if (jDialogAccumulations == null) {
			jDialogAccumulations = new JDialog(this);
			jDialogAccumulations.setTitle("Set number of accumulations...");
			jDialogAccumulations
					.setMinimumSize(new java.awt.Dimension(300, 200));
			jDialogAccumulations
					.setMaximumSize(new java.awt.Dimension(300, 200));
			jDialogAccumulations.setSize(300, 200);
		}
		jDialogAccumulations.setModalityType(ModalityType.APPLICATION_MODAL);
		jDialogAccumulations.pack();
		jDialogAccumulations.setLocationRelativeTo(null);
		jDialogAccumulations.setVisible(true);
		return jDialogAccumulations;
	}

	private static class WindowCloseManager extends WindowAdapter {
		public void windowClosing(WindowEvent evt) {
			System.exit(0);
		}
	}

	/**
	 * Called by the controller when it needs to pass along a property change
	 * from a model.
	 * 
	 * @param evt
	 *            The property change event
	 */
	public void modelPropertyChange(PropertyChangeEvent evt) {

		if (evt.getPropertyName().equals(DefaultController.COMP_CURRENT_STATE)) {
			String newStringValue = evt.getNewValue().toString();

			if (!jLabelCCDInfoCameaSt.getText().equals(newStringValue))
				jLabelCCDInfoCameaSt.setText(newStringValue);
		}

		else if (evt.getPropertyName().equals(
				DefaultController.COMP_ORIGINAL_SIZE)) {
			boolean newBooleanValue = (Boolean) evt.getNewValue();

			if (!buttonGroupImageOptionsMenuImageSize
					.isSelected(jRadioButtonMenuItemImageOptionsNormalSize
							.getModel()) != newBooleanValue) {
				if (newBooleanValue) {
					buttonGroupImageOptionsMenuImageSize.setSelected(
							jRadioButtonMenuItemImageOptionsNormalSize
									.getModel(), newBooleanValue);
				}
			}
		}

		else if (evt.getPropertyName().equals(
				DefaultController.COMP_CAMERA_MODELS)) {
			String[] newStringValue = (String[]) evt.getNewValue();
			jComboBoxCCDModels
					.setModel(new DefaultComboBoxModel(newStringValue));
			getJMenuCCDSetupModels();
		}

		// revalidate();
		repaint();

	}

	private void exposureTimeSpinnerStateChanged(
			javax.swing.event.ChangeEvent evt) {

		controller.changeCompExposureTime((Double) jSpinnerCCDExpTime
				.getValue());

	}

	private void numberAccSpinnerStateChanged(javax.swing.event.ChangeEvent evt) {

		controller.changeCompNumberAcquisitions((Long) jSpinnerCCDNAcc
				.getValue());

		/*
		 * Document document = evt.getDocument();
		 * 
		 * try { controller.changeElementText(document.getText(0, document
		 * .getLength())); } catch (BadLocationException ex) { // Handle
		 * exception }
		 */

	}

	protected void connectAction(ActionEvent e) {
		try {
			controller.connectToCamera();
			this.setTitle("gCCD - [Connected to "
					+ jComboBoxCCDModels.getModel().getSelectedItem()
							.toString() + "]");
			jComboBoxCCDModels.setEnabled(false);

			jButtonCCDConnect.setEnabled(false);
			jButtonDisconnect.setEnabled(true);
			jTabbedPaneOptions.setEnabledAt(1, true);
			jTabbedPaneOptions.setEnabledAt(2, true);
			jTabbedPaneOptions.setEnabledAt(3, true);

			jMenuItemCCDSetupConnect.setEnabled(false);
			jMenuItemCCDSetupDisconnect.setEnabled(true);
			jMenuCCDSettings.setEnabled(true);
			jMenuCCDControl.setEnabled(true);
			jMenuImageOptions.setEnabled(true);
		} catch (Throwable e1) {
			getJDialogError();
			e1.printStackTrace();
		}
	}

	protected void disconnectAction(ActionEvent e) {
		try {
			this.setTitle("gCCD - [Disconnected]");
			controller.disconnectFromCamera();
			jComboBoxCCDModels.setEnabled(true);

			jButtonCCDConnect.setEnabled(true);
			jButtonDisconnect.setEnabled(false);
			jTabbedPaneOptions.setEnabledAt(1, false);
			jTabbedPaneOptions.setEnabledAt(2, false);
			jTabbedPaneOptions.setEnabledAt(3, false);

			jMenuItemCCDSetupConnect.setEnabled(true);
			jMenuItemCCDSetupDisconnect.setEnabled(false);
			jMenuCCDSettings.setEnabled(false);
			jMenuCCDControl.setEnabled(false);
			jMenuImageOptions.setEnabled(false);
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	protected void startCameraAction(ActionEvent e) {
		try {
			controller.startCamera();
			jButtonCCDOn.setEnabled(false);
			jButtonCCDOff.setEnabled(true);
			jButtonCCDStartExp.setEnabled(true);
			jButtonCCDStartCooler.setEnabled(true);

			jMenuItemCCDControlOn.setEnabled(false);
			jMenuItemCCDControlOff.setEnabled(true);
			jMenuItemCCDControlStartExp.setEnabled(true);
			jMenuItemCCDControlStartCooler.setEnabled(true);
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	protected void shutdownCameraAction(ActionEvent e) {
		try {
			controller.shutdownCamera();
			jButtonCCDOn.setEnabled(true);
			jButtonCCDOff.setEnabled(false);
			jButtonCCDStartExp.setEnabled(false);
			jButtonCCDStartCooler.setEnabled(false);

			jMenuItemCCDControlOn.setEnabled(true);
			jMenuItemCCDControlOff.setEnabled(false);
			jMenuItemCCDControlStartExp.setEnabled(false);
			jMenuItemCCDControlStartCooler.setEnabled(false);
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	protected void resetCameraAction(ActionEvent e) {
		try {
			controller.resetCamera();
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	protected void startExposureAction(ActionEvent e) {
		try {
			controller.startExposure();
			jButtonCCDStopExp.setEnabled(true);
			jButtonCCDStartExp.setEnabled(false);
			jButtonCCDReset.setEnabled(false);

			jMenuItemCCDControlStopExp.setEnabled(true);
			jMenuItemCCDControlStartExp.setEnabled(false);
			jMenuItemCCDControlReset.setEnabled(false);
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	protected void stopExposureAction(ActionEvent e) {
		try {
			controller.stopExposure();
			jButtonCCDStopExp.setEnabled(false);
			jButtonCCDStartExp.setEnabled(true);
			jButtonCCDReset.setEnabled(true);

			jMenuItemCCDControlStopExp.setEnabled(false);
			jMenuItemCCDControlStartExp.setEnabled(true);
			jMenuItemCCDControlReset.setEnabled(true);
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	protected void startCoolerAction(ActionEvent e) {
		try {
			controller.startCooler();
			jButtonCCDStartCooler.setEnabled(false);
			jButtonCCDStopCooler.setEnabled(true);

			jMenuItemCCDControlStartCooler.setEnabled(false);
			jMenuItemCCDControlStopCooler.setEnabled(true);
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	protected void stopCoolerAction(ActionEvent e) {
		try {
			controller.stopCooler();
			jButtonCCDStartCooler.setEnabled(true);
			jButtonCCDStopCooler.setEnabled(false);

			jMenuItemCCDControlStartCooler.setEnabled(true);
			jMenuItemCCDControlStopCooler.setEnabled(false);
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	protected void changeCCD(ActionEvent e) {
		controller.changeCompSelectedCamera(((JComboBox) e.getSource())
				.getSelectedIndex());
	}
}
