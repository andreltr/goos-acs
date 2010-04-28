/****************************************************************************
 ** ui.h extension file, included from the uic-generated form implementation.
 **
 ** If you wish to add, delete or rename functions or slots use
 ** Qt Designer which will update this file, preserving your code. Create an
 ** init() function in place of a constructor, and a destroy() function in
 ** place of a destructor.
 *****************************************************************************/
/*
 * "@(#) $Id: irisCCDGUI.ui.h,v 1.37  2009/12/03 13:42:45  mparra Exp $"
 *
 * $Log: irisCCDGUI.ui.h,v $
 * Revision 1.37  2009/12/03 13:42:45  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.36  2005/03/09 14:35:25  tjuerges
 * - Added component status.
 *
 * Revision 1.35  2005/02/14 13:22:47  tjuerges
 * - Setting number of simulated stars to correct value when stars have been loaded from file.
 *
 * Revision 1.34  2005/02/11 14:48:07  tjuerges
 * - Added possibility to pass centre of simulated field rotation.
 *
 * Revision 1.33  2005/02/02 16:49:51  tjuerges
 * - Added enabling and disabling of LoadRegion and SaveRegion buttons.
 *
 * Revision 1.32  2005/02/02 14:45:38  tjuerges
 * - Added functionality: displaying of every nth frame is possible.
 *
 * Revision 1.31  2005/02/02 09:30:27  tjuerges
 * - Removed debug stuff for DS9 startup.
 *
 * Revision 1.30  2005/02/01 18:26:21  tjuerges
 * - Removed some unnecessary code in load_star_positions.
 *
 * Revision 1.29  2005/02/01 17:11:30  tjuerges
 * - Added Bash script to start DS9. This enables dedicated displaying of images.
 *
 * Revision 1.28  2005/01/31 17:32:18  tjuerges
 * - Fixed error in string build for ds9 process. :(
 *
 * Revision 1.27  2005/01/31 17:17:33  tjuerges
 * - Added a -title option to ds9 process. This enables ds9 do distinguish between different clients which want to show images.
 *
 * Revision 1.26  2005/01/31 09:20:12  tjuerges
 * - Added check if cb!=0 before deleting it.
 *
 * Revision 1.25  2005/01/27 12:13:37  tjuerges
 * - As simulation stars are loaded, feed the data directly into irisCCD component.
 *
 * Revision 1.24  2005/01/26 11:48:14  tjuerges
 * simulationFieldRotation should point to camera->simulationFieldRotation not to camera->simulationFwhmX. :-(
 *
 * Revision 1.23  2005/01/25 17:20:48  tjuerges
 * - Added simulationFieldRotation to simulated CCD camera.
 *
 * Revision 1.22  2005/01/24 15:26:17  tjuerges
 * - Disabled Load and SaveButton on startup by default.
 *
 * Revision 1.21  2005/01/24 12:14:26  tjuerges
 * - Changed error message in an alert dialog.
 *
 * Revision 1.20  2005/01/24 10:39:59  tjuerges
 * - Code cleanup. Removed some header files and one unused variable.
 *
 * Revision 1.19  2005/01/21 13:37:14  tjuerges
 * - Added loading and saving of simulation stars and field rotation.
 *
 * Revision 1.18  2005/01/20 16:09:54  tjuerges
 * - Replaced std::make_pair by ctor std::pair<T,T>.
 *
 * Revision 1.17  2005/01/20 10:50:34  tjuerges
 * - When simulation is active, fill out amplitude with a default value of 32767 when one of the two coordinates is entered.
 *
 * Revision 1.16  2005/01/19 16:41:09  tjuerges
 * - Added possibility of field rotation in CCD camera simulation mode.
 *
 * Revision 1.15  2005/01/18 15:00:36  tjuerges
 * - Changed irisCamera-Simulator to enable the possibility of many simulated stars. This change has to be made in irisCCD and irisCCDGUI, too.
 *
 * Revision 1.14  2004/12/28 17:31:11  tjuerges
 * - Added #ifdefs for developers not using the IRIS software. Say make -DNO_IRIS_USAGE to make the package compile without other iris ACS components.
 *
 * Revision 1.13  2004/12/28 13:43:21  tjuerges
 * - Changes needed due to strange bahaviour of SimpleClient. No two different connections to the same component from one SimpleCLient are possible.
 *
 * Revision 1.12  2004/12/21 18:42:26  tjuerges
 * - Added ACE_OS::sleep when mirroring coordinates to give CCD camera thread enough time to fetch new coordinates before restoring the original coordinates.
 * - Moved check for active camera in front of switch statement in off().
 *
 * Revision 1.11  2004/12/10 17:03:38  tjuerges
 * - Replaced QMessageBox::information by QMessageBox::warning.
 *
 * Revision 1.10  2004/11/30 12:27:57  tjuerges
 * - Removed start and stop container buttons. Did not work.
 *
 * Revision 1.9  2004/11/25 17:52:10  tjuerges
 * - Added saving of MCU, M1 and M2 positions.
 *
 * Revision 1.8  2004/11/23 19:24:48  tjuerges
 * *** empty log message ***
 *
 * Revision 1.7  2004/11/02 13:20:47  tjuerges
 * - Datenpfad wird nicht mehr im Empf�nger gesetzt, sondern vom GUI selbst.
 *
 * Revision 1.4  2004/09/22 14:16:35  tjuerges
 * - F�r Simulation backgroundNoise und readoutNoise hinzugef�gt, rmsNoise entfernt.
 * - GUI speichert FITS auf Verlangen.
 * - GUI startet externes DS9 und beendet es.
 *
 * Revision 1.3  2004/08/17 09:18:45  tjuerges
 * - Verbesserungen am GUI.
 *
 * Revision 1.2  2004/08/09 00:03:17  rlemke
 * - Kleine Unpaesslichkeiten im GUI behoben.
 *
 * Revision 1.1  2004/08/08 18:18:25  tjuerges
 * - irisCCDClient entschlackt.
 * - irisCCDGUI hinzujgef�gt.
 * - Aufr�umarbeiten in der Komponente.
 *
 *
 */

void irisCCDGUI::init()
{
  ds9 = 0;
  myClient = 0;
  monitor_componentStatus = 0;
  camera = irisCCD::CCD::_nil();
  cb = 0;
  set_cameraName(CCDCamera->currentItem());
  camname = "NONE";
  pathname = "";
  componentStatus_changed(9999);
}

void irisCCDGUI::destroy()
{
  disconnectCCD();
}

void irisCCDGUI::set_cameraName(int v)
{
  switch (v)
  {
  case 0:
    camname = "CCD_FLI";
    Connect->setEnabled(true);
    break;
  case 1:
    camname = "CCD_Simulator";
    Connect->setEnabled(true);
    break;
  case 2:
    camname = "CCD_ST9";
    Connect->setEnabled(true);
    break;
  case 3:
    camname = "CCD_STL";
    Connect->setEnabled(true);
    break;
  case 4:
    camname = "CCD_IRIS";
    Connect->setEnabled(true);
    break;
  case 5:
  default:
    camname = "NONE";
    Connect->setEnabled(false);
    break;
  }
}

void irisCCDGUI::on(void)
{
  if (!CORBA::is_nil(camera.in()))
  {
    camera->on(cbvar.in(), cbd);
    wait_for_callback();

    xStart = camera->xStart();
    yStart = camera->yStart();
    xEnd = camera->xEnd();
    yEnd = camera->yEnd();
    darkFrame = camera->darkFrame();
    exposureTime = camera->exposureTime();
    filterName = camera->filterName();
    cameraName = camera->cameraName();
    telescopeName = camera->telescopeName();
    focalLength = camera->focalLength();
    observerName = camera->observerName();
    objectName = camera->objectName();
    commandedCCDTemperature = camera->commandedCCDTemperature();
    exposureSequence = camera->exposureSequence();
    numberOfExposuresInSequence = camera->numberOfExposuresInSequence();
    waitTimeBetweenExposuresInSequence = camera->waitTimeBetweenExposuresInSequence();
    numberOfFlushes = camera->numberOfFlushes();
    simulationX = camera->simulationX();
    simulationY = camera->simulationY();
    simulationFieldRotation = camera->simulationFieldRotation();
    simulationRotationCentreX = camera->simulationRotationCentreX();
    simulationRotationCentreY = camera->simulationRotationCentreY();
    simulationFwhmX = camera->simulationFwhmX();
    simulationFwhmY = camera->simulationFwhmY();
    simulationAmplitude = camera->simulationAmplitude();
    simulationNoise = camera->simulationNoise();
    simulationBackgroundNoise = camera->simulationBackgroundNoise();
    simulationReadoutNoise = camera->simulationReadoutNoise();

    // Enable most but buttons, but On button.
    ExposureTime->setEnabled(true);
    Type->setEnabled(true);
    StartX->setEnabled(true);
    StartY->setEnabled(true);
    Width->setEnabled(true);
    Height->setEnabled(true);
    FullResolution->setEnabled(true);
    Mirror->setEnabled(true);
    Temp->setEnabled(true);
    ExposureSequence->setEnabled(true);
    NumberFlushes->setEnabled(true);

    Observer->setEnabled(true);
    Object->setEnabled(true);
    TelescopeName->setEnabled(true);
    FocalLength->setEnabled(true);
    Filter->setEnabled(true);

    StartDS9Button->setEnabled(true);
    StopDS9Button->setEnabled(true);
    DisplayNthFrame->setEnabled(true);
    LoadRegions->setEnabled(true);
    SaveRegions->setEnabled(true);

    CCDCamera->setEnabled(false);
    On->setEnabled(false);
    Off->setEnabled(true);
    Reset->setEnabled(true);
    Start->setEnabled(true);
    Stop->setEnabled(true);
    SaveImage->setEnabled(true);
    DeleteImage->setEnabled(true);

    StartX->setRange(xStart->min_value(), xStart->max_value());
    StartY->setRange(yStart->min_value(), yStart->max_value());
    Width->setRange(xEnd->max_value() - xStart->max_value(), xEnd->max_value()
        - xStart->min_value() + 1);
    Height->setRange(yEnd->max_value() - yStart->max_value(), yEnd->max_value()
        - yStart->min_value() + 1);
    ExposureTime->setRange(exposureTime->min_value(), exposureTime->max_value());
    Temp->setRange(commandedCCDTemperature->min_value(), commandedCCDTemperature->max_value());
    WaitTime->setRange(0.0, 9999.9);
    NumberOfExposures->setRange(numberOfExposuresInSequence->min_value(),
        numberOfExposuresInSequence->max_value());
    NumberFlushes->setRange(numberOfFlushes->min_value(), numberOfFlushes->max_value());
    CCDCamera->setCurrentItem(1);
    StartX->setValue(xStart->get_sync(completion.out()));
    StartY->setValue(yStart->get_sync(completion.out()));
    long dummy1(xEnd->get_sync(completion.out()));
    long dummy2(xStart->get_sync(completion.out()));
#ifndef NO_IRIS_SIMULATOR
    dummy1 = 2047;
    ACS_SHORT_LOG((LM_ERROR, "irisCCDGUI::on: dummy1 %d dummy2  %d", dummy1, dummy2));
#endif
    Width->setValue(dummy1 - dummy2 + 1);
    dummy1 = yEnd->get_sync(completion.out());
    dummy2 = yStart->get_sync(completion.out());
#ifndef NO_IRIS_SIMULATOR
    dummy1 = 1023;
    ACS_SHORT_LOG((LM_ERROR, "irisCCDGUI::on: dummy1 %d dummy2  %d", dummy1, dummy2));
#endif
    Height->setValue(dummy1 - dummy2 + 1);
    FocalLength->setValue(focalLength->get_sync(completion.out()));
    ExposureTime->setValue(exposureTime->get_sync(completion.out()));
    Temp->setValue(commandedCCDTemperature->get_sync(completion.out()));
    set_doSequence(ExposureSequence->isChecked());
    setCaption(QString("irisCCDGUI %1").arg(camname.c_str()));

    if (camname == "CCD_Simulator")
    {
      NumberOfStars->setEnabled(true);
      LoadButton->setEnabled(true);
      SaveButton->setEnabled(true);
      StarTable->setEnabled(true);
      fwhmX->setEnabled(true);
      fwhmY->setEnabled(true);
      FieldRotation->setEnabled(true);
      FieldRotationCentreX->setEnabled(true);
      FieldRotationCentreY->setEnabled(true);
      n_onoff->setEnabled(true);
      background->setEnabled(true);
      readout->setEnabled(true);

      fwhmX->setRange(simulationFwhmX->min_value(), simulationFwhmX->max_value());
      fwhmY->setRange(simulationFwhmY->min_value(), simulationFwhmY->max_value());
      background->setRange(simulationBackgroundNoise->min_value(),
          simulationBackgroundNoise->max_value());
      readout->setRange(simulationReadoutNoise->min_value(), simulationReadoutNoise->max_value());

      fwhmX->setValue(simulationFwhmX->get_sync(completion.out()));
      fwhmY->setValue(simulationFwhmY->get_sync(completion.out()));
      background->setValue(simulationBackgroundNoise->get_sync(completion.out()));
      readout->setValue(simulationReadoutNoise->get_sync(completion.out()));

      StarTable->setText(0, 0, QString("%1").arg(Width->value() / 2));
      StarTable->setText(0, 1, QString("%1").arg(Height->value() / 2));
      StarTable->setText(0, 2, QString("32767"));
    }
    else
    {
      NumberOfStars->setEnabled(false);
      StarTable->setEnabled(false);
      fwhmX->setEnabled(false);
      fwhmY->setEnabled(false);
      FieldRotation->setEnabled(false);
      n_onoff->setEnabled(false);
      background->setEnabled(false);
      readout->setEnabled(false);
    }

    setup_data_path();
    emit(set_camera_name(QString(camname.c_str())));
    emit(set_path_name(QString(pathname.c_str())));
    emit(activate_saveToDisk(true));
    startDS9();
  }
}

void irisCCDGUI::off(void)
{
  if (!CORBA::is_nil(camera.in()))
  {
    int ret(QMessageBox::warning(this, QString("irisCCDGUI %1").arg(camname.c_str()), QString(
        "Do you really want to switch the CCD camera off?"), QMessageBox::Yes, QMessageBox::No,
        QMessageBox::NoButton));
    switch (ret)
    {
    case QMessageBox::Yes:
      emit(activate_saveToDisk(false));
      camera->off(cbvar.in(), cbd);
      wait_for_callback();

      // Disable most but buttons.
      ExposureTime->setEnabled(false);
      Type->setEnabled(false);
      StartX->setEnabled(false);
      StartY->setEnabled(false);
      Width->setEnabled(false);
      Height->setEnabled(false);
      FullResolution->setEnabled(false);
      Temp->setEnabled(false);
      set_doSequence(false);

      Observer->setEnabled(false);
      Object->setEnabled(false);
      TelescopeName->setEnabled(false);
      FocalLength->setEnabled(false);
      Filter->setEnabled(false);

      StartDS9Button->setEnabled(false);
      StopDS9Button->setEnabled(false);
      DisplayNthFrame->setEnabled(false);
      LoadRegions->setEnabled(false);
      SaveRegions->setEnabled(false);

      CCDCamera->setEnabled(true);
      Off->setEnabled(false);
      On->setEnabled(true);
      Reset->setEnabled(false);
      Start->setEnabled(false);
      Stop->setEnabled(false);
      DeleteImage->setEnabled(false);
      SaveImage->setEnabled(false);
      SaveLastImage->setEnabled(false);

      // Disable CCD_Simulator buttons.
      NumberOfStars->setEnabled(false);
      LoadButton->setEnabled(true);
      SaveButton->setEnabled(true);
      StarTable->setEnabled(false);
      fwhmX->setEnabled(false);
      fwhmY->setEnabled(false);
      FieldRotation->setEnabled(false);
      FieldRotationCentreX->setEnabled(false);
      FieldRotationCentreY->setEnabled(false);
      n_onoff->setEnabled(false);
      background->setEnabled(false);
      readout->setEnabled(false);
      stopDS9();
      break;
    default:
      break;
    };
  }
}

void irisCCDGUI::reset(void)
{
  if (!CORBA::is_nil(camera.in()))
  {
    int ret = QMessageBox::warning(this, QString("irisCCDGUI %1").arg(camname.c_str()), QString(
        "Do you really want to reset the CCD camera?"), QMessageBox::Yes, QMessageBox::No,
        QMessageBox::NoButton);

    switch (ret)
    {
    case QMessageBox::Yes:
      camera->resetCamera(cbvar.in(), cbd);
      wait_for_callback();
      break;
    default:
      break;
    };
  }
}

void irisCCDGUI::start(void)
{
  if (!CORBA::is_nil(camera.in()))
  {
    if (camname == "CCD_Simulator")
    {
      const long size(StarTable->numRows());

      ACS::doubleSeq_var _amplitude = new ACS::doubleSeq;
      ACS::doubleSeq_var _simX = new ACS::doubleSeq;
      ACS::doubleSeq_var _simY = new ACS::doubleSeq;

      _simX->length(size);
      _simY->length(size);
      _amplitude->length(size);

      for (long i(0L); i < size; ++i)
      {
        _simX[i] = StarTable->text(i, 0).toDouble();
        _simY[i] = StarTable->text(i, 1).toDouble();
        _amplitude[i] = StarTable->text(i, 2).toDouble();
      }
      simulationX->set_sync(_simX.in());
      simulationY->set_sync(_simY.in());
      simulationAmplitude->set_sync(_amplitude.in());
    }

    if ((Mirror->isChecked() == true) && (FullResolution->isChecked() == false))
    {
      long x0(xStart->max_value() - xStart->get_sync(completion.out()) - Width->value() - 1);
      long y0(yStart->max_value() - yStart->get_sync(completion.out()) - Height->value() - 1);
      long x1(x0 + Width->value() - 1);
      long y1(y0 + Height->value() - 1);

      xStart->set_sync(x0);
      yStart->set_sync(y0);
      xEnd->set_sync(x1);
      yEnd->set_sync(y1);

      camera->startExposure(cbvar.in(), cbd);
      ACE_OS::sleep(5);

      xStart->set_sync(StartX->value());
      yStart->set_sync(StartY->value());
      xEnd->set_sync(StartX->value() + Width->value() - 1);
      yEnd->set_sync(StartY->value() + Height->value() - 1);
    }
    else
    {
      camera->startExposure(cbvar.in(), cbd);
    }
    wait_for_callback();
    SaveLastImage->setEnabled(true);
  }
}

void irisCCDGUI::stop(void)
{
  if (!CORBA::is_nil(camera.in()))
  {
    camera->stopExposure(cbvar.in(), cbd);
    wait_for_callback();
  }
}

void irisCCDGUI::setup_monitors(void)
{
  if (CORBA::is_nil(camera.in()))
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCDGUI::setup_monitors: Cannot create monitors. Component is not active."));
    return;
  }

  monitor_componentStatus=new myMonitorEnum(irisStatus,status,irisCCDGUI)(std::string("Current component status"),&irisCCDGUI::componentStatus_changed,this);
  if (!monitor_componentStatus->create_monitor(camera->componentStatus(), 0.0, 1, true))
  {
    delete monitor_componentStatus;
    monitor_componentStatus = 0;
  }
}

void irisCCDGUI::componentStatus_changed(const ACSpattern& value)
{
  componentStatusDisplay->setValue(value);
}

void irisCCDGUI::destroy_monitors(void)
{
  if (monitor_componentStatus)
  {
    delete monitor_componentStatus;
    monitor_componentStatus = 0;
  }
}

void irisCCDGUI::set_size(int x, int y, int w, int h)
{
  if (!CORBA::is_nil(camera.in()))
  {
    if (x > xStart->max_value())
    {
      StartX->setValue(xStart->max_value());
      return;
    }

    if (y > yStart->max_value())
    {
      StartY->setValue(yStart->max_value());
      return;
    }

    if ((x + w - 1) > xEnd->max_value())
    {
      Width->setValue(xEnd->max_value() - StartX->value() + 1);
      return;
    }

    if ((y + h - 1) > yEnd->max_value())
    {
      Height->setValue(yEnd->max_value() - StartY->value() + 1);
      return;
    }

    xStart->set_sync(x);
    yStart->set_sync(y);
    xEnd->set_sync(x + w - 1);
    yEnd->set_sync(y + h - 1);
  }
}

void irisCCDGUI::set_startX(int v)
{
  set_size(v, StartY->value(), Width->value(), Height->value());
}

void irisCCDGUI::set_startY(int v)
{
  set_size(StartX->value(), v, Width->value(), Height->value());
}

void irisCCDGUI::set_width(int v)
{
  set_size(StartX->value(), StartY->value(), v, Height->value());
}

void irisCCDGUI::set_height(int v)
{
  set_size(StartX->value(), StartY->value(), Width->value(), v);
}

void irisCCDGUI::set_darkFrame(int df)
{
  if (!CORBA::is_nil(camera.in()))
  {
    switch (df)
    {
    case 0:
    case 1:
      darkFrame->set_sync(0);
      break;
    case 2:
    case 3:
    default:
      darkFrame->set_sync(1);
      break;
    }
  }
}

void irisCCDGUI::set_doSequence(bool b)
{
  if (!CORBA::is_nil(camera.in()))
  {
    exposureSequence->set_sync((b ? 1L : 0L));
    NumberOfExposures->setEnabled(b);
    WaitTime->setEnabled(b);

    if (b == true)
    {
      numberOfExposuresInSequence->set_sync(NumberOfExposures->value());
      waitTimeBetweenExposuresInSequence->set_sync(WaitTime->value());
    }
  }
}

void irisCCDGUI::set_numberOfExposuresInSequence(int n)
{
  if (!CORBA::is_nil(camera.in()))
  {
    numberOfExposuresInSequence->set_sync(n);
  }
}

void irisCCDGUI::set_filterName(const QString& v)
{
  if (!CORBA::is_nil(camera.in()))
  {
    filterName->set_sync(v.latin1());
  }
}

void irisCCDGUI::set_observerName(const QString& v)
{
  if (!CORBA::is_nil(camera.in()))
  {
    observerName->set_sync(v.latin1());
  }
}

void irisCCDGUI::set_objectName(const QString& v)
{
  if (!CORBA::is_nil(camera.in()))
  {
    objectName->set_sync(v.latin1());
  }
}

void irisCCDGUI::set_telescopeName(const QString& v)
{
  if (!CORBA::is_nil(camera.in()))
  {
    telescopeName->set_sync(v.latin1());
  }
}

void irisCCDGUI::set_fullResolution(bool b)
{
  if (b == true)
  {
    Mirror->setEnabled(false);
    old_x = StartX->value();
    old_y = StartY->value();
    old_w = Width->value();
    old_h = Height->value();
    StartX->setValue(xStart->min_value());
    StartY->setValue(yStart->min_value());
    Width->setValue(xEnd->max_value() - xStart->min_value() + 1);
    Height->setValue(yEnd->max_value() - yStart->min_value() + 1);
  }
  else
  {
    Mirror->setEnabled(true);
    StartX->setValue(old_x);
    StartY->setValue(old_y);
    Width->setValue(old_w);
    Height->setValue(old_h);
  }
}

void irisCCDGUI::set_flushes(int v)
{
  if (!CORBA::is_nil(camera.in()))
  {
    numberOfFlushes->set_sync(v);
  }
}

void irisCCDGUI::set_noise(bool b)
{
  if (!CORBA::is_nil(camera.in()))
  {
    simulationNoise->set_sync((b ? 1L : 0L));
  }
}

void irisCCDGUI::set_exposureTime(double t)
{
  if (!CORBA::is_nil(camera.in()))
  {
    exposureTime->set_sync(t);
  }
}

void irisCCDGUI::set_waitTimeInSequence(double t)
{
  if (!CORBA::is_nil(camera.in()))
  {
    waitTimeBetweenExposuresInSequence->set_sync(t);
  }
}

void irisCCDGUI::set_focalLength(double v)
{
  if (!CORBA::is_nil(camera.in()))
  {
    focalLength->set_sync(v);
  }
}

void irisCCDGUI::set_commandedTemperature(double t)
{
  if (!CORBA::is_nil(camera.in()))
  {
    commandedCCDTemperature->set_sync(t);
    camera->setTemperature(cbvar.in(), cbd);
  }
}

void irisCCDGUI::set_simulationFwhmY(double y)
{
  if (!CORBA::is_nil(camera.in()))
  {
    simulationFwhmY->set_sync(y);
  }
}

void irisCCDGUI::set_simulationFwhmX(double x)
{
  if (!CORBA::is_nil(camera.in()))
  {
    simulationFwhmX->set_sync(x);
  }
}

void irisCCDGUI::set_background(double n)
{
  if (!CORBA::is_nil(camera.in()))
  {
    simulationBackgroundNoise->set_sync(n);
  }
}

void irisCCDGUI::set_readout(double n)
{
  if (!CORBA::is_nil(camera.in()))
  {
    simulationReadoutNoise->set_sync(n);
  }
}

void irisCCDGUI::wait_for_callback(void)
{
  timespec wait_time =
  { static_cast<time_t> (0), ACE_ONE_SECOND_IN_NSECS / 10000L };
  while (!cb->is_done())
  {
    ACE_OS::nanosleep(&wait_time);
  };
}

void irisCCDGUI::byebye()
{
  disconnectCCD();
  /*
   * Must check if off was successful.
   * If successful, the start exposure button is disabled.
   */
  if (Start->isEnabled() == false)
  {
    close();
  }
}

void irisCCDGUI::disconnectCCD()
{
  off();
  destroy_monitors();
  /*
   * Must check if off was successful.
   * If successful, the start exposure button is disabled.
   */
  if (Start->isEnabled() == false)
  {
    if (myClient)
    {
      delete myClient;
    }
    myClient = 0;
    camera = irisCCD::CCD::_nil();

    if (cb)
    {
      delete cb;
    }
    cb = 0;

    set_doSequence(false);
    Connect->setEnabled(true);
    Disconnect->setEnabled(false);
    On->setEnabled(false);
    Off->setEnabled(false);
    CCDCamera->setEnabled(true);
    CCDCamera->setCurrentItem(4);
    camname = "NONE";
  }
}

void irisCCDGUI::connectCCD()
{
  if (camname == "NONE")
  {
    return;
  }

  myClient = new myComponentClient<irisCCD::CCD> (camname, sc);

  if (myClient->connect() == false)
  {
    delete myClient;
    myClient = 0;
    QMessageBox::critical(this, QString("irisCCDGUI %1").arg(camname.c_str()), QString(
        "Unable to connect to the wanted CCD component %1.\n"
          "Start the component container or,\n"
          "if the component is already running,\n\n"
          "- check the camera hardware,\n"
          "- choose another camera and try again.\n").arg(camname.c_str()));
  }
  else
  {
    camera = myClient->get_object();

    setup_monitors();

    cb = new myCBvoid;
    cbvar = cb->_this();

    Connect->setEnabled(false);
    Disconnect->setEnabled(true);
    On->setEnabled(true);
    CCDCamera->setEnabled(false);
  }
}

void irisCCDGUI::save_image(bool on)
{
  emit(enable_saveToDisk(on));
}

void irisCCDGUI::save_last_file()
{
  emit( save_last_image());
}

void irisCCDGUI::startDS9()
{
  stopDS9();

  // Startup a DS9 FITS display.
  QStringList s;
  s << "start_ds9.sh";
  QString t("-title ");
  t += QString(camname.c_str());
  s << t;
  ds9 = new QProcess(s, this, QString("irisCCDGUI_imagedisplay_process"));
  ds9->start();
}

void irisCCDGUI::stopDS9()
{
  if (ds9)
  {
    std::string quit_command("xpaset -p ");
    quit_command += camname;
    quit_command += " exit";
    ACE_OS::system(quit_command.c_str());
    ds9->tryTerminate();
    delete ds9;
    ds9 = 0;
  }
}

void irisCCDGUI::setup_data_path(void)
{
  // Where do I want to save FITS files to...
  char* irisdata(ACE_OS::getenv("IRISDATA"));
  if (irisdata != NULL)
  {
    pathname = irisdata;
    pathname += "/CCD";
    QDir d(pathname.c_str());
    if (!d.exists())
    {
      if (!d.mkdir(QString(pathname.c_str())))
      {
        QMessageBox::warning(
            this,
            QString("irisCCDGUI %1").arg(camname.c_str()),
            QString(
                "Could not create CCD data directory:\n%1\nThe current directory will be used instead.").arg(
                QString(pathname.c_str())), QMessageBox::Ok, QMessageBox::NoButton);
        pathname = ".";
      }
    }
  }
  else
  {
    pathname = ".";
  }
  pathname += '/';
}

void irisCCDGUI::number_changed(int v)
{
  const int old_numberOfRows(StarTable->numRows());

  StarTable->setNumRows(v);

  if (old_numberOfRows < v)
  {
    v -= old_numberOfRows;
    for (int i(0); i < v; ++i)
    {
      StarTable->setText(old_numberOfRows + i, 0, "0.0");
      StarTable->setText(old_numberOfRows + i, 1, "0.0");
      StarTable->setText(old_numberOfRows + i, 2, "0.0");
    }
  }
}

void irisCCDGUI::simulation_star_value_changed(int row, int column)
{
  if ((StarTable->text(row, 2) == QString::null) && (column != 2))
  {
    StarTable->setText(row, 2, QString("32767"));
  }

  bool ok(false);
  StarTable->text(row, column).toDouble(&ok);
  if (ok == false)
  {
    StarTable->setText(row, column, QString::null);
  }
}

void irisCCDGUI::load_star_positions()
{
  QFileDialog* file_dialog = new QFileDialog(QString(pathname.c_str()), QString(
      "Star positions (*.stars *.Stars *.STARS)"), this, "Load star positions", true);
  file_dialog->setMode(QFileDialog::ExistingFile);
  file_dialog->setViewMode(QFileDialog::Detail);
  if (file_dialog->exec() == QDialog::Accepted)
  {
    QStringList fileNames(file_dialog->selectedFiles());
    QString name;
    if (fileNames.empty())
    {
      name = file_dialog->selectedFile();
    }
    else
    {
      name = (*(fileNames.begin()));
    }

    QString postfix(".stars");
    const bool case_sensitive(false);
    if (name.find(postfix, 0, case_sensitive) == -1)
    {
      name += ".stars";
    }

    QFile file(name);
    if (file.open(IO_ReadOnly))
    {
      QTextStream stream(&file);

      // This vector keeps the simulated star position and amplitude.
      std::vector<std::pair<std::pair<double, double>, double> > stars(0);
      // This container keeps the data of one simulated star.
      std::pair<std::pair<double, double>, double> data;

      QString line, qualifier;
      while (!stream.eof())
      {
        line = stream.readLine();
        qualifier = line.section('=', 0, 0);
        if (qualifier == "Rotation")
        {
          FieldRotation->setValue(line.section('=', 1, 1).toDouble());
        }
        else if (qualifier == "RotationCentre")
        {
          FieldRotationCentreX->setValue(
              line.section(',', 0, 0).replace("RotationCentre=", "").toDouble());
          FieldRotationCentreY->setValue(line.section(',', 1, 1).toDouble());
        }
        else if (qualifier == "Star")
        {
          data.first.first = line.section(',', 0, 0).replace("Star=", "").toDouble();
          data.first.second = line.section(',', 1, 1).toDouble();
          data.second = line.section(',', 2, 2).toDouble();
          stars.push_back(data);
        }
        else
        {
          ACS_SHORT_LOG(
              (LM_INFO, "irisCCDGUI::load_star_position: ignoring line with wrong content: %s", line.latin1()));
        }
      }
      file.close();

      int row(0);
      NumberOfStars->setValue(static_cast<int> (stars.size()));
      number_changed(stars.size());
      for (std::vector<std::pair<std::pair<double, double>, double> >::iterator iter(stars.begin()); iter
          != stars.end(); ++iter, ++row)
      {
        StarTable->setText(row, 0, QString("%1").arg((*iter).first.first));
        StarTable->setText(row, 1, QString("%1").arg((*iter).first.second));
        StarTable->setText(row, 2, QString("%1").arg((*iter).second));
      }

      if (!CORBA::is_nil(camera.in()))
      {
        ACS::doubleSeq_var _amplitude = new ACS::doubleSeq;
        ACS::doubleSeq_var _simX = new ACS::doubleSeq;
        ACS::doubleSeq_var _simY = new ACS::doubleSeq;

        _simX->length(stars.size());
        _simY->length(stars.size());
        _amplitude->length(stars.size());
        long i(0L);
        for (std::vector<std::pair<std::pair<double, double>, double> >::iterator iter(
            stars.begin()); iter != stars.end(); ++iter, ++i)
        {
          _simX[i] = (*iter).first.first;
          _simY[i] = (*iter).first.second;
          _amplitude[i] = (*iter).second;
        }
        simulationX->set_sync(_simX.in());
        simulationY->set_sync(_simY.in());
        simulationAmplitude->set_sync(_amplitude.in());
      }
    }
  }
  delete file_dialog;
}

void irisCCDGUI::save_star_positions()
{
  QFileDialog* file_dialog = new QFileDialog(QString(pathname.c_str()), QString(
      "Star positions (*.stars *.Stars *.STARS)"), this, "Save star positions", true);
  file_dialog->setMode(QFileDialog::AnyFile);
  file_dialog->setViewMode(QFileDialog::Detail);
  if (file_dialog->exec() == QDialog::Accepted)
  {
    const int rows(StarTable->numRows());
    if (rows > 0)
    {
      QString name(file_dialog->selectedFile());
      QString postfix(".stars");
      const bool case_sensitive(false);
      if (name.find(postfix, 0, case_sensitive) == -1)
      {
        name += ".stars";
      }
      QFile file(name);
      if (file.open(IO_WriteOnly))
      {
        QTextStream stream(&file);

        stream << "Rotation=" << FieldRotation->value() << "\n";
        stream << "RotationCentre=" << FieldRotationCentreX->value() << ","
            << FieldRotationCentreY->value() << "\n";

        for (int i(0); i < rows; ++i)
        {
          stream << "Star=" << StarTable->text(i, 0) << "," << StarTable->text(i, 1) << ","
              << StarTable->text(i, 2) << "\n";
        }
      }
      file.close();
    }
  }
  delete file_dialog;
}

void irisCCDGUI::set_fieldRotation(double r)
{
  if (!CORBA::is_nil(camera.in()))
  {
    simulationFieldRotation->set_sync(r);
  }
}

void irisCCDGUI::load_regions()
{
  QFileDialog* file_dialog = new QFileDialog(QString(pathname.c_str()), QString(
      "DS9 regions (*.reg)"), this, "Load regions", true);
  file_dialog->setMode(QFileDialog::ExistingFile);
  file_dialog->setViewMode(QFileDialog::Detail);
  if (file_dialog->exec() == QDialog::Accepted)
  {
    QStringList fileNames(file_dialog->selectedFiles());
    QString name;
    if (fileNames.empty())
    {
      name = file_dialog->selectedFile();
    }
    else
    {
      name = (*(fileNames.begin()));
    }

    QString postfix(".reg");
    if (name.find(postfix, 0, false) == -1)
    {
      name += ".reg";
    }

    std::string xpaset_command("xpaset -p ");
    xpaset_command += camname;
    xpaset_command += " regions load ";
    xpaset_command += name.latin1();
    ACE_OS::system(xpaset_command.c_str());
  }
  delete file_dialog;
}

void irisCCDGUI::save_regions()
{
  QFileDialog* file_dialog = new QFileDialog(QString(pathname.c_str()), QString(
      "DS9 regions (*.reg)"), this, "Save regions", true);
  file_dialog->setMode(QFileDialog::AnyFile);
  file_dialog->setViewMode(QFileDialog::Detail);
  if (file_dialog->exec() == QDialog::Accepted)
  {
    QString name(file_dialog->selectedFile());
    QString postfix(".reg");
    if (name.find(postfix, 0, false) == -1)
    {
      name += ".reg";
    }

    std::string xpaset_command("xpaset -p ");
    xpaset_command += camname;
    xpaset_command += " regions save ";
    xpaset_command += name.latin1();
    ACE_OS::system(xpaset_command.c_str());
  }
  delete file_dialog;
}

void irisCCDGUI::set_rotationCentreX(double x)
{
  if (!CORBA::is_nil(camera.in()))
  {
    simulationRotationCentreX->set_sync(x);
  }
}

void irisCCDGUI::set_rotationCentreY(double y)
{
  if (!CORBA::is_nil(camera.in()))
  {
    simulationRotationCentreY->set_sync(y);
  }
}
