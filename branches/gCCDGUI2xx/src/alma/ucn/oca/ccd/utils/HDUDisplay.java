package alma.ucn.oca.ccd.utils;

import eap.fits.*;

import javax.swing.*;
import java.awt.*;
import javax.swing.border.*;
import java.awt.event.*;

/*******************************************************************************
* Component for displaying a single HDU of a FITS file. This component is
* used by the {@link eap.fitsbrowser.FITSFileDisplay}, but it could be
* embedded in any tool which needs to diplay the contents of a single FITS
* HDU.
*******************************************************************************/
public class HDUDisplay extends JTabbedPane {

FitsHDU hdu;
JPanel headerDisplay;
JComponent dataDisplay;

/******************************************************************************
* Construct a new display which will show the data in the given HDU.
* @param hdu the HDU to be displayed.
******************************************************************************/
public HDUDisplay(FitsHDU hdu) throws FitsException {

/*****************
* set the layout *
*****************/
//setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

/*********
* header *
*********/
FitsHeader header = hdu.getHeader();
int nrows = header.cardCount();
JTextArea text = new JTextArea(nrows, 80 );
text.setFont(new Font("Courier", Font.PLAIN, 12) );
text.setLineWrap(false);



/***********
* add text *
***********/
for(int i=0; i<nrows; ++i) {
    text.append(header.card(i) +"\n");
}

JScrollPane scroll = new JScrollPane(text);

Dimension dimen = scroll.getPreferredSize();
dimen = new Dimension(dimen.width, dimen.width/3 );
scroll.setPreferredSize(dimen);

/************************************************
* make a border labled wth the name of this HDU *
************************************************/
setBorder(BorderFactory.createTitledBorder(
          BorderFactory.createLineBorder(Color.red), 
          header.getName(),TitledBorder.RIGHT, TitledBorder.BELOW_TOP ));



/*******************
* now add the data *
*******************/
FitsData data = hdu.getData();

try {
    /***************
    * table viewer *
    ***************/
    JTable table = new JTable( (FitsTableData)data );
    table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
    table.setPreferredScrollableViewportSize(new Dimension(500, 70));
    
    table.addMouseMotionListener(new TableMouse());

    add(header.getType(), new JScrollPane(table));
} catch(ClassCastException e) {}

try {
    /***************
    * image viewer *
    ***************/
    if(data.blockCount() >0) {
        FitsImageViewer viewer = new FitsImageViewer((FitsImageData)data);
        viewer.showProgress();
        viewer.allowGammaCorrection();

        add(header.getType(),viewer);
    }
} catch(ClassCastException e) {}

add("Header", scroll);

} // end of constructor

/**********************************************************************
* Inner class for handling mouse events in a table.
**********************************************************************/
private class TableMouse extends MouseMotionAdapter {

int last_row;

TableMouse() {
    last_row=-1;
}


/********************************************************************
* Responds to movement of the mouse  by resetting the tooltip to indicate
* row of the table under the cursor.
********************************************************************/
public void mouseMoved(MouseEvent e) {

    JTable table = (JTable)e.getSource();
    int row = table.rowAtPoint(e.getPoint()) + 1; // convert to FITS style

    if(row != last_row) {
        table.setToolTipText("row "+row);
        last_row=row;
    }

  //  System.out.println("row="+row);
  
} // end of MouseMoved method

}


} // end of HDUDisplay class
