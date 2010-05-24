package alma.ucn.oca.ccd.ui;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import javax.swing.*;


/**
* This code was edited or generated using CloudGarden's Jigloo
* SWT/Swing GUI Builder, which is free for non-commercial
* use. If Jigloo is being used commercially (ie, by a corporation,
* company or business for any purpose whatever) then you
* should purchase a license for each developer using Jigloo.
* Please visit www.cloudgarden.com for details.
* Use of Jigloo implies acceptance of these licensing terms.
* A COMMERCIAL LICENSE HAS NOT BEEN PURCHASED FOR
* THIS MACHINE, SO JIGLOO OR THIS CODE CANNOT BE USED
* LEGALLY FOR ANY CORPORATE OR COMMERCIAL PURPOSE.
*/
public class gCCDGUIClient extends javax.swing.JFrame {

	/**
	 * 
	 */
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
	private ButtonGroup buttonGroupCCDSetupMenuModels;
	private JMenu jMenuCCDSetupModels;
	private JRadioButtonMenuItem jRadioButtonMenuItem2;
	private JRadioButtonMenuItem jRadioButtonMenuItem1;
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
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				gCCDGUIClient inst = new gCCDGUIClient();
				inst.pack();
				inst.setLocationRelativeTo(null);
				inst.setMinimumSize(inst.getSize());
				inst.setVisible(true);
			}
		});
	}
	
	public gCCDGUIClient() {
		super();
		initGUI();
	}
	
	private void initGUI() {
		try {
			{
				GridBagLayout thisLayout = new GridBagLayout();
				thisLayout.rowWeights = new double[] {0.1};
				thisLayout.rowHeights = new int[] {7};
				thisLayout.columnWeights = new double[] {0.1};
				thisLayout.columnWidths = new int[] {7};
				getContentPane().setLayout(thisLayout);
				this.setTitle("gCCD - [No camera selected]");
				{
					jSplitPaneVertical = new JSplitPane();
					getContentPane().add(jSplitPaneVertical, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0, 0));
					jSplitPaneVertical.setOrientation(JSplitPane.VERTICAL_SPLIT);
					jSplitPaneVertical.setOneTouchExpandable(true);
					jSplitPaneVertical.setResizeWeight(1.0);
					{
						jTabbedPaneOptions = new JTabbedPane();
						jSplitPaneVertical.add(jTabbedPaneOptions, JSplitPane.RIGHT);
						jTabbedPaneOptions.setMinimumSize(new java.awt.Dimension(800, 200));
						jTabbedPaneOptions.setSize(800, 200);
						jTabbedPaneOptions.setPreferredSize(new java.awt.Dimension(800, 200));
						jTabbedPaneOptions.setMaximumSize(new java.awt.Dimension(32767, 200));
						{
							jPanelCCDSetup = new JPanel();
							jTabbedPaneOptions.addTab("CCD Setup", null, jPanelCCDSetup, null);
							{
								jLabelCCDSetup = new JLabel();
								jPanelCCDSetup.add(jLabelCCDSetup);
								jLabelCCDSetup.setText("CCD Setup");
							}
							{
								jLabelCCDModels = new JLabel();
								jPanelCCDSetup.add(jLabelCCDModels);
								jLabelCCDModels.setText("Select CCD Model:");
							}
							{
								ComboBoxModel jComboBoxCCDModelsModel = 
									new DefaultComboBoxModel(
											new String[] { "Item One", "Item Two" });
								jComboBoxCCDModels = new JComboBox();
								jPanelCCDSetup.add(jComboBoxCCDModels);
								jComboBoxCCDModels.setModel(jComboBoxCCDModelsModel);
							}
							{
								jButtonCCDConnect = new JButton();
								jPanelCCDSetup.add(jButtonCCDConnect);
								jButtonCCDConnect.setText("Connect");
							}
							{
								jButtonDisconnect = new JButton();
								jPanelCCDSetup.add(jButtonDisconnect);
								jButtonDisconnect.setText("Disconnect");
							}
						}
						{
							jPanelCCDSettings = new JPanel();
							jTabbedPaneOptions.addTab("CCD Settings", null, jPanelCCDSettings, null);
							{
								jLabelCCDSettings = new JLabel();
								jPanelCCDSettings.add(jLabelCCDSettings);
								jLabelCCDSettings.setText("CCD Settings");
							}
							{
								jLabelCCDTemp = new JLabel();
								jPanelCCDSettings.add(jLabelCCDTemp);
								jLabelCCDTemp.setText("Cooling Temperature (ºC):");
							}
							{
								SpinnerListModel jSpinnerCCDTempModel = 
									new SpinnerListModel(
											new String[] { "Sun", "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" });
								jSpinnerCCDTemp = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDTemp);
								jSpinnerCCDTemp.setModel(jSpinnerCCDTempModel);
							}
							{
								jLabelCCDExpTime = new JLabel();
								jPanelCCDSettings.add(jLabelCCDExpTime);
								jLabelCCDExpTime.setText("Exposure Time (s):");
							}
							{
								SpinnerListModel jSpinnerCCDExpTimeModel = 
									new SpinnerListModel(
											new String[] { "Sun", "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" });
								jSpinnerCCDExpTime = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDExpTime);
								jSpinnerCCDExpTime.setModel(jSpinnerCCDExpTimeModel);
							}
							{
								jLabelCCDNAcc = new JLabel();
								jPanelCCDSettings.add(jLabelCCDNAcc);
								jLabelCCDNAcc.setText("Accumulations:");
							}
							{
								SpinnerListModel jSpinnerCCDNAccModel = 
									new SpinnerListModel(
											new String[] { "Sun", "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" });
								jSpinnerCCDNAcc = new JSpinner();
								jPanelCCDSettings.add(jSpinnerCCDNAcc);
								jSpinnerCCDNAcc.setModel(jSpinnerCCDNAccModel);
							}
							{
								jLabelCCDScanType = new JLabel();
								jPanelCCDSettings.add(jLabelCCDScanType);
								jPanelCCDSettings.add(getJRadioButtonCCDScanTypeSingle());
								jPanelCCDSettings.add(getJRadioButtonCCDScanTypeAcc());
								jLabelCCDScanType.setText("Scan Type:");
							}
						}
						{
							jPanelCCDControl = new JPanel();
							jTabbedPaneOptions.addTab("CCD Control", null, jPanelCCDControl, null);
							{
								jLabelCCDControl = new JLabel();
								jPanelCCDControl.add(jLabelCCDControl);
								jPanelCCDControl.add(getJButtonCCDOn());
								jPanelCCDControl.add(getJButtonCCDOff());
								jPanelCCDControl.add(getJButtonCCDReset());
								jPanelCCDControl.add(getJButtonCCDStartExp());
								jPanelCCDControl.add(getJButtonCCDStopExp());
								jPanelCCDControl.add(getJButtonCCDStartCooler());
								jPanelCCDControl.add(getJButtonCCDStopCooler());
								jLabelCCDControl.setText("CCD Control");
							}
						}
						{
							jPanelImageOptions = new JPanel();
							jTabbedPaneOptions.addTab("Image Options", null, jPanelImageOptions, null);
							{
								jLabelImageOptions = new JLabel();
								jPanelImageOptions.add(jLabelImageOptions);
								jPanelImageOptions.add(getJButtonImageFitSize());
								jPanelImageOptions.add(getJButtonImageNormalSize());
								jPanelImageOptions.add(getJButtonImageSaveAs());
								jPanelImageOptions.add(getJButtonImagePrev());
								jPanelImageOptions.add(getJButtonImageNext());
								jLabelImageOptions.setText("Image Options");
							}
						}
					}
					{
						jSplitPaneHorizontal = new JSplitPane();
						jSplitPaneVertical.add(jSplitPaneHorizontal, JSplitPane.LEFT);
						jSplitPaneHorizontal.setOneTouchExpandable(true);
						jSplitPaneHorizontal.setResizeWeight(1.0);
						{
							jPanelImageInfo = new JPanel();
							jSplitPaneHorizontal.add(jPanelImageInfo, JSplitPane.RIGHT);
							jPanelImageInfo.setMinimumSize(new java.awt.Dimension(200, 400));
							jPanelImageInfo.setSize(200, 400);
							jPanelImageInfo.setPreferredSize(new java.awt.Dimension(200, 400));
							jPanelImageInfo.setMaximumSize(new java.awt.Dimension(200, 32767));
							jPanelImageInfo.add(getJLabelImageInfo());
							jPanelImageInfo.add(getJLabelImageInfoWidth());
							jPanelImageInfo.add(getJLabelImageInfoW());
							jPanelImageInfo.add(getJLabelImageInfoHeight());
							jPanelImageInfo.add(getJLabelImageInfoH());
							jPanelImageInfo.add(getJLabelImageInfoFileSize());
							jPanelImageInfo.add(getJLabelImageInfoFileSz());
							jPanelImageInfo.add(getJLabelImageInfoFrames());
							jPanelImageInfo.add(getJLabelImageInfoFr());
							jPanelImageInfo.add(getJLabelCCDInfo());
							jPanelImageInfo.add(getJLabelCCDInfoCurrTemp());
							jPanelImageInfo.add(getJLabelCCDInfoCurrT());
							jPanelImageInfo.add(getJLabelCCDInfoCoolerState());
							jPanelImageInfo.add(getJLabelCCDInfoCoolerSt());
							jPanelImageInfo.add(getJLabelCCDInfoCameraState());
							jPanelImageInfo.add(getJLabelCCDInfoCameaSt());
						}
						{
							jScrollPaneImage = new JScrollPane();
							jSplitPaneHorizontal.add(jScrollPaneImage, JSplitPane.LEFT);
							jScrollPaneImage.setMinimumSize(new java.awt.Dimension(600, 400));
							jScrollPaneImage.setSize(600, 400);
							jScrollPaneImage.setPreferredSize(new java.awt.Dimension(600, 400));
							jScrollPaneImage.setMaximumSize(new java.awt.Dimension(32767, 32767));
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
					jMenuCCDSettings.add(getJMenuItemCCDSettingsCoolerTemp());
					jMenuCCDSettings.add(getJMenuItemCCDSettingsExpTime());
					jMenuCCDSettings.add(getJMenuItemCCDSettingsNAcc());
					jMenuCCDSettings.add(getJMenuCCDSettingsScanType());
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
					jMenuImageOptions.add(getJRadioButtonMenuItemImageOptionsFitImage());
					jMenuImageOptions.add(getJRadioButtonMenuItemImageOptionsNormalSize());
					jMenuImageOptions.add(getJSeparator6());
					jMenuImageOptions.add(getJMenuItemImageOptionsSaveAs());
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
	}
	
	private ButtonGroup getButtonGroupCCDSettingsMenuScanType() {
		if(buttonGroupCCDSettingsMenuScanType == null) {
			buttonGroupCCDSettingsMenuScanType = new ButtonGroup();
		}
		return buttonGroupCCDSettingsMenuScanType;
	}
	
	private JRadioButton getJRadioButtonCCDScanTypeSingle() {
		if(jRadioButtonCCDScanTypeSingle == null) {
			jRadioButtonCCDScanTypeSingle = new JRadioButton();
			jRadioButtonCCDScanTypeSingle.setText("Single Scan");
			getButtonGroupCCDSettingsTabScanType().add(jRadioButtonCCDScanTypeSingle);
		}
		return jRadioButtonCCDScanTypeSingle;
	}
	
	private JRadioButton getJRadioButtonCCDScanTypeAcc() {
		if(jRadioButtonCCDScanTypeAcc == null) {
			jRadioButtonCCDScanTypeAcc = new JRadioButton();
			jRadioButtonCCDScanTypeAcc.setText("Accumulative");
			getButtonGroupCCDSettingsTabScanType().add(jRadioButtonCCDScanTypeAcc);
		}
		return jRadioButtonCCDScanTypeAcc;
	}
	
	private JButton getJButtonCCDOn() {
		if(jButtonCCDOn == null) {
			jButtonCCDOn = new JButton();
			jButtonCCDOn.setText("Start CCD");
		}
		return jButtonCCDOn;
	}
	
	private JButton getJButtonCCDOff() {
		if(jButtonCCDOff == null) {
			jButtonCCDOff = new JButton();
			jButtonCCDOff.setText("Shutdown CCD");
		}
		return jButtonCCDOff;
	}
	
	private JButton getJButtonCCDReset() {
		if(jButtonCCDReset == null) {
			jButtonCCDReset = new JButton();
			jButtonCCDReset.setText("Reset CCD");
		}
		return jButtonCCDReset;
	}
	
	private JButton getJButtonCCDStartExp() {
		if(jButtonCCDStartExp == null) {
			jButtonCCDStartExp = new JButton();
			jButtonCCDStartExp.setText("Start Exposure");
		}
		return jButtonCCDStartExp;
	}
	
	private JButton getJButtonCCDStopExp() {
		if(jButtonCCDStopExp == null) {
			jButtonCCDStopExp = new JButton();
			jButtonCCDStopExp.setText("Stop Exposure");
		}
		return jButtonCCDStopExp;
	}
	
	private JButton getJButtonCCDStartCooler() {
		if(jButtonCCDStartCooler == null) {
			jButtonCCDStartCooler = new JButton();
			jButtonCCDStartCooler.setText("Start Cooler");
		}
		return jButtonCCDStartCooler;
	}
	
	private JButton getJButtonCCDStopCooler() {
		if(jButtonCCDStopCooler == null) {
			jButtonCCDStopCooler = new JButton();
			jButtonCCDStopCooler.setText("Stop Cooler");
		}
		return jButtonCCDStopCooler;
	}
	
	private JButton getJButtonImageFitSize() {
		if(jButtonImageFitSize == null) {
			jButtonImageFitSize = new JButton();
			jButtonImageFitSize.setText("Fit Image To Panel");
		}
		return jButtonImageFitSize;
	}
	
	private JButton getJButtonImageNormalSize() {
		if(jButtonImageNormalSize == null) {
			jButtonImageNormalSize = new JButton();
			jButtonImageNormalSize.setText("Original Image Size");
		}
		return jButtonImageNormalSize;
	}
	
	private JButton getJButtonImageSaveAs() {
		if(jButtonImageSaveAs == null) {
			jButtonImageSaveAs = new JButton();
			jButtonImageSaveAs.setText("Save Image As...");
		}
		return jButtonImageSaveAs;
	}
	
	private JButton getJButtonImageNext() {
		if(jButtonImageNext == null) {
			jButtonImageNext = new JButton();
			jButtonImageNext.setText("Next Image");
		}
		return jButtonImageNext;
	}
	
	private JButton getJButtonImagePrev() {
		if(jButtonImagePrev == null) {
			jButtonImagePrev = new JButton();
			jButtonImagePrev.setText("Previous Image");
		}
		return jButtonImagePrev;
	}
	
	private JLabel getJLabelImageInfo() {
		if(jLabelImageInfo == null) {
			jLabelImageInfo = new JLabel();
			jLabelImageInfo.setText("Image Information");
		}
		return jLabelImageInfo;
	}
	
	private JLabel getJLabelImageInfoWidth() {
		if(jLabelImageInfoWidth == null) {
			jLabelImageInfoWidth = new JLabel();
			jLabelImageInfoWidth.setText("Width (px):");
		}
		return jLabelImageInfoWidth;
	}
	
	private JLabel getJLabelImageInfoW() {
		if(jLabelImageInfoW == null) {
			jLabelImageInfoW = new JLabel();
			jLabelImageInfoW.setText("999");
		}
		return jLabelImageInfoW;
	}
	
	private JLabel getJLabelImageInfoHeight() {
		if(jLabelImageInfoHeight == null) {
			jLabelImageInfoHeight = new JLabel();
			jLabelImageInfoHeight.setText("Height (px):");
		}
		return jLabelImageInfoHeight;
	}
	
	private JLabel getJLabelImageInfoH() {
		if(jLabelImageInfoH == null) {
			jLabelImageInfoH = new JLabel();
			jLabelImageInfoH.setText("999");
		}
		return jLabelImageInfoH;
	}
	
	private JLabel getJLabelImageInfoFileSize() {
		if(jLabelImageInfoFileSize == null) {
			jLabelImageInfoFileSize = new JLabel();
			jLabelImageInfoFileSize.setText("File Size (kB):");
		}
		return jLabelImageInfoFileSize;
	}
	
	private JLabel getJLabelImageInfoFileSz() {
		if(jLabelImageInfoFileSz == null) {
			jLabelImageInfoFileSz = new JLabel();
			jLabelImageInfoFileSz.setText("999");
		}
		return jLabelImageInfoFileSz;
	}
	
	private JLabel getJLabelImageInfoFrames() {
		if(jLabelImageInfoFrames == null) {
			jLabelImageInfoFrames = new JLabel();
			jLabelImageInfoFrames.setText("Frames:");
		}
		return jLabelImageInfoFrames;
	}
	
	private JLabel getJLabelImageInfoFr() {
		if(jLabelImageInfoFr == null) {
			jLabelImageInfoFr = new JLabel();
			jLabelImageInfoFr.setText("999");
		}
		return jLabelImageInfoFr;
	}
	
	private JLabel getJLabelCCDInfo() {
		if(jLabelCCDInfo == null) {
			jLabelCCDInfo = new JLabel();
			jLabelCCDInfo.setText("CCD Information");
		}
		return jLabelCCDInfo;
	}
	
	private JLabel getJLabelCCDInfoCurrTemp() {
		if(jLabelCCDInfoCurrTemp == null) {
			jLabelCCDInfoCurrTemp = new JLabel();
			jLabelCCDInfoCurrTemp.setText("Current Temperature (ºC):");
		}
		return jLabelCCDInfoCurrTemp;
	}
	
	private JLabel getJLabelCCDInfoCurrT() {
		if(jLabelCCDInfoCurrT == null) {
			jLabelCCDInfoCurrT = new JLabel();
			jLabelCCDInfoCurrT.setText("999");
		}
		return jLabelCCDInfoCurrT;
	}
	
	private JLabel getJLabelCCDInfoCoolerState() {
		if(jLabelCCDInfoCoolerState == null) {
			jLabelCCDInfoCoolerState = new JLabel();
			jLabelCCDInfoCoolerState.setText("Cooler State:");
		}
		return jLabelCCDInfoCoolerState;
	}
	
	private JLabel getJLabelCCDInfoCoolerSt() {
		if(jLabelCCDInfoCoolerSt == null) {
			jLabelCCDInfoCoolerSt = new JLabel();
			jLabelCCDInfoCoolerSt.setText("On/Off");
		}
		return jLabelCCDInfoCoolerSt;
	}
	
	private JLabel getJLabelCCDInfoCameraState() {
		if(jLabelCCDInfoCameraState == null) {
			jLabelCCDInfoCameraState = new JLabel();
			jLabelCCDInfoCameraState.setText("Camera State:");
		}
		return jLabelCCDInfoCameraState;
	}
	
	private JLabel getJLabelCCDInfoCameaSt() {
		if(jLabelCCDInfoCameaSt == null) {
			jLabelCCDInfoCameaSt = new JLabel();
			jLabelCCDInfoCameaSt.setText("Working/On/Off/Disconnected/Connected");
		}
		return jLabelCCDInfoCameaSt;
	}

	private JRadioButtonMenuItem getJRadioButtonMenuItem1() {
		if(jRadioButtonMenuItem1 == null) {
			jRadioButtonMenuItem1 = new JRadioButtonMenuItem();
			jRadioButtonMenuItem1.setText("jRadioButtonMenuItem1");
			jRadioButtonMenuItem1.setBounds(88, -21, 152, 21);
			getButtonGroupCCDSetupMenuModels().add(jRadioButtonMenuItem1);
		}
		return jRadioButtonMenuItem1;
	}
	
	private JRadioButtonMenuItem getJRadioButtonMenuItem2() {
		if(jRadioButtonMenuItem2 == null) {
			jRadioButtonMenuItem2 = new JRadioButtonMenuItem();
			jRadioButtonMenuItem2.setText("jRadioButtonMenuItem2");
			jRadioButtonMenuItem2.setBounds(88, -21, 152, 21);
			getButtonGroupCCDSetupMenuModels().add(jRadioButtonMenuItem2);
		}
		return jRadioButtonMenuItem2;
	}
	
	private JMenu getJMenuCCDSetupModels() {
		if(jMenuCCDSetupModels == null) {
			jMenuCCDSetupModels = new JMenu();
			jMenuCCDSetupModels.setText("CCD Models");
			jMenuCCDSetupModels.add(getJRadioButtonMenuItem2());
			jMenuCCDSetupModels.add(getJRadioButtonMenuItem1());
		}
		return jMenuCCDSetupModels;
	}
	
	private ButtonGroup getButtonGroupCCDSetupMenuModels() {
		if(buttonGroupCCDSetupMenuModels == null) {
			buttonGroupCCDSetupMenuModels = new ButtonGroup();
		}
		return buttonGroupCCDSetupMenuModels;
	}
	
	private JMenuItem getJMenuItemCCDSetupConnect() {
		if(jMenuItemCCDSetupConnect == null) {
			jMenuItemCCDSetupConnect = new JMenuItem();
			jMenuItemCCDSetupConnect.setText("Connect");
		}
		return jMenuItemCCDSetupConnect;
	}
	
	private JMenuItem getJMenuItemCCDSetupDisconnect() {
		if(jMenuItemCCDSetupDisconnect == null) {
			jMenuItemCCDSetupDisconnect = new JMenuItem();
			jMenuItemCCDSetupDisconnect.setText("Disconnect");
		}
		return jMenuItemCCDSetupDisconnect;
	}
	
	private JMenuItem getJMenuItemCCDSettingsCoolerTemp() {
		if(jMenuItemCCDSettingsCoolerTemp == null) {
			jMenuItemCCDSettingsCoolerTemp = new JMenuItem();
			jMenuItemCCDSettingsCoolerTemp.setText("Cooler Temperature...");
		}
		return jMenuItemCCDSettingsCoolerTemp;
	}
	
	private JMenuItem getJMenuItemCCDSettingsExpTime() {
		if(jMenuItemCCDSettingsExpTime == null) {
			jMenuItemCCDSettingsExpTime = new JMenuItem();
			jMenuItemCCDSettingsExpTime.setText("Exposure Time...");
		}
		return jMenuItemCCDSettingsExpTime;
	}
	
	private JMenuItem getJMenuItemCCDSettingsNAcc() {
		if(jMenuItemCCDSettingsNAcc == null) {
			jMenuItemCCDSettingsNAcc = new JMenuItem();
			jMenuItemCCDSettingsNAcc.setText("Accumulations...");
		}
		return jMenuItemCCDSettingsNAcc;
	}
	
	private JMenu getJMenuCCDSettingsScanType() {
		if(jMenuCCDSettingsScanType == null) {
			jMenuCCDSettingsScanType = new JMenu();
			jMenuCCDSettingsScanType.setText("Scan Type");
			jMenuCCDSettingsScanType.add(getJRadioButtonCCDSettingsScanTypeSingle());
			jMenuCCDSettingsScanType.add(getJRadioButtonCCDSettingsScanTypeAccumulated());
		}
		return jMenuCCDSettingsScanType;
	}
	
	private ButtonGroup getButtonGroupCCDSettingsTabScanType() {
		if(buttonGroupCCDSettingsTabScanType == null) {
			buttonGroupCCDSettingsTabScanType = new ButtonGroup();
		}
		return buttonGroupCCDSettingsTabScanType;
	}
	
	private JRadioButtonMenuItem getJRadioButtonCCDSettingsScanTypeSingle() {
		if(jRadioButtonCCDSettingsScanTypeSingle == null) {
			jRadioButtonCCDSettingsScanTypeSingle = new JRadioButtonMenuItem();
			jRadioButtonCCDSettingsScanTypeSingle.setText("Single Scan");
			getButtonGroupCCDSettingsMenuScanType().add(jRadioButtonCCDSettingsScanTypeSingle);
		}
		return jRadioButtonCCDSettingsScanTypeSingle;
	}
	
	private JRadioButtonMenuItem getJRadioButtonCCDSettingsScanTypeAccumulated() {
		if(jRadioButtonCCDSettingsScanTypeAccumulative == null) {
			jRadioButtonCCDSettingsScanTypeAccumulative = new JRadioButtonMenuItem();
			jRadioButtonCCDSettingsScanTypeAccumulative.setText("Accumulative");
			getButtonGroupCCDSettingsMenuScanType().add(jRadioButtonCCDSettingsScanTypeAccumulative);
		}
		return jRadioButtonCCDSettingsScanTypeAccumulative;
	}
	
	private JMenuItem getJMenuItemCCDControlOn() {
		if(jMenuItemCCDControlOn == null) {
			jMenuItemCCDControlOn = new JMenuItem();
			jMenuItemCCDControlOn.setText("Start CCD");
		}
		return jMenuItemCCDControlOn;
	}
	
	private JMenuItem getJMenuItemCCDControlOff() {
		if(jMenuItemCCDControlOff == null) {
			jMenuItemCCDControlOff = new JMenuItem();
			jMenuItemCCDControlOff.setText("Shutdown CCD");
		}
		return jMenuItemCCDControlOff;
	}
	
	private JSeparator getJSeparator3() {
		if(jSeparator3 == null) {
			jSeparator3 = new JSeparator();
		}
		return jSeparator3;
	}
	
	private JMenuItem getJMenuItemCCDControlReset() {
		if(jMenuItemCCDControlReset == null) {
			jMenuItemCCDControlReset = new JMenuItem();
			jMenuItemCCDControlReset.setText("Reset CCD");
		}
		return jMenuItemCCDControlReset;
	}
	
	private JSeparator getJSeparator4() {
		if(jSeparator4 == null) {
			jSeparator4 = new JSeparator();
		}
		return jSeparator4;
	}
	
	private JMenuItem getJMenuItemCCDControlStartExp() {
		if(jMenuItemCCDControlStartExp == null) {
			jMenuItemCCDControlStartExp = new JMenuItem();
			jMenuItemCCDControlStartExp.setText("Start Exposure");
		}
		return jMenuItemCCDControlStartExp;
	}
	
	private JMenuItem getJMenuItemCCDControlStopExp() {
		if(jMenuItemCCDControlStopExp == null) {
			jMenuItemCCDControlStopExp = new JMenuItem();
			jMenuItemCCDControlStopExp.setText("Stop Exposure");
		}
		return jMenuItemCCDControlStopExp;
	}
	
	private JSeparator getJSeparator5() {
		if(jSeparator5 == null) {
			jSeparator5 = new JSeparator();
		}
		return jSeparator5;
	}
	
	private JMenuItem getJMenuItemCCDControlStartCooler() {
		if(jMenuItemCCDControlStartCooler == null) {
			jMenuItemCCDControlStartCooler = new JMenuItem();
			jMenuItemCCDControlStartCooler.setText("Start Cooler");
		}
		return jMenuItemCCDControlStartCooler;
	}
	
	private JMenuItem getJMenuItemCCDControlStopCooler() {
		if(jMenuItemCCDControlStopCooler == null) {
			jMenuItemCCDControlStopCooler = new JMenuItem();
			jMenuItemCCDControlStopCooler.setText("Stop Cooler");
		}
		return jMenuItemCCDControlStopCooler;
	}
	
	private ButtonGroup getButtonGroupImageOptionsMenuImageSize() {
		if(buttonGroupImageOptionsMenuImageSize == null) {
			buttonGroupImageOptionsMenuImageSize = new ButtonGroup();
		}
		return buttonGroupImageOptionsMenuImageSize;
	}
	
	private JRadioButtonMenuItem getJRadioButtonMenuItemImageOptionsFitImage() {
		if(jRadioButtonMenuItemImageOptionsFitSize == null) {
			jRadioButtonMenuItemImageOptionsFitSize = new JRadioButtonMenuItem();
			jRadioButtonMenuItemImageOptionsFitSize.setText("Fit Image To Panel");
			getButtonGroupImageOptionsMenuImageSize().add(jRadioButtonMenuItemImageOptionsFitSize);
		}
		return jRadioButtonMenuItemImageOptionsFitSize;
	}
	
	private JRadioButtonMenuItem getJRadioButtonMenuItemImageOptionsNormalSize() {
		if(jRadioButtonMenuItemImageOptionsNormalSize == null) {
			jRadioButtonMenuItemImageOptionsNormalSize = new JRadioButtonMenuItem();
			jRadioButtonMenuItemImageOptionsNormalSize.setText("Original Image Size");
			getButtonGroupImageOptionsMenuImageSize().add(jRadioButtonMenuItemImageOptionsNormalSize);
		}
		return jRadioButtonMenuItemImageOptionsNormalSize;
	}
	
	private JSeparator getJSeparator6() {
		if(jSeparator6 == null) {
			jSeparator6 = new JSeparator();
		}
		return jSeparator6;
	}
	
	private JMenuItem getJMenuItemImageOptionsSaveAs() {
		if(jMenuItemImageOptionsSaveAs == null) {
			jMenuItemImageOptionsSaveAs = new JMenuItem();
			jMenuItemImageOptionsSaveAs.setText("Save Image As...");
		}
		return jMenuItemImageOptionsSaveAs;
	}
	
	private JSeparator getJSeparator7() {
		if(jSeparator7 == null) {
			jSeparator7 = new JSeparator();
		}
		return jSeparator7;
	}
	
	private JMenuItem getJMenuItemImageOptionsPrev() {
		if(jMenuItemImageOptionsPrev == null) {
			jMenuItemImageOptionsPrev = new JMenuItem();
			jMenuItemImageOptionsPrev.setText("Previous Image");
		}
		return jMenuItemImageOptionsPrev;
	}
	
	private JMenuItem getJMenuItemImageOptionsNext() {
		if(jMenuItemImageOptionsNext == null) {
			jMenuItemImageOptionsNext = new JMenuItem();
			jMenuItemImageOptionsNext.setText("Next Image");
		}
		return jMenuItemImageOptionsNext;
	}
	
	private JSeparator getJSeparator8() {
		if(jSeparator8 == null) {
			jSeparator8 = new JSeparator();
		}
		return jSeparator8;
	}
	
	private JMenuItem getJMenuItemHelpAbout() {
		if(jMenuItemHelpAbout == null) {
			jMenuItemHelpAbout = new JMenuItem();
			jMenuItemHelpAbout.setText("About gCCD...");
		}
		return jMenuItemHelpAbout;
	}

}
