package alma.ucn.oca.ccd.ui;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Panel;
import java.awt.ScrollPane;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import javax.swing.BorderFactory;
import javax.swing.ComboBoxModel;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.ScrollPaneConstants;
import javax.swing.SpinnerListModel;
import javax.swing.WindowConstants;
import javax.swing.border.BevelBorder;
import javax.swing.border.LineBorder;
import javax.swing.plaf.basic.BasicScrollPaneUI.ViewportChangeHandler;
import javax.swing.SwingUtilities;
import javax.swing.JViewport;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.filechooser.*;
import java.io.File;
import javax.swing.Timer;
import java.awt.event.*;
import java.util.LinkedList;

import magick.*;
import magick.util.*;

import alma.ucn.oca.ccd.logic.*;

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
public class luckyClientCCDGUI extends javax.swing.JFrame {
	private JButton jBtnDropConnection;
	private JPanel jPanelInformationCamera;
	private JButton jBtnOriginalSize;
	private JButton jBtnAdjustImage;
	private JLabel jLabelPercentage;
	private JLabel jLabelImagePercentage;
	private JLabel jLabelcounterTemporizador;
	private JLabel jLblCamModel;
	private JComboBox jCmbCamModel;
	private JButton jBtnNextFrame;
	private JButton jBtnPrevFrame;
	// Filename spinner
	private JSpinner jSpinnerFilename;
	private SpinnerListModel SpinnerFilenameModel;
	private JLabel jLabelCurrentFile;
	private JButton jBtnCancel;
	private JSpinner jSpinnerFramesPerFile;
	private JLabel jLabelFramePerFile;
	private JLabel jLabelTituloTemporizador;
	private JButton jBtnSaveImage;
	private JScrollPane jScrollPaneImage;
	private JSpinner jSpinnerExposureTime;
	private JButton jBtnStartExposure;
	private JPanel jPanelImage;
	private JLabel jLblExposureTitle;
	private JPanel Exposure;
	private JTabbedPane jTabPaneOptions;
	private JButton jBtnGetConnection;
	private ImagePanels panelImagen;
	private Timer imageListTimer;
	private BufferedImage image;
	JFileChooser jFileChooserDialog;
	private int counterTemp;
	// Logic reference
	private luckyClientCCDController controller;
	// Current exposition time
	private int ExposureTime;
	// Used to calculate the completed percentage
	public static int percentageIndex = 0;

	/**
	 * Auto-generated main method to display this JFrame
	 */
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				luckyClientCCDGUI inst = new luckyClientCCDGUI();
				inst.setLocationRelativeTo(null);
				inst.setVisible(true);

			}
		});
	}

	public luckyClientCCDGUI() {
		super();
		SpinnerFilenameModel = null;

		// Timer to update the list of files received
		imageListTimer = new Timer(1000, new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				imageListTimerEvent();
			}
		});

		initGUI();
	}

	private void initGUI() {
		try {
			controller = new luckyClientCCDController();
			setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
			getContentPane().setLayout(null);
			this.setPreferredSize(new java.awt.Dimension(807, 750));
			this.setResizable(false);
			this.addWindowListener(new WindowAdapter() {
				public void windowClosing(WindowEvent evt) {
					thisWindowClosing(evt);
				}
			});
			{
				// Button GetConnection
				jBtnGetConnection = new JButton();
				getContentPane().add(jBtnGetConnection);
				jBtnGetConnection.setText("Connect to Camera");
				jBtnGetConnection.setBounds(599, 551, 176, 22);
				jBtnGetConnection.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jBtnConnectionMouseClicked(evt);
					}
				});
			}
			{
				// Button DropConnection
				jBtnDropConnection = new JButton();
				getContentPane().add(jBtnDropConnection);
				jBtnDropConnection.setText("Disconnect from Camera");
				jBtnDropConnection.setBounds(599, 592, 176, 22);
				jBtnDropConnection.setEnabled(false);
				jBtnDropConnection.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jBtnDropConnectionMouseClicked(evt);
					}
				});
			}
			{
				// Tabbed options panel
				jTabPaneOptions = new JTabbedPane();
				getContentPane().add(jTabPaneOptions);
				jTabPaneOptions.setBounds(31, 504, 545, 187);
				{
					// Exposure settings
					Exposure = new JPanel();
					jTabPaneOptions.addTab("Exposure Settings", null, Exposure,
							null);
					Exposure.setPreferredSize(new java.awt.Dimension(540, 159));
					Exposure.setLayout(null);
					{
						jLblExposureTitle = new JLabel();
						Exposure.add(jLblExposureTitle);
						jLblExposureTitle.setText("Exposure time:");
						jLblExposureTitle.setBounds(24, 33, 161, 14);
					}

					{
						jPanelInformationCamera = new JPanel();
						Exposure.add(jPanelInformationCamera);
						jPanelInformationCamera.setBounds(270, 12, 258, 136);

						jPanelInformationCamera.setBorder(BorderFactory
								.createTitledBorder("Camera Information"));
						jPanelInformationCamera.setLayout(null);
						{
							jLabelTituloTemporizador = new JLabel();
							jPanelInformationCamera
									.add(jLabelTituloTemporizador);
							jLabelTituloTemporizador.setText("Exposure time:");
							jLabelTituloTemporizador.setBounds(10, 32, 106, 14);
						}
						{
							// Current exposure time
							jLabelcounterTemporizador = new JLabel();
							jPanelInformationCamera
									.add(jLabelcounterTemporizador);
							jLabelcounterTemporizador.setText("0");
							jLabelcounterTemporizador
									.setBounds(114, 31, 86, 14);
						}
						{
							jLabelImagePercentage = new JLabel();
							jPanelInformationCamera.add(jLabelImagePercentage);
							jLabelImagePercentage.setText("Completed:");
							jLabelImagePercentage.setBounds(11, 57, 97, 14);
						}
						{
							// Label to display current completed percentage
							jLabelPercentage = new JLabel();
							jPanelInformationCamera.add(jLabelPercentage);
							jLabelPercentage.setBounds(114, 57, 86, 14);
							jLabelPercentage.setText("percentage");
						}
						{
							//Camera models from the IDL
							ComboBoxModel jCmbCamModelModel = 
								new DefaultComboBoxModel(controller.getCameraModels());
							jCmbCamModel = new JComboBox();
							jPanelInformationCamera.add(jCmbCamModel);
							jCmbCamModel.setModel(jCmbCamModelModel);
							jCmbCamModel.setBounds(114, 83, 105, 18);
							jCmbCamModel.setEnabled(false);
							jCmbCamModel.addActionListener(new ActionListener() {
								@Override
								public void actionPerformed(ActionEvent e) {
									controller.setCCDModel(jCmbCamModel.getSelectedIndex());								
								}
							});
						}
						{
							//Camera model label
							jLblCamModel = new JLabel();
							jPanelInformationCamera.add(jLblCamModel);
							jLblCamModel.setText("Camera model:");
							jLblCamModel.setBounds(11, 84, 97, 12);
						}
					}
					{
						// Button StartExposure
						jBtnStartExposure = new JButton();
						Exposure.add(jBtnStartExposure);
						jBtnStartExposure.setEnabled(false);
						jBtnStartExposure.setText("Start");
						jBtnStartExposure.setBounds(23, 112, 95, 21);
						jBtnStartExposure.addMouseListener(new MouseAdapter() {
							public void mousePressed(MouseEvent evt) {
								jBtnStartExposureMousePressed(evt);
							}
						});
					}
					{
						// Spinner to select exposure time
						// Parameters: initial value, minvalue, maxvalue, step
						SpinnerNumberModel model = new SpinnerNumberModel(1, 0,
								10, 0.01F);
						jSpinnerExposureTime = new JSpinner(model);
						Exposure.add(jSpinnerExposureTime);
						jSpinnerExposureTime.setBounds(160, 30, 69, 21);
						jSpinnerExposureTime.setEnabled(false);
					}
					{
						// Label for frames per file
						jLabelFramePerFile = new JLabel();
						Exposure.add(jLabelFramePerFile);
						jLabelFramePerFile.setText("N° of accumulations:");
						jLabelFramePerFile.setBounds(24, 59, 161, 16);
					}
					{
						// Spinner to select the number of frames per file
						// Parameters: initial value, minvalue, maxvalue, step
						SpinnerNumberModel jSpinnerFramesPerFileModel = new SpinnerNumberModel(
								7, 1, 10, 1);
						jSpinnerFramesPerFile = new JSpinner();
						Exposure.add(jSpinnerFramesPerFile);
						jSpinnerFramesPerFile
								.setModel(jSpinnerFramesPerFileModel);
						jSpinnerFramesPerFile.setBounds(160, 56, 69, 23);
						jSpinnerFramesPerFile.setEnabled(false);
					}
					{
						// Button to stop the image acquisition
						jBtnCancel = new JButton();
						Exposure.add(jBtnCancel);
						jBtnCancel.setText("Stop");
						jBtnCancel.setBounds(134, 112, 95, 21);
						jBtnCancel.setEnabled(false);
						jBtnCancel.addMouseListener(new MouseAdapter() {
							public void mousePressed(MouseEvent evt) {
								jBtnCancelExposureMousePressed(evt);
							}
						});
					}

				}
				{
					// Image options tab
					jPanelImage = new JPanel();
					jTabPaneOptions.addTab("Image Options", null, jPanelImage,
							null);
					jPanelImage.setLayout(null);
					jPanelImage.setPreferredSize(new java.awt.Dimension(547,
							159));
					{
						// Button AdjustImage
						jBtnAdjustImage = new JButton();
						jPanelImage.add(jBtnAdjustImage);
						jBtnAdjustImage.setEnabled(false);
						jBtnAdjustImage.setText("Adjust Size");
						jBtnAdjustImage.setBounds(29, 32, 153, 21);
						jBtnAdjustImage.addMouseListener(new MouseAdapter() {
							public void mouseClicked(MouseEvent evt) {
								jBtnAdjustImageMouseClicked(evt);
							}
						});
					}
					{
						// Button OriginalSize
						jBtnOriginalSize = new JButton();
						jPanelImage.add(jBtnOriginalSize);
						jBtnOriginalSize.setEnabled(false);
						jBtnOriginalSize.setText("Original Size");
						jBtnOriginalSize.setBounds(29, 58, 153, 21);
						jBtnOriginalSize.addMouseListener(new MouseAdapter() {
							public void mouseClicked(MouseEvent evt) {
								jBtnOriginalSizeMouseClicked(evt);
							}
						});
					}
					{
						// Button SaveImage
						jBtnSaveImage = new JButton();
						jPanelImage.add(jBtnSaveImage);
						jBtnSaveImage.setEnabled(false);
						jBtnSaveImage.setText("Save Image...");
						jBtnSaveImage.setBounds(29, 99, 153, 21);
						jBtnSaveImage.addMouseListener(new MouseAdapter() {
							public void mouseClicked(MouseEvent evt) {
								jBtnSaveImageMouseClicked(evt);
							}
						});
					}
					{
						// Label for the filename spinner
						jLabelCurrentFile = new JLabel();
						jPanelImage.add(jLabelCurrentFile);
						jLabelCurrentFile.setText("File on display:");
						jLabelCurrentFile.setBounds(246, 34, 78, 16);
					}
					{
						// Spinner to select the file being displayed
						SpinnerListModel jSpinnerFilenameModel = new SpinnerListModel(
								new String[] { "null.bmp" });
						jSpinnerFilename = new JSpinner();
						jPanelImage.add(jSpinnerFilename);
						jSpinnerFilename.setModel(jSpinnerFilenameModel);
						jSpinnerFilename.setBounds(360, 31, 113, 23);

						// Listener that gets called when the value of the
						// spinner changes. Every time the file should be
						// diplayed on the
						// image panel.
						jSpinnerFilename
								.addChangeListener(new ChangeListener() {
									@Override
									public void stateChanged(ChangeEvent e) {
										// Avoids creating unnecessary objects
										if (panelImagen == null) {
											panelImagen = new ImagePanels(
													jScrollPaneImage.getWidth() - 30,
													jScrollPaneImage
															.getHeight() - 45,
													jSpinnerFilename.getValue()
															.toString());
										}
										// We only send the name of the file
										// the method has a hard coded filepath
										// this should be fixed.
										panelImagen.setImage(jSpinnerFilename
												.getValue().toString());
										jScrollPaneImage
												.setViewportView(panelImagen);
									}
								});
					}
					{
						//Previous frame
						jBtnPrevFrame = new JButton();
						jPanelImage.add(jBtnPrevFrame);
						jBtnPrevFrame.setText("Previous frame");
						jBtnPrevFrame.setBounds(246, 66, 100, 30);
					}
					{
						//Next frame
						jBtnNextFrame = new JButton();
						jPanelImage.add(jBtnNextFrame);
						jBtnNextFrame.setText("Next frame");
						jBtnNextFrame.setBounds(373, 66, 100, 30);
					}
				}
			}
			{

				{
					jScrollPaneImage = new JScrollPane(
							ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
							ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
					jScrollPaneImage.setBorder(BorderFactory
							.createTitledBorder("Image"));
					getContentPane().add(jScrollPaneImage);
					jScrollPaneImage.setBounds(116, 33, 516, 431);

				}
				{
					// File selector dialog
					jFileChooserDialog = new JFileChooser();
					jFileChooserDialog
							.addChoosableFileFilter(new FileSelectorDialog());

				}
			}
			pack();
			this.setSize(807, 750);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// Event for the Connect to Camera button
	private void jBtnConnectionMouseClicked(MouseEvent evt) {
		if (jBtnGetConnection.isEnabled() == true) {
			try {
				jBtnDropConnection.setEnabled(true);
				jBtnGetConnection.setEnabled(false);
				jBtnStartExposure.setEnabled(true);
				jCmbCamModel.setEnabled(true);
				controller.getConnection();
				jCmbCamModel.setSelectedIndex(0);
				jSpinnerExposureTime.setEnabled(true);
				jSpinnerFramesPerFile.setEnabled(true);

			} catch (Exception e) {
				jBtnDropConnection.setEnabled(false);
				jBtnGetConnection.setEnabled(true);
				jBtnStartExposure.setEnabled(false);
				jCmbCamModel.setEnabled(false);
				jSpinnerExposureTime.setEnabled(false);
				jSpinnerFramesPerFile.setEnabled(false);
				e.printStackTrace();
			}
		}
	}

	// Event for the Disconnect from camera button
	private void jBtnDropConnectionMouseClicked(MouseEvent evt) {
		if (jBtnDropConnection.isEnabled() == true) {
			try {
				jBtnDropConnection.setEnabled(false);
				jBtnGetConnection.setEnabled(true);
				jBtnStartExposure.setEnabled(false);
				jBtnCancel.setEnabled(false);
				jBtnSaveImage.setEnabled(false);
				jBtnOriginalSize.setEnabled(false);
				jBtnAdjustImage.setEnabled(false);
				jCmbCamModel.setEnabled(false);
				controller.dropConnection();
				jSpinnerExposureTime.setEnabled(false);
				jSpinnerFramesPerFile.setEnabled(false);

			} catch (Exception e) {
				jBtnDropConnection.setEnabled(true);
				jBtnGetConnection.setEnabled(false);
				//Solving bug 3
				jBtnStartExposure.setEnabled(false);
				jBtnCancel.setEnabled(true);
				jBtnSaveImage.setEnabled(true);
				jBtnOriginalSize.setEnabled(true);
				jBtnAdjustImage.setEnabled(true);
				jCmbCamModel.setEnabled(true);
				jSpinnerExposureTime.setEnabled(true);
				jSpinnerFramesPerFile.setEnabled(true);

				e.printStackTrace();
				System.exit(-1);
			}
		}
	}

	// Event called on closing the window
	private void thisWindowClosing(WindowEvent evt) {
		try {
			controller.dropConnection();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	// Event for the Start Exposure button
	private void jBtnStartExposureMousePressed(MouseEvent evt) {
		if (jBtnStartExposure.isEnabled() == true) {
			try {
				float exposureTime = Float.parseFloat(jSpinnerExposureTime
						.getValue().toString());
				int numberOfAcc = Integer.parseInt(jSpinnerFramesPerFile
						.getValue().toString());
				// Send a petition
				jBtnStartExposure.setEnabled(false);
				jBtnCancel.setEnabled(true);
				jSpinnerExposureTime.setEnabled(false);
				jSpinnerFramesPerFile.setEnabled(false);
				jCmbCamModel.setEnabled(false);
				imageListTimer.start();
				controller.getImage(640,480,2,numberOfAcc,exposureTime);

				// counterTemp = ExposureTime;
				// jLabelcounterTemporizador.setText(String.valueOf(counterTemp));
			} catch (Exception e) {
				jBtnStartExposure.setEnabled(true);
				jBtnCancel.setEnabled(false);
				jSpinnerExposureTime.setEnabled(false);
				jSpinnerFramesPerFile.setEnabled(false);
				jCmbCamModel.setEnabled(false);
				e.printStackTrace();
			}
		}
	}

	// Event for the Cancel exposure button
	private void jBtnCancelExposureMousePressed(MouseEvent evt) {
		if (jBtnCancel.isEnabled() == true) {
			controller.disconnectConsumer();
			imageListTimer.stop();
			jBtnStartExposure.setEnabled(true);
			jBtnCancel.setEnabled(false);
			jBtnSaveImage.setEnabled(true);
			jBtnOriginalSize.setEnabled(true);
			jBtnAdjustImage.setEnabled(true);
			jSpinnerExposureTime.setEnabled(true);
			jSpinnerFramesPerFile.setEnabled(true);
			jCmbCamModel.setEnabled(true);			
		}
	}

	// Event for the Adjust Image button
	private void jBtnAdjustImageMouseClicked(MouseEvent evt) {
		if (jBtnAdjustImage.isEnabled() == true) {
			if (panelImagen != null) {
				panelImagen.adjustImage();
			} else {
				JOptionPane.showMessageDialog(this, "Error: No image loaded.",
						"Information", 2);
			}
		}

	}

	// Event for the Original size button
	private void jBtnOriginalSizeMouseClicked(MouseEvent evt) {
		if (jBtnOriginalSize.isEnabled() == true) {
			if (panelImagen != null) {
				panelImagen.panelToAdjustImage();
			} else {
				JOptionPane.showMessageDialog(this, "Error: No image loaded.",
						"Information", 2);
			}
		}

	}

	// Event for the Save Image button
	private void jBtnSaveImageMouseClicked(MouseEvent evt) {
		if (jBtnSaveImage.isEnabled() == true) {
			int result = jFileChooserDialog.showSaveDialog(this);
			File fileObj = jFileChooserDialog.getSelectedFile();// We get the
			// path to save the image
			if (result == JFileChooser.APPROVE_OPTION) {
				try {
					// We append the .fits extension if it's not found
					if (jFileChooserDialog.getFileFilter().accept(fileObj) == true) {
						controller.saveImage(fileObj.getAbsolutePath(),
								jSpinnerFilename.getValue().toString());
					} else {
						controller.saveImage(fileObj.getAbsolutePath()
								+ ".fits", jSpinnerFilename.getValue()
								.toString());
					}

				} catch (Exception ex) {
					ex.printStackTrace();
				}
			} else {
				if (result == JFileChooser.CANCEL_OPTION) {

				}
			}
		}
	}

	// This method updates the completed percentage
	public void imageListTimerEvent() {
		// Image has been received
		if (!controller.isConsumerOn()) {
			imageListTimer.stop();
			LinkedList<String> list = controller.getFilenameList();

			if (list != null) {
				if (SpinnerFilenameModel == null) {
					SpinnerFilenameModel = new SpinnerListModel();
				}
				SpinnerFilenameModel.setList(list);
				jSpinnerFilename.setModel(SpinnerFilenameModel);

				if (panelImagen == null) {
					panelImagen = new ImagePanels(
							jScrollPaneImage.getWidth() - 30, jScrollPaneImage
									.getHeight() - 45, jSpinnerFilename
									.getValue().toString());
				}

				panelImagen.setImage(jSpinnerFilename.getValue().toString());
				jScrollPaneImage.setViewportView(panelImagen);
			}

			jBtnStartExposure.setEnabled(true);
			jBtnCancel.setEnabled(false);
			jBtnSaveImage.setEnabled(true);
			jBtnOriginalSize.setEnabled(true);
			jBtnAdjustImage.setEnabled(true);
			jSpinnerExposureTime.setEnabled(true);
			jSpinnerFramesPerFile.setEnabled(true);
			jCmbCamModel.setEnabled(true);
		} else {
			// We get the list of filenames and add it to the spinner so it
			// can be selected
			LinkedList<String> list = controller.getFilenameList();

			if (list != null) {
				if (SpinnerFilenameModel == null) {
					SpinnerFilenameModel = new SpinnerListModel();
				}
				SpinnerFilenameModel.setList(list);
				jSpinnerFilename.setModel(SpinnerFilenameModel);

				if (panelImagen == null) {
					panelImagen = new ImagePanels(
							jScrollPaneImage.getWidth() - 30, jScrollPaneImage
									.getHeight() - 45, jSpinnerFilename
									.getValue().toString());
				}

				panelImagen.setImage(jSpinnerFilename.getValue().toString());
				jScrollPaneImage.setViewportView(panelImagen);
			}

			jBtnStartExposure.setEnabled(false);
			jBtnCancel.setEnabled(true);
			jSpinnerExposureTime.setEnabled(false);
			jSpinnerFramesPerFile.setEnabled(false);
			jBtnSaveImage.setEnabled(true);
			jBtnOriginalSize.setEnabled(true);
			jBtnAdjustImage.setEnabled(true);
			jCmbCamModel.setEnabled(false);
		}
	}

}
