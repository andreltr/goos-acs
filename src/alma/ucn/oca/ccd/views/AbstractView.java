/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package alma.ucn.oca.ccd.views;

import java.awt.HeadlessException;
import java.beans.PropertyChangeEvent;
import javax.swing.JFrame;

/**
 *
 * @author JacKFour
 */
public abstract class AbstractView extends JFrame {

    public AbstractView() throws HeadlessException {
    }

    public abstract void modelPropertyChange(PropertyChangeEvent evt);
}
