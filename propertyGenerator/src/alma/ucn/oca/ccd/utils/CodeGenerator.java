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
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
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
	private JMenuItem removePropertyMenuItem;
	private JMenuItem addPropertyMenuItem;
	private JMenu jMenu4;
	private JMenuItem exitMenuItem;
	private JSeparator jSeparator2;
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
						newFileMenuItem.addActionListener(new ActionListener() {
							@Override
							public void actionPerformed(ActionEvent e) {
								newCodeAction(e);
							}
						});
					}
					{
						openFileMenuItem = new JMenuItem();
						jMenu3.add(openFileMenuItem);
						openFileMenuItem.setText("Open");
						openFileMenuItem
								.addActionListener(new ActionListener() {
									@Override
									public void actionPerformed(ActionEvent e) {
										openCodeAction(e);
									}
								});
					}
					{
						saveMenuItem = new JMenuItem();
						jMenu3.add(saveMenuItem);
						saveMenuItem.setText("Save");
						saveMenuItem.addActionListener(new ActionListener() {
							@Override
							public void actionPerformed(ActionEvent e) {
								saveCodeAction(e);
							}
						});
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
						exitMenuItem.addActionListener(new ActionListener() {
							@Override
							public void actionPerformed(ActionEvent e) {
								System.exit(0);
							}
						});
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

	public void newCodeAction(ActionEvent e) {
		if (propertyNameLabels != null) {
			propertyNameLabels = null;
		}
		if (propertyNames != null) {
			propertyNames = null;
		}
		if (propertyTypeLabels != null) {
			propertyTypeLabels = null;
		}
		if (propertyTypes != null) {
			propertyTypes = null;
		}
		if (propertyRORWLabels != null) {
			propertyRORWLabels = null;
		}
		if (propertyRORW != null) {
			propertyRORW = null;
		}

		jPanelPropertyNameLabels.removeAll();
		jPanelPropertyNames.removeAll();
		jPanelPropertyTypeLabels.removeAll();
		jPanelPropertyTypes.removeAll();
		jPanelPropertyRORWLabels.removeAll();
		jPanelPropertyRORW.removeAll();

		pack();
	}

	public void openCodeAction(ActionEvent e) {
		newCodeAction(e);

		try {
			BufferedReader properties = new BufferedReader(new FileReader(
					"properties.prop"));

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

			String s = properties.readLine();

			int w = 150;
			int h = 15;

			while (!s.equals("---")) {
				propertyNameLabels.add(new JLabel("Property name:"));
				propertyNames.add(new JTextField(s));

				propertyNameLabels.getLast().setPreferredSize(
						new Dimension(w, h));
				propertyNames.getLast().setPreferredSize(new Dimension(w, h));

				propertyNameLabels.getLast().setSize(new Dimension(w, h));
				propertyNames.getLast().setSize(new Dimension(w, h));

				s = properties.readLine();
			}
			s = properties.readLine();
			while (!s.equals("---")) {
				propertyTypeLabels.add(new JLabel("Type:"));
				propertyTypes.add(new JComboBox(new String[] { "Double",
						"Long", "String" }));
				propertyTypes.getLast().setSelectedIndex(new Integer(s));

				propertyTypeLabels.getLast().setPreferredSize(
						new Dimension(w, h));
				propertyTypes.getLast().setPreferredSize(new Dimension(w, h));

				propertyTypeLabels.getLast().setSize(new Dimension(w, h));
				propertyTypes.getLast().setSize(new Dimension(w, h));

				s = properties.readLine();
			}
			s = properties.readLine();
			while (!s.equals("---")) {
				propertyRORWLabels.add(new JLabel("RO/RW:"));
				propertyRORW.add(new JComboBox(new DefaultComboBoxModel(
						new String[] { "Read only", "Read write" })));
				propertyRORW.getLast().setSelectedIndex(new Integer(s));

				propertyRORWLabels.getLast().setPreferredSize(
						new Dimension(w, h));
				propertyRORW.getLast().setPreferredSize(new Dimension(w, h));

				propertyRORWLabels.getLast().setSize(new Dimension(w, h));
				propertyRORW.getLast().setSize(new Dimension(w, h));

				s = properties.readLine();
			}

			properties.close();

		} catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

		for (int i = 0; i < propertyNames.size(); i++) {
			jPanelPropertyNameLabels.add(propertyNameLabels.get(i));
			jPanelPropertyNames.add(propertyNames.get(i));
			jPanelPropertyTypeLabels.add(propertyTypeLabels.get(i));
			jPanelPropertyTypes.add(propertyTypes.get(i));
			jPanelPropertyRORWLabels.add(propertyRORWLabels.get(i));
			jPanelPropertyRORW.add(propertyRORW.get(i));
		}
		pack();
	}

	public void saveCodeAction(ActionEvent e) {

		if (propertyNames != null) {
			try {
				BufferedWriter properties = new BufferedWriter(new FileWriter(
						"properties.prop"));
				for (JTextField j : propertyNames) {
					properties.write(j.getText());
					properties.newLine();
				}
				properties.write("---");
				properties.newLine();
				for (JComboBox j : propertyTypes) {
					properties.write("" + j.getSelectedIndex());
					properties.newLine();
				}
				properties.write("---");
				properties.newLine();
				for (JComboBox j : propertyRORW) {
					properties.write("" + j.getSelectedIndex());
					properties.newLine();
				}
				properties.write("---");
				properties.newLine();

				properties.close();

			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
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
		BufferedWriter idl_properties = new BufferedWriter(new FileWriter(
				"idl_properties.inc"));

		for (int i = 0; i < propertyNames.size(); i++) {
			idl_properties.write("readonly attribute ACS::");

			switch (propertyRORW.get(i).getSelectedIndex()) {
			case 0:
				idl_properties.write("RO");
				break;
			case 1:
				idl_properties.write("RW");
				break;
			}

			switch (propertyTypes.get(i).getSelectedIndex()) {
			case 0:
				idl_properties.write("double ");
				break;
			case 1:
				idl_properties.write("long ");
				break;
			case 2:
				idl_properties.write("string ");
				break;
			}

			idl_properties.write(propertyNames.get(i).getText() + ";");
			idl_properties.newLine();
		}
		idl_properties.flush();
		idl_properties.close();
	}

	public void generateComponentIncludeFile() throws IOException {
		BufferedWriter component_properties = new BufferedWriter(
				new FileWriter("component_properties.inc"));
		BufferedWriter component_prototypes = new BufferedWriter(
				new FileWriter("component_prototypes.inc"));
		for (int i = 0; i < propertyNames.size(); i++) {
			component_properties.write("SmartPropertyPointer<");
			component_prototypes.write("virtual ACS::");

			switch (propertyRORW.get(i).getSelectedIndex()) {
			case 0:
				component_properties.write("RO");
				component_prototypes.write("RO");
				break;
			case 1:
				component_properties.write("RW");
				component_prototypes.write("RW");
				break;
			}

			switch (propertyTypes.get(i).getSelectedIndex()) {
			case 0:
				component_properties.write("double> ");
				component_prototypes.write("double_ptr ");
				break;
			case 1:
				component_properties.write("long> ");
				component_prototypes.write("long_ptr ");
				break;
			case 2:
				component_properties.write("string> ");
				component_prototypes.write("string_ptr ");
				break;
			}

			component_properties.write("m_" + propertyNames.get(i).getText()
					+ "_sp;");
			component_properties.newLine();

			component_prototypes.write(propertyNames.get(i).getText() + "() ");
			component_prototypes.write("throw (CORBA::SystemException);");
			component_prototypes.newLine();
		}
		component_properties.flush();
		component_properties.close();
		component_prototypes.flush();
		component_prototypes.close();
	}

	public void generateComponenCppFile() throws IOException {
		BufferedWriter component_constructor = new BufferedWriter(
				new FileWriter("component_constructor.inc"));
		BufferedWriter component_methods = new BufferedWriter(new FileWriter(
				"component_methods.inc"));
		component_constructor
				.write("CCDComponent::CCDComponent(const ACE_CString& name,\n"
						+ "\t\tmaci::ContainerServices * containerServices) :\n"
						+ "\tCharacteristicComponentImpl(name, containerServices)\n");

		String constructor_properties = "";
		String ctor_m_r = "";
		String ctor_m_t = "";
		for (int i = 0; i < propertyNames.size(); i++) {
			constructor_properties += "\tm_" + propertyNames.get(i).getText()
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

			component_constructor.write("\t\t\t, m_"
					+ propertyNames.get(i).getText() + "_sp(this)\n");
			constructor_properties += propertyNames.get(i).getText()
					+ "\", getComponent());\n";

			component_methods.write(propertyNames.get(i).getText() + "()\n"
					+ "\t\tthrow (CORBA::SystemException) {\n" + "\tif (!m_"
					+ propertyNames.get(i).getText() + "_sp) {\n"
					+ "\t\treturn ACS::" + ctor_m_r + ctor_m_t + "::_nil();\n"
					+ "\t}\n" + "\tACS::" + ctor_m_r + ctor_m_t
					+ "_var prop = ACS::" + ctor_m_r + ctor_m_t
					+ "::_narrow(\n" + "\t\t\tm_"
					+ propertyNames.get(i).getText()
					+ "_sp->getCORBAReference());\n"
					+ "\treturn prop._retn();\n" + "}\n\n");
		}
		component_constructor.write("{\n");
		component_constructor.write(constructor_properties);
		component_constructor.write("}");
		component_constructor.newLine();
		component_constructor.flush();
		component_constructor.close();
		component_methods.flush();
		component_methods.close();
	}

	private static class WindowCloseManager extends WindowAdapter {
		public void windowClosing(WindowEvent evt) {
			System.exit(0);
		}
	}
}
