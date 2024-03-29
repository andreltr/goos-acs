package alma.ucn.oca.ccd.views;

import javax.swing.JOptionPane;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.beans.PropertyChangeEvent;
import java.io.File;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.LinkedList;
import javax.swing.JFileChooser;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import alma.ucn.oca.ccd.controller.DefaultController;
import alma.ucn.oca.ccd.utils.*;

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

	// The controller used by this view
	private DefaultController controller;

	private static final long serialVersionUID = 1L;

	private Timer updateGUIValues;
	private JMenuItem helpMenuItem;
	private JMenu jMenuHelp;
	private JPanel jPanelCCDSetup;
	private JPanel jPanelImageInfo;
	private JScrollPane jScrollPaneImage;
	private JPanel imageContainer;
	private JSplitPane jSplitPaneHorizontal;
	private JTabbedPane jTabbedPaneOptions;
	private JSplitPane jSplitPaneVertical;
	private JRadioButton jRadioButtonCCDScanTypeAcc;
	private JRadioButton jRadioButtonCCDScanTypeSingle;
	private ButtonGroup buttonGroupCCDSettingsMenuScanType;
	private JLabel jLabelCCDScanType;
	private JSpinner jSpinnerCCDNAcc;
	private JSpinner jSpinnerCCDNAccDialog;
	private JLabel jLabelCCDNAcc;
	private JSpinner jSpinnerCCDExpTime;
	private JSpinner jSpinnerCCDExpTimeDialog;
	private JLabel jLabelCCDExpTime;
	private JSpinner jSpinnerCCDTemp;
	private JSpinner jSpinnerCCDTempDialog;
	private JLabel jLabelCCDTemp;
	private JLabel jLabelCCDModels;
	private JButton jButtonCCDOn;
	private JMenuItem jMenuItemDeviceType;
	private JMenuItem jMenuItemIP;
	private JComboBox jComboBoxDeviceType;
	private JTextField jTextFieldIPAddress;
	private JTextField jTextFieldIPAddress2;
	private JLabel jLabelDeviceType;
	private JLabel jLabelIPAddress;
	private JSeparator jSeparator2;
	private JMenuItem jMenuItemExit;
	private JSeparator jSeparator1;
	private JMenuItem jMenuItemOpen;
	private JMenu jMenuFile;
	private JTextField jTextFieldImageInfoTabObserverName;
	private JTextField jTextFieldImageInfoTabTelescopeName;
	private JTextField jTextFieldImageInfoTabObjectName;
	private JLabel jLabelImageInfoTabTelescopeName;
	private JLabel jLabelImageInfoTabObserverName;
	private JLabel jLabelImageInfoTabObjectName;
	private JPanel jPanelTabImageInfo;
	private JFrame jFrameAboutDialog;
	private JFrame jFrameErrorDialog;
	private JFrame jFrameCoolerTempDialog;
	private JFrame jFrameExpTimeDialog;
	private JFrame jFrameAccDialog;
	private JFrame jFrameSetIP;
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
	private JMenuItem jMenuItemCCDControlStartExp;
	private JSeparator jSeparator4;
	private JMenuItem jMenuItemCCDControlReset;
	private JSeparator jSeparator3;
	private JMenuItem jMenuItemCCDControlOff;
	private JMenuItem jMenuItemCCDControlOn;
	private ButtonGroup buttonGroupCCDSettingsTabScanType;
	private JRadioButtonMenuItem jRadioButtonMenuItemCCDSettingsScanTypeAccumulative;
	private JRadioButtonMenuItem jRadioButtonMenuItemCCDSettingsScanTypeSingle;
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
	private JMenuBar jMenuBar;
	private LinkedList<String> listFiles;
	private int imgIndex = 0;
	private int imgMax;
	private JFileChooser jFileChooserDialogSave;
	private JFileChooser jFileChooserDialogOpen;
	private boolean coolerOn;
	private boolean ccdOn;
	private boolean acquiring;

	private JLabel jLabelReceptionMessage;
	private JLabel jLabelAcquiringMessage;

	private int currentReceivedFile;
	private int totalFiles;

	private JProgressBar jProgressBarReception;
	private String receptionDialogMessage;
	private JDialog jDialogReceptionProgress;
	private volatile Thread tReceptionDialog;

	private JProgressBar jProgressBarAcquiring;
	private String acquiringDialogMessage;
	private JDialog jDialogAcquiringProgress;
	private boolean receiving = false;

	private FITSFileDisplay imagePanel;
	private String currentDir = System.getProperty("user.dir") + "/";

	/**
	 * Auto-generated main method to display this JFrame
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
				this.setTitle("gCCD [Disconnected]");
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
									0.1, 0.1, 0.1, 0.1, 0.1, 0.1 };
							jPanelCCDSettingsLayout.columnWidths = new int[] {
									7, 7, 7, 7, 7, 7 };
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
								SpinnerNumberModel jSpinnerCCDTempModel = new SpinnerNumberModel(
										-20D, -55D, 45D, 0.1D);
								jSpinnerCCDTemp = new JSpinner();
								jSpinnerCCDTempDialog = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDTemp,
										new GridBagConstraints(1, 3, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jSpinnerCCDTemp.setModel(jSpinnerCCDTempModel);
								jSpinnerCCDTempDialog
										.setModel(jSpinnerCCDTempModel);
								jSpinnerCCDTemp
										.addChangeListener(new javax.swing.event.ChangeListener() {
											public void stateChanged(
													javax.swing.event.ChangeEvent evt) {
												coolerTempSpinnerStateChanged(evt);
											}
										});
								jSpinnerCCDTempDialog
										.addChangeListener(new javax.swing.event.ChangeListener() {
											public void stateChanged(
													javax.swing.event.ChangeEvent evt) {
												coolerTempSpinnerStateChanged(evt);
											}
										});
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
								SpinnerNumberModel jSpinnerCCDExpTimeModel = new SpinnerNumberModel(
										1D, 0D, 10D, 0.1D);
								jSpinnerCCDExpTime = new JSpinner();
								jSpinnerCCDExpTimeDialog = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDExpTime,
										new GridBagConstraints(1, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jSpinnerCCDExpTime
										.setModel(jSpinnerCCDExpTimeModel);
								jSpinnerCCDExpTimeDialog
										.setModel(jSpinnerCCDExpTimeModel);
								jSpinnerCCDExpTime
										.addChangeListener(new javax.swing.event.ChangeListener() {
											public void stateChanged(
													javax.swing.event.ChangeEvent evt) {
												exposureTimeSpinnerStateChanged(evt);
											}
										});
								jSpinnerCCDExpTimeDialog
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
								SpinnerNumberModel jSpinnerCCDNAccModel = new SpinnerNumberModel(
										new Long(1), new Long(0), new Long(20),
										new Long(1));
								jSpinnerCCDNAcc = new JSpinner();
								jSpinnerCCDNAccDialog = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDNAcc,
										new GridBagConstraints(1, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jSpinnerCCDNAcc.setModel(jSpinnerCCDNAccModel);
								jSpinnerCCDNAccDialog
										.setModel(jSpinnerCCDNAccModel);
								jSpinnerCCDNAcc
										.addChangeListener(new javax.swing.event.ChangeListener() {
											public void stateChanged(
													javax.swing.event.ChangeEvent evt) {
												numberAccSpinnerStateChanged(evt);
											}
										});
								jSpinnerCCDNAccDialog
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
								jPanelCCDSettings.add(getJLabelIPAddress(),
										new GridBagConstraints(4, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDSettings.add(getJLabelDeviceType(),
										new GridBagConstraints(4, 2, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDSettings.add(getJTextFieldIPAddress(),
										new GridBagConstraints(5, 1, 1, 1, 0.0,
												0.0, GridBagConstraints.CENTER,
												GridBagConstraints.NONE,
												new Insets(0, 0, 0, 0), 0, 0));
								jPanelCCDSettings.add(getJComboBoxDeviceType(),
										new GridBagConstraints(5, 2, 1, 1, 0.0,
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
							jTabbedPaneOptions.addTab("Image Information",
									null, getJPanelImageInfoTab(), null);

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
							jScrollPaneImage = new JScrollPane(
									ScrollPaneConstants.VERTICAL_SCROLLBAR_NEVER,
									ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
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
							jScrollPaneImage
									.addComponentListener(new ComponentListener() {
										@Override
										public void componentShown(
												ComponentEvent e) {
										}

										@Override
										public void componentResized(
												ComponentEvent e) {
											fitSizeImageAction(null);
										}

										@Override
										public void componentMoved(
												ComponentEvent e) {
										}

										@Override
										public void componentHidden(
												ComponentEvent e) {
										}
									});
						}
					}
				}
			}
			{
				jMenuBar = new JMenuBar();
				setJMenuBar(jMenuBar);
				{
					jMenuCCDSetup = new JMenu();
					jMenuBar.add(getJMenuFile());
					jMenuBar.add(jMenuCCDSetup);
					jMenuCCDSetup.setText("CCD Setup");
					jMenuCCDSetup.add(getJMenuCCDSetupModels());
					jMenuCCDSetup.add(getJSeparator2());
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
					jMenuCCDSettings.add(getJMenuItemDeviceType());
					jMenuCCDSettings.add(getJMenuItemIP());
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
					jMenuImageOptions.add(getJSeparator7());
					jMenuImageOptions.add(getJMenuItemImageOptionsPrev());
					jMenuImageOptions.add(getJMenuItemImageOptionsNext());
				}
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
		initValues();
	}

	private void initValues() {
		jButtonDisconnect.setEnabled(false);
		jTabbedPaneOptions.setEnabledAt(1, false);
		jTabbedPaneOptions.setEnabledAt(2, false);
		jTabbedPaneOptions.setEnabledAt(3, false);
		jTabbedPaneOptions.setEnabledAt(4, false);

		jMenuCCDSettings.setEnabled(false);
		jMenuCCDControl.setEnabled(false);
		jMenuImageOptions.setEnabled(false);

		getJButtonCCDStopExp();
	}

	// GUI components

	private JPanel getJPanelImageInfoTab() {
		if (jPanelTabImageInfo == null) {
			jPanelTabImageInfo = new JPanel();
			GridBagLayout jPanelTabImageInfoLayout = new GridBagLayout();
			jPanelTabImageInfoLayout.rowWeights = new double[] { 0.1, 0.1, 0.1,
					0.1, 0.1 };
			jPanelTabImageInfoLayout.rowHeights = new int[] { 7, 7, 7, 7, 7 };
			jPanelTabImageInfoLayout.columnWeights = new double[] { 0.1, 0.1,
					0.1 };
			jPanelTabImageInfoLayout.columnWidths = new int[] { 7, 7, 7 };
			jPanelTabImageInfo.setLayout(jPanelTabImageInfoLayout);
			jPanelTabImageInfo.add(getJLabelImageInfoTabObjectName(),
					new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER, GridBagConstraints.NONE,
							new Insets(0, 0, 0, 0), 0, 0));
			jPanelTabImageInfo.add(getJLabelImageInfoTabObserverName(),
					new GridBagConstraints(0, 3, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER, GridBagConstraints.NONE,
							new Insets(0, 0, 0, 0), 0, 0));
			jPanelTabImageInfo.add(getJLabelImageInfoTabTelescopeName(),
					new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER, GridBagConstraints.NONE,
							new Insets(0, 0, 0, 0), 0, 0));
			jPanelTabImageInfo.add(getJTextFieldImageInfoTabObjectName(),
					new GridBagConstraints(1, 1, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
			jPanelTabImageInfo.add(getJTextFieldImageInfoTabTelescopeName(),
					new GridBagConstraints(1, 2, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
			jPanelTabImageInfo.add(getJTextFieldImageInfoTabObserverName(),
					new GridBagConstraints(1, 3, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
		}
		return jPanelTabImageInfo;
	}

	private JLabel getJLabelImageInfoTabObjectName() {
		if (jLabelImageInfoTabObjectName == null) {
			jLabelImageInfoTabObjectName = new JLabel();
			jLabelImageInfoTabObjectName.setText("Object Name:");
		}
		return jLabelImageInfoTabObjectName;
	}

	private JLabel getJLabelImageInfoTabObserverName() {
		if (jLabelImageInfoTabObserverName == null) {
			jLabelImageInfoTabObserverName = new JLabel();
			jLabelImageInfoTabObserverName.setText("Observer Name:");
		}
		return jLabelImageInfoTabObserverName;
	}

	private JLabel getJLabelImageInfoTabTelescopeName() {
		if (jLabelImageInfoTabTelescopeName == null) {
			jLabelImageInfoTabTelescopeName = new JLabel();
			jLabelImageInfoTabTelescopeName.setText("Telescope Name:");
		}
		return jLabelImageInfoTabTelescopeName;
	}

	private JTextField getJTextFieldImageInfoTabObjectName() {
		if (jTextFieldImageInfoTabObjectName == null) {
			jTextFieldImageInfoTabObjectName = new JTextField();
			jTextFieldImageInfoTabObjectName
					.addFocusListener(new FocusListener() {
						@Override
						public void focusLost(FocusEvent e) {
							changeObjectNameActionPerformed();
						}

						@Override
						public void focusGained(FocusEvent e) {
						}
					});
		}
		return jTextFieldImageInfoTabObjectName;
	}

	private JTextField getJTextFieldImageInfoTabTelescopeName() {
		if (jTextFieldImageInfoTabTelescopeName == null) {
			jTextFieldImageInfoTabTelescopeName = new JTextField();
			jTextFieldImageInfoTabTelescopeName
					.addFocusListener(new FocusListener() {
						@Override
						public void focusLost(FocusEvent e) {
							changeTelescopeNameActionPerformed();
						}

						@Override
						public void focusGained(FocusEvent e) {
						}
					});
		}
		return jTextFieldImageInfoTabTelescopeName;
	}

	private JTextField getJTextFieldImageInfoTabObserverName() {
		if (jTextFieldImageInfoTabObserverName == null) {
			jTextFieldImageInfoTabObserverName = new JTextField();
			jTextFieldImageInfoTabObserverName
					.addFocusListener(new FocusListener() {
						@Override
						public void focusLost(FocusEvent e) {
							changeObserverNameActionPerformed();
						}

						@Override
						public void focusGained(FocusEvent e) {
						}
					});
		}
		return jTextFieldImageInfoTabObserverName;
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
			jRadioButtonCCDScanTypeSingle
					.addActionListener(new ActionListener() {
						public void actionPerformed(ActionEvent e) {
							acqModeTabStateChanged(e);
						}
					});
		}
		return jRadioButtonCCDScanTypeSingle;
	}

	private JRadioButton getJRadioButtonCCDScanTypeAcc() {
		if (jRadioButtonCCDScanTypeAcc == null) {
			jRadioButtonCCDScanTypeAcc = new JRadioButton();
			jRadioButtonCCDScanTypeAcc.setText("Accumulative");
			getButtonGroupCCDSettingsTabScanType().add(
					jRadioButtonCCDScanTypeAcc);
			jRadioButtonCCDScanTypeAcc.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					acqModeTabStateChanged(e);
				}
			});
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
			jButtonImageFitSize.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					fitSizeImageAction(e);
				}
			});
		}
		return jButtonImageFitSize;
	}

	private JButton getJButtonImageNormalSize() {
		if (jButtonImageNormalSize == null) {
			jButtonImageNormalSize = new JButton();
			jButtonImageNormalSize.setText("Original Image Size");
			jButtonImageNormalSize.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					originalSizeImageAction(e);
				}
			});
		}
		return jButtonImageNormalSize;
	}

	private JButton getJButtonImageSaveAs() {
		if (jButtonImageSaveAs == null) {
			jButtonImageSaveAs = new JButton();
			jButtonImageSaveAs.setText("Save Image As...");
			jButtonImageSaveAs.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					saveAsImageAction(e);
				}
			});
		}
		return jButtonImageSaveAs;
	}

	private JButton getJButtonImageNext() {
		if (jButtonImageNext == null) {
			jButtonImageNext = new JButton();
			jButtonImageNext.setText("Next Image");
			jButtonImageNext.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					nextImageAction(e);
				}
			});
		}
		return jButtonImageNext;
	}

	private JButton getJButtonImagePrev() {
		if (jButtonImagePrev == null) {
			jButtonImagePrev = new JButton();
			jButtonImagePrev.setText("Previous Image");
			jButtonImagePrev.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					previousImageAction(e);
				}
			});
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
			jLabelImageInfoWidth.setText("Width:");
		}
		return jLabelImageInfoWidth;
	}

	private JLabel getJLabelImageInfoW() {
		if (jLabelImageInfoW == null) {
			jLabelImageInfoW = new JLabel();
			jLabelImageInfoW.setText("---");
		}
		return jLabelImageInfoW;
	}

	private JLabel getJLabelImageInfoHeight() {
		if (jLabelImageInfoHeight == null) {
			jLabelImageInfoHeight = new JLabel();
			jLabelImageInfoHeight.setText("Height:");
		}
		return jLabelImageInfoHeight;
	}

	private JLabel getJLabelImageInfoH() {
		if (jLabelImageInfoH == null) {
			jLabelImageInfoH = new JLabel();
			jLabelImageInfoH.setText("---");
		}
		return jLabelImageInfoH;
	}

	private JLabel getJLabelImageInfoFileSize() {
		if (jLabelImageInfoFileSize == null) {
			jLabelImageInfoFileSize = new JLabel();
			jLabelImageInfoFileSize.setText("File Size:");
		}
		return jLabelImageInfoFileSize;
	}

	private JLabel getJLabelImageInfoFileSz() {
		if (jLabelImageInfoFileSz == null) {
			jLabelImageInfoFileSz = new JLabel();
			jLabelImageInfoFileSz.setText("---");
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
			jLabelImageInfoFr.setText("---");
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
			jLabelCCDInfoCurrTemp.setText("Temperature:");
		}
		return jLabelCCDInfoCurrTemp;
	}

	private JLabel getJLabelCCDInfoCurrT() {
		if (jLabelCCDInfoCurrT == null) {
			jLabelCCDInfoCurrT = new JLabel();
			jLabelCCDInfoCurrT.setText("---");
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
			jLabelCCDInfoCoolerSt.setText("---");
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
			jLabelCCDInfoCameaSt.setToolTipText("On/Off/Acquiring");
		}
		return jLabelCCDInfoCameaSt;
	}

	private JMenu getJMenuFile() {
		if (jMenuFile == null) {
			jMenuFile = new JMenu();
			jMenuFile.setText("File");
			jMenuFile.setBounds(331, 0, 35, 23);
			jMenuFile.add(getJMenuItemOpen());
			jMenuFile.add(getJSeparator6());
			jMenuFile.add(getJMenuItemImageOptionsSaveAs());
			jMenuFile.add(getJSeparator1());
			jMenuFile.add(getJMenuItemExit());
		}
		return jMenuFile;
	}

	private JMenuItem getJMenuItemOpen() {
		if (jMenuItemOpen == null) {
			jMenuItemOpen = new JMenuItem();
			jMenuItemOpen.setText("Open FITS file...");
			jMenuItemOpen.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					openImageAction(e);
				}
			});
		}
		return jMenuItemOpen;
	}

	private JSeparator getJSeparator1() {
		if (jSeparator1 == null) {
			jSeparator1 = new JSeparator();
			jSeparator1.setBounds(116, 21, 70, 7);
		}
		return jSeparator1;
	}

	private JMenuItem getJMenuItemExit() {
		if (jMenuItemExit == null) {
			jMenuItemExit = new JMenuItem();
			jMenuItemExit.setText("Exit");
			jMenuItemExit.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					System.exit(0);
				}
			});
		}
		return jMenuItemExit;
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
			jMenuItemCCDSettingsCoolerTemp
					.addActionListener(new ActionListener() {
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
		if (jRadioButtonMenuItemCCDSettingsScanTypeSingle == null) {
			jRadioButtonMenuItemCCDSettingsScanTypeSingle = new JRadioButtonMenuItem();
			jRadioButtonMenuItemCCDSettingsScanTypeSingle
					.setText("Single Scan");
			getButtonGroupCCDSettingsMenuScanType().add(
					jRadioButtonMenuItemCCDSettingsScanTypeSingle);
			jRadioButtonMenuItemCCDSettingsScanTypeSingle
					.addActionListener(new ActionListener() {
						public void actionPerformed(ActionEvent e) {
							acqModeMenuStateChanged(e);
						}
					});
		}
		return jRadioButtonMenuItemCCDSettingsScanTypeSingle;
	}

	private JRadioButtonMenuItem getJRadioButtonCCDSettingsScanTypeAccumulated() {
		if (jRadioButtonMenuItemCCDSettingsScanTypeAccumulative == null) {
			jRadioButtonMenuItemCCDSettingsScanTypeAccumulative = new JRadioButtonMenuItem();
			jRadioButtonMenuItemCCDSettingsScanTypeAccumulative
					.setText("Accumulative");
			getButtonGroupCCDSettingsMenuScanType().add(
					jRadioButtonMenuItemCCDSettingsScanTypeAccumulative);
			jRadioButtonMenuItemCCDSettingsScanTypeAccumulative
					.addActionListener(new ActionListener() {
						public void actionPerformed(ActionEvent e) {
							acqModeMenuStateChanged(e);
						}
					});
		}
		return jRadioButtonMenuItemCCDSettingsScanTypeAccumulative;
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
			jRadioButtonMenuItemImageOptionsFitSize
					.addActionListener(new ActionListener() {
						@Override
						public void actionPerformed(ActionEvent e) {
							fitSizeImageAction(e);
						}
					});
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
			jRadioButtonMenuItemImageOptionsNormalSize
					.addActionListener(new ActionListener() {
						@Override
						public void actionPerformed(ActionEvent e) {
							originalSizeImageAction(e);
						}
					});
		}
		return jRadioButtonMenuItemImageOptionsNormalSize;
	}

	private JSeparator getJSeparator6() {
		if (jSeparator6 == null) {
			jSeparator6 = new JSeparator();
			jSeparator6.setBounds(248, 67, 149, 7);
		}
		return jSeparator6;
	}

	private JMenuItem getJMenuItemImageOptionsSaveAs() {
		if (jMenuItemImageOptionsSaveAs == null) {
			jMenuItemImageOptionsSaveAs = new JMenuItem();
			jMenuItemImageOptionsSaveAs.setText("Save Image As...");
			jMenuItemImageOptionsSaveAs.setBounds(248, 74, 149, 23);
			jMenuItemImageOptionsSaveAs.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					saveAsImageAction(e);
				}
			});
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
			jMenuItemImageOptionsPrev.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					previousImageAction(e);
				}
			});
		}
		return jMenuItemImageOptionsPrev;
	}

	private JMenuItem getJMenuItemImageOptionsNext() {
		if (jMenuItemImageOptionsNext == null) {
			jMenuItemImageOptionsNext = new JMenuItem();
			jMenuItemImageOptionsNext.setText("Next Image");
			jMenuItemImageOptionsNext.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					nextImageAction(e);
				}
			});
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

	// Dialogs

	private void getJDialogAbout() {
		if (jFrameAboutDialog == null) {
			jFrameAboutDialog = new JFrame();
		}
		JOptionPane.showMessageDialog(jFrameAboutDialog, "gCCD 2009 - 2010",
				"About...", JOptionPane.INFORMATION_MESSAGE);
	}

	private void getJDialogError(String err) {
		if (jFrameErrorDialog == null) {
			jFrameErrorDialog = new JFrame();
		}
		JOptionPane.showMessageDialog(jFrameErrorDialog, "Error: " + err,
				"An error has occured...", JOptionPane.ERROR_MESSAGE);
	}

	private void getJDialogSelectDeviceType() {
		int size = jComboBoxDeviceType.getModel().getSize();
		Object[] deviceTypes = new Object[size];
		for (int i = 0; i < size; i++) {
			deviceTypes[i] = jComboBoxDeviceType.getModel().getElementAt(i);
		}

		String s = (String) JOptionPane.showInputDialog(jFrameErrorDialog,
				"Select the device type:\n", "Select device type...",
				JOptionPane.PLAIN_MESSAGE, null, deviceTypes, null);

		if ((s != null) && (s.length() > 0)) {
			for (int i = 0; i < size; i++) {
				if (s.equals(jComboBoxDeviceType.getModel().getElementAt(i))) {
					jComboBoxDeviceType.setSelectedIndex(i);
					break;
				}
			}
		}
	}

	private void getJDialogSetIP() {
		Object[] message = { "Set the camera IP address: ",
				getJTextFieldIPAddress2() };
		JOptionPane.showMessageDialog(jFrameCoolerTempDialog, message,
				"Set camera IP...", JOptionPane.OK_CANCEL_OPTION);
	}

	private void getJDialogSelectCamera() {
		int size = jComboBoxCCDModels.getModel().getSize();
		Object[] cameraModels = new Object[size];
		for (int i = 0; i < size; i++) {
			cameraModels[i] = jComboBoxCCDModels.getModel().getElementAt(i);
		}

		String s = (String) JOptionPane.showInputDialog(jFrameErrorDialog,
				"Select the camera model:\n", "Select camera model...",
				JOptionPane.PLAIN_MESSAGE, null, cameraModels, null);

		if ((s != null) && (s.length() > 0)) {
			for (int i = 0; i < size; i++) {
				if (s.equals(jComboBoxCCDModels.getModel().getElementAt(i))) {
					jComboBoxCCDModels.setSelectedIndex(i);
					break;
				}
			}
		}
	}

	private void getJDialogCoolerTemp() {
		if (jFrameCoolerTempDialog == null) {
			jFrameCoolerTempDialog = new JFrame();
		}
		Object[] message = { "Set temperature (ºC): ", jSpinnerCCDTempDialog };
		JOptionPane.showMessageDialog(jFrameCoolerTempDialog, message,
				"Set cooler temperature...", JOptionPane.OK_CANCEL_OPTION);
	}

	private void getJDialogExposureTime() {
		if (jFrameExpTimeDialog == null) {
			jFrameExpTimeDialog = new JFrame();
		}
		Object[] message = { "Set exposure time: ", jSpinnerCCDExpTimeDialog };
		JOptionPane.showMessageDialog(jFrameExpTimeDialog, message,
				"Set exposure time...", JOptionPane.OK_CANCEL_OPTION);
	}

	private void getJDialogAccumulations() {
		if (jFrameAccDialog == null) {
			jFrameAccDialog = new JFrame();
		}
		Object[] message = { "Set number of accumulations: ",
				jSpinnerCCDNAccDialog };
		JOptionPane.showMessageDialog(jFrameAccDialog, message,
				"Set number of accumulations...", JOptionPane.OK_CANCEL_OPTION);
	}

	private void getJDialogAcquiring() {
		if (jLabelAcquiringMessage == null) {
			jProgressBarAcquiring = new JProgressBar();
			jProgressBarAcquiring.setIndeterminate(true);
			jLabelAcquiringMessage = new JLabel();
		}

		acquiringDialogMessage = "Taking image...";
		jLabelAcquiringMessage.setText(acquiringDialogMessage);

		jDialogAcquiringProgress = new JDialog(this, "Acquiring...", true);
		jDialogAcquiringProgress
				.add(BorderLayout.SOUTH, getJButtonCCDStopExp());
		jDialogAcquiringProgress
				.add(BorderLayout.CENTER, jProgressBarAcquiring);
		jDialogAcquiringProgress
				.add(BorderLayout.NORTH, jLabelAcquiringMessage);
		jDialogAcquiringProgress.setSize(300, 100);
		jDialogAcquiringProgress.setLocationRelativeTo(this);
		jDialogAcquiringProgress.addWindowListener(new WindowListener() {
			@Override
			public void windowActivated(WindowEvent e) {
			}

			@Override
			public void windowClosed(WindowEvent e) {
			}

			@Override
			public void windowClosing(WindowEvent e) {
				stopExposureAction(null);
			}

			@Override
			public void windowDeactivated(WindowEvent e) {
			}

			@Override
			public void windowDeiconified(WindowEvent e) {
			}

			@Override
			public void windowIconified(WindowEvent e) {
			}

			@Override
			public void windowOpened(WindowEvent e) {
			}
		});
	}

	private void getJDialogReception() {
		if (jLabelReceptionMessage == null) {
			jProgressBarReception = new JProgressBar(0, 999);
			jLabelReceptionMessage = new JLabel();
		}

		receptionDialogMessage = "Receiving...";
		jLabelReceptionMessage.setText(receptionDialogMessage);

		jDialogReceptionProgress = new JDialog(this, "Receiving...", true);
		jDialogReceptionProgress
				.add(BorderLayout.CENTER, jProgressBarReception);
		jDialogReceptionProgress
				.add(BorderLayout.NORTH, jLabelReceptionMessage);
		jDialogReceptionProgress.setSize(300, 100);
		jDialogReceptionProgress.setLocationRelativeTo(this);
	}

	private JFileChooser getJDialogFilechooser() {
		if (jFileChooserDialogSave == null) {
			// File selector dialog
			jFileChooserDialogSave = new JFileChooser(System
					.getProperty("user.dir"));
			jFileChooserDialogSave
					.addChoosableFileFilter(new gCCDFileSelectorDialog());
		}
		return jFileChooserDialogSave;
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
	@SuppressWarnings("unchecked")
	public void modelPropertyChange(PropertyChangeEvent evt) {

		if (evt.getPropertyName().equals(DefaultController.COMP_CURRENT_STATE)) {
			Integer newIntegerValue = (Integer) evt.getNewValue();

			if (!jLabelCCDInfoCameaSt.getText().equals(newIntegerValue)) {
				switch (newIntegerValue) {
				case 0:
					jLabelCCDInfoCameaSt.setText("Off");
					jLabelCCDInfoCameaSt.setText("Off");

					ccdOn = false;
					coolerOn = false;
					acquiring = false;
					break;
				case 1:
					jLabelCCDInfoCameaSt.setText("On");
					jLabelCCDInfoCoolerSt.setText("Off");
					ccdOn = true;
					coolerOn = false;
					acquiring = false;
					break;
				case 2:
					jLabelCCDInfoCameaSt.setText("Acquiring");
					acquiring = true;
					break;
				case 3:
					jLabelCCDInfoCameaSt.setText("On");
					jLabelCCDInfoCoolerSt.setText("On");
					ccdOn = true;
					coolerOn = true;
					acquiring = false;
					break;
				}
			}
		}

		else if (evt.getPropertyName().equals(
				DefaultController.COMP_CAMERA_MODELS)) {
			String[] newStringValue = (String[]) evt.getNewValue();
			jComboBoxCCDModels
					.setModel(new DefaultComboBoxModel(newStringValue));
		}

		else if (evt.getPropertyName()
				.equals(DefaultController.COMP_LIST_FILES)) {
			LinkedList<String> newStringValue = (LinkedList<String>) evt
					.getNewValue();
			listFiles = newStringValue;
			imgMax = listFiles.size();

		} else if (evt.getPropertyName().equals(
				DefaultController.COMP_FILE_RECEIVED)) {
			System.out.println("Notificacion");
			gCCDNCEvent newNotification = (gCCDNCEvent) evt.getNewValue();

			jDialogAcquiringProgress.setVisible(false);
			receiving = true;

			currentReceivedFile = (int) newNotification.getID();
			totalFiles = (int) newNotification.getTotal();

			receptionDialogMessage = "Receiving image " + currentReceivedFile
					+ " of " + totalFiles;
			jLabelReceptionMessage.setText(receptionDialogMessage);

			jProgressBarReception.setValue(currentReceivedFile);
			jProgressBarReception.setMaximum(totalFiles);

		} else if (evt.getPropertyName().equals(
				DefaultController.COMP_END_SUBSCRIPTION)) {
			jButtonCCDStopExp.setEnabled(false);
			jButtonCCDStartExp.setEnabled(true);
			jButtonCCDReset.setEnabled(true);
			jButtonCCDOff.setEnabled(true);
			//
			jButtonCCDStartCooler.setEnabled(!coolerOn);
			jButtonCCDStopCooler.setEnabled(coolerOn);

			jMenuItemCCDControlStartExp.setEnabled(true);
			jMenuItemCCDControlReset.setEnabled(true);
			jMenuItemCCDControlOff.setEnabled(true);
			//
			jMenuItemCCDControlStartCooler.setEnabled(!coolerOn);
			jMenuItemCCDControlStopCooler.setEnabled(coolerOn);

			tReceptionDialog.interrupt();
			tReceptionDialog = null;
			jDialogReceptionProgress.setVisible(false);
			jDialogAcquiringProgress.setVisible(false);
			receiving = false;
			showImageAction(null, 0);
		}

		else if (evt.getPropertyName().equals(
				DefaultController.COMP_EXPOSURE_TIME)) {
			Double newDoubleValue = (Double) evt.getNewValue();
			jSpinnerCCDExpTime.setValue(newDoubleValue);
		}

		else if (evt.getPropertyName()
				.equals(DefaultController.COMP_NUMBER_ACQ)) {
			Long newLongValue = (Long) evt.getNewValue();
			jSpinnerCCDNAcc.setValue(newLongValue);
		}

		else if (evt.getPropertyName().equals(DefaultController.COMP_ACQ_MODE)) {
			Long newLongValue = (Long) evt.getNewValue();

			switch (newLongValue.intValue()) {
			case 0:
				buttonGroupCCDSettingsTabScanType.setSelected(
						jRadioButtonCCDScanTypeSingle.getModel(), true);
				buttonGroupCCDSettingsMenuScanType.setSelected(
						jRadioButtonMenuItemCCDSettingsScanTypeSingle
								.getModel(), true);
				break;
			case 1:
				buttonGroupCCDSettingsTabScanType.setSelected(
						jRadioButtonCCDScanTypeAcc.getModel(), true);
				buttonGroupCCDSettingsMenuScanType.setSelected(
						jRadioButtonMenuItemCCDSettingsScanTypeAccumulative
								.getModel(), true);
				break;
			}
		}

		else if (evt.getPropertyName().equals(
				DefaultController.COMP_COMMANDED_CCD_TEMP)) {
			Double newDoubleValue = (Double) evt.getNewValue();
			jSpinnerCCDTemp.setValue(newDoubleValue);
		}

		else if (evt.getPropertyName().equals(
				DefaultController.COMP_ACTUAL_CCD_TEMP)) {
			Double newDoubleValue = (Double) evt.getNewValue();
			if (newDoubleValue != -9999.9) {
				BigDecimal bd = new BigDecimal(newDoubleValue.toString());
				bd = bd.setScale(4, BigDecimal.ROUND_HALF_UP);
				jLabelCCDInfoCurrT.setText(bd + " ºC");
			}
		}

		repaint();
	}

	// Methods that change the model

	private void changeIPActionPerformed() {

		controller.changeIP(jTextFieldIPAddress.getText());

	}

	private void changeDeviceTypeActionPerformed() {

		controller.changeDeviceType(jComboBoxDeviceType.getSelectedIndex() + 1);

	}

	private void changeObserverNameActionPerformed() {

		controller.changeCompObserverName(jTextFieldImageInfoTabObserverName
				.getText());

	}

	private void changeObjectNameActionPerformed() {

		controller.changeCompObjectName(jTextFieldImageInfoTabObjectName
				.getText());

	}

	private void changeTelescopeNameActionPerformed() {

		controller.changeCompTelescopeName(jTextFieldImageInfoTabTelescopeName
				.getText());

	}

	private void exposureTimeSpinnerStateChanged(
			javax.swing.event.ChangeEvent evt) {

		controller.changeCompExposureTime((Double) jSpinnerCCDExpTime
				.getValue());

	}

	private void coolerTempSpinnerStateChanged(javax.swing.event.ChangeEvent evt) {

		controller.changeCompCCDTemp((Double) jSpinnerCCDTemp.getValue());

	}

	private void numberAccSpinnerStateChanged(javax.swing.event.ChangeEvent evt) {

		controller.changeCompNumberAcquisitions((Long) jSpinnerCCDNAcc
				.getValue());

	}

	private void acqModeTabStateChanged(ActionEvent e) {
		int acqMode = 0;
		if (jRadioButtonCCDScanTypeSingle.isSelected()) {
			acqMode = 0;
		} else if (jRadioButtonCCDScanTypeAcc.isSelected()) {
			acqMode = 1;
		}

		controller.changeCompAcquisitionMode(new Long((long) acqMode));
	}

	private void acqModeMenuStateChanged(ActionEvent e) {
		int acqMode = 0;
		if (jRadioButtonMenuItemCCDSettingsScanTypeSingle.isSelected()) {
			acqMode = 0;
		} else if (jRadioButtonMenuItemCCDSettingsScanTypeAccumulative
				.isSelected()) {
			acqMode = 1;
		}

		controller.changeCompAcquisitionMode(new Long((long) acqMode));
	}

	// GUI events

	protected void connectAction(ActionEvent e) {
		try {
			controller.connectToCamera();
			this.setTitle("gCCD [Connected to "
					+ jComboBoxCCDModels.getModel().getSelectedItem()
							.toString() + "]");
			jComboBoxCCDModels.setEnabled(false);
			jMenuItemCCDSetupModels.setEnabled(false);

			jButtonCCDConnect.setEnabled(false);
			jButtonDisconnect.setEnabled(true);
			jTabbedPaneOptions.setEnabledAt(1, true);
			jTabbedPaneOptions.setEnabledAt(2, true);
			jTabbedPaneOptions.setEnabledAt(3, true);
			jTabbedPaneOptions.setEnabledAt(4, true);

			jMenuItemCCDSetupConnect.setEnabled(false);
			jMenuItemCCDSetupDisconnect.setEnabled(true);
			jMenuCCDSettings.setEnabled(true);
			jMenuCCDControl.setEnabled(true);
			jMenuImageOptions.setEnabled(true);
		} catch (Throwable e1) {
			getJDialogError(e1.getCause().toString());
			e1.printStackTrace();
		}
	}

	protected void disconnectAction(ActionEvent e) {

		if (acquiring) {
			stopExposureAction(e);
		}

		if (ccdOn) {
			shutdownCameraAction(e);
		}

		try {
			this.setTitle("gCCD [Disconnected]");
			controller.disconnectFromCamera();
			jComboBoxCCDModels.setEnabled(true);
			jMenuItemCCDSetupModels.setEnabled(true);

			jButtonCCDConnect.setEnabled(true);
			jButtonDisconnect.setEnabled(false);
			jTabbedPaneOptions.setEnabledAt(1, false);
			jTabbedPaneOptions.setEnabledAt(2, false);
			jTabbedPaneOptions.setEnabledAt(3, false);
			jTabbedPaneOptions.setEnabledAt(4, false);
			jTabbedPaneOptions.setSelectedIndex(0);

			jMenuItemCCDSetupConnect.setEnabled(true);
			jMenuItemCCDSetupDisconnect.setEnabled(false);
			jMenuCCDSettings.setEnabled(false);
			jMenuCCDControl.setEnabled(false);
			jMenuImageOptions.setEnabled(false);
		} catch (Exception e1) {
			getJDialogError(e1.getCause().toString());
			e1.printStackTrace();
		}
	}

	protected void startCameraAction(ActionEvent e) {
		try {
			controller.startCamera();

			if (updateGUIValues == null) {
				updateGUIValues = new Timer(1500, new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						try {
							controller.getCCDValues();
						} catch (Exception e1) {
							e1.printStackTrace();
						}
					}
				});
			}

			updateGUIValues.start();

			jButtonCCDOn.setEnabled(false);
			jButtonCCDOff.setEnabled(true);
			jButtonCCDReset.setEnabled(true);
			jButtonCCDStartExp.setEnabled(true);
			jButtonCCDStartCooler.setEnabled(true);

			jComboBoxDeviceType.setEnabled(false);
			jTextFieldIPAddress.setEnabled(false);

			jMenuItemCCDControlOn.setEnabled(false);
			jMenuItemCCDControlOff.setEnabled(true);
			jMenuItemCCDControlReset.setEnabled(true);
			jMenuItemCCDControlStartExp.setEnabled(true);
			jMenuItemCCDControlStartCooler.setEnabled(true);
		} catch (Exception e1) {
			getJDialogError(e1.getCause().toString());
			e1.printStackTrace();
		}
	}

	protected void shutdownCameraAction(ActionEvent e) {

		if (coolerOn) {
			stopCoolerAction(e);
		}

		try {
			controller.shutdownCamera();

			updateGUIValues.stop();

			jButtonCCDOn.setEnabled(true);
			jButtonCCDOff.setEnabled(false);
			jButtonCCDReset.setEnabled(false);
			jButtonCCDStartExp.setEnabled(false);
			jButtonCCDStartCooler.setEnabled(false);

			jComboBoxDeviceType.setEnabled(true);
			jTextFieldIPAddress.setEnabled(true);

			jMenuItemCCDControlOn.setEnabled(true);
			jMenuItemCCDControlOff.setEnabled(false);
			jMenuItemCCDControlReset.setEnabled(false);
			jMenuItemCCDControlStartExp.setEnabled(false);
			jMenuItemCCDControlStartCooler.setEnabled(false);
		} catch (Exception e1) {
			getJDialogError(e1.getCause().toString());
			e1.printStackTrace();
		}
	}

	protected void resetCameraAction(ActionEvent e) {
		try {
			controller.resetCamera();
		} catch (Exception e1) {
			getJDialogError(e1.getCause().toString());
			e1.printStackTrace();
		}
	}

	protected void startExposureAction(ActionEvent e) {
		try {
			getJDialogAcquiring();
			getJDialogReception();

			tReceptionDialog = new Thread(new Runnable() {

				public void run() {
					Thread thisThread = Thread.currentThread();
					while (tReceptionDialog == thisThread) {
						if (!receiving) {
							jDialogAcquiringProgress.setVisible(true);
						} else {
							jDialogReceptionProgress.setVisible(true);
						}
					}
					jDialogAcquiringProgress.setVisible(false);
					jDialogReceptionProgress.setVisible(false);
				}
			});

			tReceptionDialog.start();

			controller.startExposure();

			jButtonCCDStopExp.setEnabled(true);
			jButtonCCDStartExp.setEnabled(false);
			jButtonCCDReset.setEnabled(false);
			jButtonCCDOff.setEnabled(false);
			jButtonCCDStartCooler.setEnabled(false);
			jButtonCCDStopCooler.setEnabled(false);

			jMenuItemCCDControlStartExp.setEnabled(false);
			jMenuItemCCDControlReset.setEnabled(false);
			jMenuItemCCDControlOff.setEnabled(false);
			jMenuItemCCDControlStartCooler.setEnabled(false);
			jMenuItemCCDControlStopCooler.setEnabled(false);

		} catch (Exception e1) {
			disconnectAction(null);
			getJDialogError(e1.getCause().toString());
			e1.printStackTrace();
		}
	}

	protected void stopExposureAction(ActionEvent e) {
		try {
			tReceptionDialog.interrupt();
			tReceptionDialog = null;
			jDialogReceptionProgress.setVisible(false);
			jDialogAcquiringProgress.setVisible(false);
			receiving = false;

			controller.stopExposure();

			jButtonCCDStopExp.setEnabled(false);
			jButtonCCDStartExp.setEnabled(true);
			jButtonCCDReset.setEnabled(true);
			jButtonCCDOff.setEnabled(true);

			jButtonCCDStartCooler.setEnabled(!coolerOn);
			jButtonCCDStopCooler.setEnabled(coolerOn);

			jMenuItemCCDControlStartExp.setEnabled(true);
			jMenuItemCCDControlReset.setEnabled(true);
			jMenuItemCCDControlOff.setEnabled(true);

			jMenuItemCCDControlStartCooler.setEnabled(!coolerOn);
			jMenuItemCCDControlStopCooler.setEnabled(coolerOn);
		} catch (Exception e1) {
			getJDialogError(e1.getCause().toString());
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
			getJDialogError(e1.getCause().toString());
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
			getJDialogError(e1.getCause().toString());
			e1.printStackTrace();
		}
	}

	protected void changeCCD(ActionEvent e) {
		controller.changeCompSelectedCamera(((JComboBox) e.getSource())
				.getSelectedIndex());
	}

	protected void fitSizeImageAction(ActionEvent e) {
		if (imagePanel != null) {
			Dimension fitSize = new Dimension(jScrollPaneImage.getWidth() - 3,
					jScrollPaneImage.getHeight() - 3);

			imageContainer.setPreferredSize(fitSize);
			imagePanel.setPreferredSize(fitSize);
			imagePanel.setSize(fitSize);

			jScrollPaneImage.validate();
		}
		jRadioButtonMenuItemImageOptionsFitSize.setSelected(true);
	}

	protected void originalSizeImageAction(ActionEvent e) {
		if (imagePanel != null) {
			// Dimension originalSize = imagePanel.getWidthHeight();
			Dimension originalSize = imagePanel.getSize();

			imagePanel.setPreferredSize(originalSize);
			imagePanel.setSize(originalSize);
			imageContainer.setPreferredSize(originalSize);

			jScrollPaneImage.validate();
		}
		jRadioButtonMenuItemImageOptionsNormalSize.setSelected(true);
	}

	protected void nextImageAction(ActionEvent e) {
		if (imgIndex < imgMax - 1) {
			imgIndex++;
			showImageAction(e, imgIndex);
		} else {
			imgIndex = 0;
			showImageAction(e, imgIndex);
		}
	}

	protected void previousImageAction(ActionEvent e) {
		if (imgIndex > 0) {
			imgIndex--;
			showImageAction(e, imgIndex);
		} else {
			imgIndex = imgMax - 1;
			showImageAction(e, imgIndex);
		}
	}

	protected void showImageAction(ActionEvent e, int imgIndex) {
		if (imagePanel == null) {
			imagePanel = new FITSFileDisplay();
			imagePanel.addChangeListener(new ChangeListener() {
				@Override
				public void stateChanged(ChangeEvent e) {
					if (imagePanel.getSelectedIndex() >= 0) {
						imagePanel.setCurrentHDU(imagePanel.getSelectedIndex());
						setImageInfo();
					}
				}
			});
			imageContainer = new JPanel(new GridBagLayout());
			imageContainer.add(imagePanel);
			jScrollPaneImage.setViewportView(imageContainer);
		}
		try {
			if (listFiles != null) {
				this.setTitle("gCCD [Connected to "
						+ jComboBoxCCDModels.getModel().getSelectedItem()
								.toString() + "] - " + currentDir
						+ listFiles.get(imgIndex));
				imagePanel.load(currentDir + listFiles.get(imgIndex));
				setImageInfo();
				fitSizeImageAction(null);
			}
		} catch (IOException e1) {
			e1.printStackTrace();
		}
	}

	protected void openImageAction(ActionEvent e) {
		if (imagePanel == null) {
			imagePanel = new FITSFileDisplay();
			imagePanel.addChangeListener(new ChangeListener() {
				@Override
				public void stateChanged(ChangeEvent e) {
					if (imagePanel.getSelectedIndex() >= 0) {
						imagePanel.setCurrentHDU(imagePanel.getSelectedIndex());
						setImageInfo();
					}
				}
			});
			imageContainer = new JPanel(new GridBagLayout());
			imageContainer.add(imagePanel);
			jScrollPaneImage.setViewportView(imageContainer);
		}
		if (jFileChooserDialogOpen == null) {
			jFileChooserDialogOpen = new JFileChooser(currentDir);
		}
		if (jFileChooserDialogOpen.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
			try {
				imagePanel.load(jFileChooserDialogOpen.getSelectedFile());
				this.setTitle("gCCD [Local Image] - "
						+ jFileChooserDialogOpen.getSelectedFile());
				imagePanel.load(jFileChooserDialogOpen.getSelectedFile());
				setImageInfo();
				fitSizeImageAction(null);
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}
	}

	protected void saveAsImageAction(ActionEvent e) {
		int result = getJDialogFilechooser().showSaveDialog(this);
		File fileObj = jFileChooserDialogSave.getSelectedFile();
		// We get the path to save the image
		if (result == JFileChooser.APPROVE_OPTION) {
			try {
				// We append the .fits extension if it's not found
				if (jFileChooserDialogSave.getFileFilter().accept(fileObj) == true) {
					saveImage(fileObj.getAbsolutePath());
				} else {
					saveImage(fileObj.getAbsolutePath() + ".fits");
				}

			} catch (Exception ex) {
				ex.printStackTrace();
			}
		} else {
			if (result == JFileChooser.CANCEL_OPTION) {

			}
		}
	}

	public void saveImage(String savedImagePath) {
		try {
			imagePanel.save(new File(savedImagePath));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void setImageInfo() {
		jLabelImageInfoW.setText("" + imagePanel.getImageWidth());
		jLabelImageInfoH.setText("" + imagePanel.getImageHeight());
		jLabelImageInfoFr.setText("" + imagePanel.getFrames());
		jLabelImageInfoFileSz.setText("" + imagePanel.getFileSize());
	}

	private JSeparator getJSeparator2() {
		if (jSeparator2 == null) {
			jSeparator2 = new JSeparator();
		}
		return jSeparator2;
	}

	private JLabel getJLabelIPAddress() {
		if (jLabelIPAddress == null) {
			jLabelIPAddress = new JLabel();
			jLabelIPAddress.setText("IP Address:");
		}
		return jLabelIPAddress;
	}

	private JLabel getJLabelDeviceType() {
		if (jLabelDeviceType == null) {
			jLabelDeviceType = new JLabel();
			jLabelDeviceType.setText("Device Type:");
		}
		return jLabelDeviceType;
	}

	private JTextField getJTextFieldIPAddress() {
		if (jTextFieldIPAddress == null) {
			jTextFieldIPAddress = new JTextField();
			jTextFieldIPAddress.setText("255.255.255.255");
			jTextFieldIPAddress.setEnabled(true);
			jTextFieldIPAddress.addFocusListener(new FocusAdapter() {
				@Override
				public void focusLost(FocusEvent e) {
					changeIPActionPerformed();
					jTextFieldIPAddress2.setText(jTextFieldIPAddress.getText());
				}

				@Override
				public void focusGained(FocusEvent e) {
				}
			});
		}
		return jTextFieldIPAddress;
	}

	private JTextField getJTextFieldIPAddress2() {
		if (jTextFieldIPAddress2 == null) {
			jTextFieldIPAddress2 = new JTextField();
			jTextFieldIPAddress2.setText("255.255.255.255");
			jTextFieldIPAddress2.setEnabled(true);
			jTextFieldIPAddress2.addFocusListener(new FocusAdapter() {
				@Override
				public void focusLost(FocusEvent e) {
					changeIPActionPerformed();
					jTextFieldIPAddress.setText(jTextFieldIPAddress2.getText());
				}

				@Override
				public void focusGained(FocusEvent e) {
				}
			});
		}
		return jTextFieldIPAddress2;
	}

	private JComboBox getJComboBoxDeviceType() {
		if (jComboBoxDeviceType == null) {
			ComboBoxModel jComboBoxDeviceTypeModel = new DefaultComboBoxModel(
					new String[] { "Ethernet", "USB", "Parallel Port" });
			jComboBoxDeviceType = new JComboBox();
			jComboBoxDeviceType.setModel(jComboBoxDeviceTypeModel);
			jComboBoxDeviceType.setEnabled(true);
			jComboBoxDeviceType.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					changeDeviceTypeActionPerformed();
				}
			});
		}
		return jComboBoxDeviceType;
	}

	private JMenuItem getJMenuItemIP() {
		if (jMenuItemIP == null) {
			jMenuItemIP = new JMenuItem();
			jMenuItemIP.setText("Set camera IP...");
			jMenuItemIP.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent evt) {
					getJDialogSetIP();
				}
			});
		}
		return jMenuItemIP;
	}

	private JMenuItem getJMenuItemDeviceType() {
		if (jMenuItemDeviceType == null) {
			jMenuItemDeviceType = new JMenuItem();
			jMenuItemDeviceType.setText("Set device type...");
			jMenuItemDeviceType.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent evt) {
					getJDialogSelectDeviceType();
				}
			});
		}
		return jMenuItemDeviceType;
	}
}
