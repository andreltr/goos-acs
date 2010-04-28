/*
 * "@(#) $Id: irisCCDGUIMain.cpp,v 1.9  2009/12/04 14:33:21  mparra Exp $"
 *
 * $Log: irisCCDGUIMain.cpp,v $
 * Revision 1.9  2009/12/04 14:33:21  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.8  2005/02/02 14:45:38  tjuerges
 * - Added functionality: displaying of every nth frame is possible.
 *
 * Revision 1.7  2005/01/27 17:32:33  tjuerges
 * - Improvements for the GUI in connection with irisGuide and simulation mode.
 *
 * Revision 1.6  2005/01/24 10:39:59  tjuerges
 * - Code cleanup. Removed some header files and one unused variable.
 *
 * Revision 1.5  2004/12/28 13:43:21  tjuerges
 * - Changes needed due to strange bahaviour of SimpleClient. No two different connections to the same component from one SimpleCLient are possible.
 *
 * Revision 1.4  2004/11/02 13:20:47  tjuerges
 * - Datenpfad wird nicht mehr im Empf�nger gesetzt, sondern vom GUI selbst.
 *
 * Revision 1.2  2004/09/22 14:16:35  tjuerges
 * - F�r Simulation backgroundNoise und readoutNoise hinzugef�gt, rmsNoise entfernt.
 * - GUI speichert FITS auf Verlangen.
 * - GUI startet externes DS9 und beendet es.
 *
 * Revision 1.1  2004/08/08 18:18:25  tjuerges
 * - irisCCDClient entschlackt.
 * - irisCCDGUI hinzujgef�gt.
 * - Aufr�umarbeiten in der Komponente.
 *
 *
 */

#include <irisCCDGUI.h>
#include <irisCCDGUIEventLoop.h>
#include <irisCCDGUISaveDataToDisk.h>
#include <qapplication.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <maciSimpleClient.h>

maci::SimpleClient* sc;
irisCCD::CCD_var camera;
eventLoop* myEventLoop;
SaveDataToDisk* mySaveDataToDisk;

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  sc = new maci::SimpleClient;
  myEventLoop = new eventLoop;
  myEventLoop->setSimpleClient(sc);

  mySaveDataToDisk = new SaveDataToDisk;
  mySaveDataToDisk->setSimpleClient(sc);

  try
  {
    /**
     * Create the instance of Client and Init() it.
     */
    if (sc->init(qApp->argc(), qApp->argv()) == 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCCDGUI::main: Cannot init client."));
      delete sc;
      return -1;
    }

    if (sc->login() == 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCCDGUI::main: Cannot login."));
      delete sc;
      return -1;
    }
  }
  catch (...)
  {
    ACS_SHORT_LOG((LM_ERROR, "irisCCDGUI::main: Exception in init!"));
    delete sc;
    return -1;
  }

  irisCCDGUI* w = new irisCCDGUI;
  a.setMainWidget(w);

  myEventLoop->start();
  QObject::connect(w,SIGNAL(activate_saveToDisk(bool)),mySaveDataToDisk,SLOT(activate(bool)));
  QObject::connect(w,SIGNAL(enable_saveToDisk(bool)),mySaveDataToDisk,SLOT(enable_save(bool)));
  QObject::connect(w,SIGNAL(set_camera_name(const QString&)),mySaveDataToDisk,SLOT(set_cameraName(const QString&)));
  QObject::connect(w,SIGNAL(set_path_name(const QString&)),mySaveDataToDisk,SLOT(set_pathName(const QString&)));
  QObject::connect(w->DeleteImage,SIGNAL(clicked(void)),mySaveDataToDisk,SLOT(delete_image(void)));
  QObject::connect(w,SIGNAL(save_last_image(void)),mySaveDataToDisk,SLOT(save_last(void)));
  QObject::connect(w->DisplayNthFrame,SIGNAL(valueChanged(int)),mySaveDataToDisk,SLOT(set_display_nth_frame(int)));

  w->show();

  a.exec();
  sc->logout();
  ACS_SHORT_LOG((LM_INFO, "irisCCDGUI: Waiting 5s (max.) for the event loop to finish."));
  myEventLoop->stop();
  myEventLoop->wait();
  delete myEventLoop;

  delete mySaveDataToDisk;

  delete w;
  return 0;
}
