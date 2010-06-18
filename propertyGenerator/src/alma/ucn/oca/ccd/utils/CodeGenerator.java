package alma.ucn.oca.ccd.utils;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;

import javax.swing.*;

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
public class CodeGenerator extends javax.swing.JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private JMenuItem helpMenuItem;
	private JMenu jMenu5;
	private JSeparator jSeparator1;
	private JMenuItem removePropertyMenuItem;
	private JMenuItem addPropertyMenuItem;
	private JMenu jMenu4;
	private JMenuItem exitMenuItem;
	private JSeparator jSeparator2;
	private JMenuItem saveAsMenuItem;
	private JMenuItem generateMenuItem;
	private JMenuItem saveMenuItem;
	private JMenuItem openFileMenuItem;
	private JMenuItem newFileMenuItem;
	private JMenu jMenu3;
	private JMenuBar jMenuBar1;

	LinkedList<JLabel> propertyNameLabels;
	private JPanel jPanelPropertyRORW;
	private JPanel jPanelPropertyRORWLabels;
	private JPanel jPanelPropertyTypes;
	private JPanel jPanelPropertyTypeLabels;
	LinkedList<JTextField> propertyNames;
	LinkedList<JLabel> propertyTypeLabels;
	LinkedList<JComboBox> propertyTypes;
	LinkedList<JLabel> propertyRORWLabels;
	LinkedList<JComboBox> propertyRORW;

	private JPanel jPanelPropertyNames;
	private JPanel jPanelPropertyNameLabels;
	private JPanel jPanel1;

	/**
	 * Auto-generated main method to display this JFrame
	 */
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				CodeGenerator inst = new CodeGenerator();
				inst.setLocationRelativeTo(null);
				inst.setVisible(true);
			}
		});
	}

	public CodeGenerator() {
		super();
		initGUI();

		this.addWindowListener(new WindowCloseManager());
	}

	private void initGUI() {
		try {
			getContentPane().add(getJPanel1(), BorderLayout.CENTER);
			this.setSize(776, 181);
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
						generateMenuItem = new JMenuItem();
						jMenu3.add(generateMenuItem);
						generateMenuItem.setText("Generate code");
						generateMenuItem
								.addActionListener(new ActionListener() {
									@Override
									public void actionPerformed(ActionEvent e) {
										generateCodeAction(e);
									}
								});
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
						addPropertyMenuItem = new JMenuItem();
						jMenu4.add(addPropertyMenuItem);
						addPropertyMenuItem.setText("Add property");
						addPropertyMenuItem
								.addActionListener(new ActionListener() {
									@Override
									public void actionPerformed(ActionEvent e) {
										addPropertyAction(e);
									}
								});
					}
					{
						removePropertyMenuItem = new JMenuItem();
						jMenu4.add(removePropertyMenuItem);
						removePropertyMenuItem.setText("Remove property");
						removePropertyMenuItem
								.addActionListener(new ActionListener() {
									@Override
									public void actionPerformed(ActionEvent e) {
										removePropertyAction(e);
									}
								});
					}
					{
						jSeparator1 = new JSeparator();
						jMenu4.add(jSeparator1);
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

	private JPanel getJPanel1() {
		if (jPanel1 == null) {
			jPanel1 = new JPanel();
			GridBagLayout jPanel1Layout = new GridBagLayout();
			jPanel1Layout.rowWeights = new double[] { 0.1 };
			jPanel1Layout.rowHeights = new int[] { 7 };
			jPanel1Layout.columnWeights = new double[] { 0.1, 0.1, 0.1, 0.1,
					0.1, 0.1 };
			jPanel1Layout.columnWidths = new int[] { 7, 7, 7, 7, 7, 7 };
			jPanel1.setLayout(jPanel1Layout);
			jPanel1.add(getJPanelPropertyNames(),
					new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
			jPanel1.add(getJPanelPropertyNamesText(),
					new GridBagConstraints(1, 0, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
			jPanel1.add(getJPanelPropertyTypeLabels(),
					new GridBagConstraints(2, 0, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
			jPanel1.add(getJPanelPropertyTypes(),
					new GridBagConstraints(3, 0, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
			jPanel1.add(getJPanelPropertyRORWLabels(),
					new GridBagConstraints(4, 0, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
			jPanel1.add(getJPanelPropertyRORW(),
					new GridBagConstraints(5, 0, 1, 1, 0.0, 0.0,
							GridBagConstraints.CENTER,
							GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0,
									0), 0, 0));
		}
		return jPanel1;
	}

	private JPanel getJPanelPropertyNames() {
		if (jPanelPropertyNameLabels == null) {
			jPanelPropertyNameLabels = new JPanel();
			BoxLayout jPanelPropertyNameLabelsLayout = new BoxLayout(
					jPanelPropertyNameLabels, javax.swing.BoxLayout.Y_AXIS);
			jPanelPropertyNameLabels.setLayout(jPanelPropertyNameLabelsLayout);
		}
		return jPanelPropertyNameLabels;
	}

	private JPanel getJPanelPropertyNamesText() {
		if (jPanelPropertyNames == null) {
			jPanelPropertyNames = new JPanel();
			BoxLayout jPanelPropertyNamesLayout = new BoxLayout(
					jPanelPropertyNames, javax.swing.BoxLayout.Y_AXIS);
			jPanelPropertyNames.setLayout(jPanelPropertyNamesLayout);
		}
		return jPanelPropertyNames;
	}

	private JPanel getJPanelPropertyTypeLabels() {
		if (jPanelPropertyTypeLabels == null) {
			jPanelPropertyTypeLabels = new JPanel();
			BoxLayout jPanelPropertyTypeLabelsLayout = new BoxLayout(
					jPanelPropertyTypeLabels, javax.swing.BoxLayout.Y_AXIS);
			jPanelPropertyTypeLabels.setLayout(jPanelPropertyTypeLabelsLayout);
		}
		return jPanelPropertyTypeLabels;
	}

	private JPanel getJPanelPropertyTypes() {
		if (jPanelPropertyTypes == null) {
			jPanelPropertyTypes = new JPanel();
			BoxLayout jPanelPropertyTypesLayout = new BoxLayout(
					jPanelPropertyTypes, javax.swing.BoxLayout.Y_AXIS);
			jPanelPropertyTypes.setLayout(jPanelPropertyTypesLayout);
		}
		return jPanelPropertyTypes;
	}

	private JPanel getJPanelPropertyRORWLabels() {
		if (jPanelPropertyRORWLabels == null) {
			jPanelPropertyRORWLabels = new JPanel();
			BoxLayout jPanelPropertyRORWLabelsLayout = new BoxLayout(
					jPanelPropertyRORWLabels, javax.swing.BoxLayout.Y_AXIS);
			jPanelPropertyRORWLabels.setLayout(jPanelPropertyRORWLabelsLayout);
		}
		return jPanelPropertyRORWLabels;
	}

	private JPanel getJPanelPropertyRORW() {
		if (jPanelPropertyRORW == null) {
			jPanelPropertyRORW = new JPanel();
			BoxLayout jPanelPropertyRORWLayout = new BoxLayout(
					jPanelPropertyRORW, javax.swing.BoxLayout.Y_AXIS);
			jPanelPropertyRORW.setLayout(jPanelPropertyRORWLayout);
		}
		return jPanelPropertyRORW;
	}

	public void addProperty() {
		if (propertyNameLabels == null) {
			propertyNameLabels = new LinkedList<JLabel>();
		}
		if (propertyNames == null) {
			propertyNames = new LinkedList<JTextField>();
		}
		if (propertyTypeLabels == null) {
			propertyTypeLabels = new LinkedList<JLabel>();
		}
		if (propertyTypes == null) {
			propertyTypes = new LinkedList<JComboBox>();
		}
		if (propertyRORWLabels == null) {
			propertyRORWLabels = new LinkedList<JLabel>();
		}
		if (propertyRORW == null) {
			propertyRORW = new LinkedList<JComboBox>();
		}
		propertyNameLabels.add(new JLabel("Property name:"));
		propertyNames.add(new JTextField());
		propertyTypeLabels.add(new JLabel("Type:"));
		propertyTypes.add(new JComboBox(new String[] { "Double", "Long",
				"String" }));
		propertyRORWLabels.add(new JLabel("RO/RW:"));
		propertyRORW.add(new JComboBox(new DefaultComboBoxModel(new String[] {
				"Read only", "Read write" })));
		
		int w = 150;
		int h = 15;

		propertyNameLabels.getLast().setPreferredSize(new Dimension(w, h));
		propertyNames.getLast().setPreferredSize(new Dimension(w, h));
		propertyTypeLabels.getLast().setPreferredSize(new Dimension(w, h));
		propertyTypes.getLast().setPreferredSize(new Dimension(w, h));
		propertyRORWLabels.getLast().setPreferredSize(new Dimension(w, h));
		propertyRORW.getLast().setPreferredSize(new Dimension(w, h));

		propertyNameLabels.getLast().setSize(new Dimension(w, h));
		propertyNames.getLast().setSize(new Dimension(w, h));
		propertyTypeLabels.getLast().setSize(new Dimension(w, h));
		propertyTypes.getLast().setSize(new Dimension(w, h));
		propertyRORWLabels.getLast().setSize(new Dimension(w, h));
		propertyRORW.getLast().setSize(new Dimension(w, h));
	}

	public void removeProperty() {
		if (propertyNameLabels == null) {
			propertyNameLabels = new LinkedList<JLabel>();
		}
		if (propertyNames == null) {
			propertyNames = new LinkedList<JTextField>();
		}
		if (propertyTypeLabels == null) {
			propertyTypeLabels = new LinkedList<JLabel>();
		}
		if (propertyTypes == null) {
			propertyTypes = new LinkedList<JComboBox>();
		}
		if (propertyRORWLabels == null) {
			propertyRORWLabels = new LinkedList<JLabel>();
		}
		if (propertyRORW == null) {
			propertyRORW = new LinkedList<JComboBox>();
		}
		propertyNameLabels.removeLast();
		propertyNames.removeLast();
		propertyTypeLabels.removeLast();
		propertyTypes.removeLast();
		propertyRORWLabels.removeLast();
		propertyRORW.removeLast();
	}

	public void addPropertyAction(ActionEvent e) {
		addProperty();

		jPanelPropertyNameLabels.add(propertyNameLabels.getLast());
		jPanelPropertyNames.add(propertyNames.getLast());
		jPanelPropertyTypeLabels.add(propertyTypeLabels.getLast());
		jPanelPropertyTypes.add(propertyTypes.getLast());
		jPanelPropertyRORWLabels.add(propertyRORWLabels.getLast());
		jPanelPropertyRORW.add(propertyRORW.getLast());

		pack();
	}

	public void removePropertyAction(ActionEvent e) {
		if (propertyNameLabels != null) {
			if (propertyNameLabels.size() != 0) {
				jPanelPropertyNameLabels.remove(propertyNameLabels.getLast());
				jPanelPropertyNames.remove(propertyNames.getLast());
				jPanelPropertyTypeLabels.remove(propertyTypeLabels.getLast());
				jPanelPropertyTypes.remove(propertyTypes.getLast());
				jPanelPropertyRORWLabels.remove(propertyRORWLabels.getLast());
				jPanelPropertyRORW.remove(propertyRORW.getLast());
				removeProperty();

				jPanel1.validate();

				pack();
			}
		}
	}

	public void generateCodeAction(ActionEvent e) {
		try {
			generateIDL();
			generateComponentIncludeFile();
			generateComponenCppFile();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}

	public void generateIDL() throws IOException {
		BufferedWriter outputStream = new BufferedWriter(new FileWriter(
				"idl_properties.inc"));

		for (int i = 0; i < propertyNames.size(); i++) {
			outputStream.write("readonly attribute ACS::");

			switch (propertyRORW.get(i).getSelectedIndex()) {
			case 0:
				outputStream.write("RO");
				break;
			case 1:
				outputStream.write("RW");
				break;
			}

			switch (propertyTypes.get(i).getSelectedIndex()) {
			case 0:
				outputStream.write("double ");
				break;
			case 1:
				outputStream.write("long ");
				break;
			case 2:
				outputStream.write("string ");
				break;
			}

			outputStream.write(propertyNames.get(i).getText() + ";");
			// System.out.println(idl_property);
		}
		outputStream.newLine();
		outputStream.flush();
		outputStream.close();
	}

	public void generateComponentIncludeFile() throws IOException {
		BufferedWriter include_property = new BufferedWriter(new FileWriter(
				"component_properties.inc"));
		BufferedWriter prototype_method = new BufferedWriter(new FileWriter(
				"component_prototypes.inc"));
		for (int i = 0; i < propertyNames.size(); i++) {
			include_property.write("SmartPropertyPointer<");
			prototype_method.write("virtual ACS::");

			switch (propertyRORW.get(i).getSelectedIndex()) {
			case 0:
				include_property.write("RO");
				prototype_method.write("RO");
				break;
			case 1:
				include_property.write("RW");
				prototype_method.write("RW");
				break;
			}

			switch (propertyTypes.get(i).getSelectedIndex()) {
			case 0:
				include_property.write("double> ");
				prototype_method.write("double_ptr ");
				break;
			case 1:
				include_property.write("long> ");
				prototype_method.write("long_ptr ");
				break;
			case 2:
				include_property.write("string> ");
				prototype_method.write("string_ptr ");
				break;
			}

			include_property.write("m_" + propertyNames.get(i).getText()
					+ "_sp;");
			prototype_method.write(propertyNames.get(i).getText() + "() ");
			prototype_method.write("throw (CORBA::SystemException);");
			// System.out.println(include_property);
			// System.out.println(prototype_method);
		}
		include_property.newLine();
		include_property.flush();
		include_property.close();
		prototype_method.newLine();
		prototype_method.flush();
		prototype_method.close();
	}

	public void generateComponenCppFile() throws IOException {
		BufferedWriter component_constructor = new BufferedWriter(
				new FileWriter("component_constructor.inc"));
		BufferedWriter component_methods = new BufferedWriter(new FileWriter(
				"component_methods.inc"));
		component_constructor
				.write("CCDComponent::CCDComponent(const ACE_CString& name, maci::ContainerServices * containerServices) :CharacteristicComponentImpl(name, containerServices)");

		String constructor_properties = "";
		String ctor_m_r = "";
		String ctor_m_t = "";
		for (int i = 0; i < propertyNames.size(); i++) {
			constructor_properties += "m_" + propertyNames.get(i).getText()
					+ "_sp = new ";
			component_methods.write("ACS::");

			switch (propertyRORW.get(i).getSelectedIndex()) {
			case 0:
				constructor_properties += "RO";
				ctor_m_r = "RO";
				component_methods.write(ctor_m_r);
				break;
			case 1:
				constructor_properties += "RW";
				ctor_m_r = "RW";
				component_methods.write(ctor_m_r);
				break;
			}

			switch (propertyTypes.get(i).getSelectedIndex()) {
			case 0:
				constructor_properties += "double(name + \":";
				ctor_m_t = "double";
				component_methods.write("double_ptr CCDComponent::");
				break;
			case 1:
				constructor_properties += "long(name + \":";
				ctor_m_t = "long";
				component_methods.write("long_ptr CCDComponent::");
				break;
			case 2:
				constructor_properties += "string(name + \":";
				ctor_m_t = "string";
				component_methods.write("string_ptr CCDComponent::");
				break;
			}

			component_constructor.write(", m_" + propertyNames.get(i).getText()
					+ "_sp(this)");
			constructor_properties += propertyNames.get(i).getText()
					+ "\", getComponent());";
			component_methods.write(propertyNames.get(i).getText()
					+ "() throw (CORBA::SystemException) { if (!m_"
					+ propertyNames.get(i).getText() + "_sp) { return ACS::"
					+ ctor_m_r + ctor_m_t + "::_nil(); }ACS::" + ctor_m_r
					+ ctor_m_t + "_var prop = ACS::" + ctor_m_r + ctor_m_t
					+ "::_narrow(m_" + propertyNames.get(i).getText()
					+ "_sp->getCORBAReference()); return prop._retn();	}");
			// System.out.println(constructor_properties);
			// System.out.println(constructor_method);
		}
		component_constructor.write("{");
		component_constructor.write(constructor_properties);
		component_constructor.write("}");
		component_constructor.newLine();
		component_constructor.flush();
		component_constructor.close();
		component_methods.newLine();
		component_methods.flush();
		component_methods.close();
		// System.out.println(constructor_parameters);
	}
	
	private static class WindowCloseManager extends WindowAdapter {
		public void windowClosing(WindowEvent evt) {
			System.exit(0);
		}
	}
}
