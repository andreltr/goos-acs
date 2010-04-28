/*
 * "@(#) $Id: irisCCDImpl.cpp,v 1.13  2009/12/03 16:00:22  mparra Exp $"
 *
 * $Log: irisCCDImpl.cpp,v $
 * Revision 1.13  2009/12/03 16:00:22  mparra
 * - Adapted to iris telescope name.
 * - Change the constructor class, from this moment it's use const ACE_CString&
 *   and maci::ContainerServices*.
 * - The SmartPropertyPointer has change the methods read and write, there is no need
 *   to  use the int& variable, so the local definition acs_error has been deleted.
 *
 * Revision 1.12  2005/03/09 14:35:01  tjuerges
 * - Added component status.
 *
 */

#include <vltPort.h>

static char *rcsId = "@(#) $Id: irisCCDImpl.cpp,v 1.13  2009/12/03 16:00:22  mparra Exp $";
static void* use_rcsId = ((void) &use_rcsId, (void *) &rcsId);

#include <baciDB.h>
#include <irisCCDImpl.h>
#include <irisCCDImplIncludes.h>
#include <irisCCDHelperFunctions.cpp>

using namespace baci;

const static int off_ACTION = 0;
const static int on_ACTION = 1;
const static int resetCamera_ACTION = 2;
const static int setTemperature_ACTION = 3;
const static int startExposure_ACTION = 4;
const static int stopExposure_ACTION = 5;
CCD::CCD(const ACE_CString& name, maci::ContainerServices* containerServices) :
  CharacteristicComponentImpl(name, containerServices), m_componentStatus_p(this),
      m_actualAirTemperature_p(this), m_actualCCDTemperature_p(this), m_cameraName_p(this),
      m_commandedCCDTemperature_p(this), m_darkFrame_p(this), m_exposureSequence_p(this),
      m_exposureTime_p(this), m_filterName_p(this), m_focalLength_p(this), m_gain_p(this),
      m_imageData_p(this), m_imageReady_p(this), m_numberOfExposuresInSequence_p(this),
      m_numberOfFlushes_p(this), m_objectName_p(this), m_observerName_p(this),
      m_simulationAmplitude_p(this), m_simulationBackgroundNoise_p(this),
      m_simulationFieldRotation_p(this), m_simulationFwhmX_p(this), m_simulationFwhmY_p(this),
      m_simulationNoise_p(this), m_simulationReadoutNoise_p(this), m_simulationRotationCentreX_p(
          this), m_simulationRotationCentreY_p(this), m_simulationX_p(this), m_simulationY_p(this),
      m_status_p(this), m_telescopeName_p(this), m_timeExposureEnd_p(this), m_timeExposureStart_p(
          this), m_waitTimeBetweenExposuresInSequence_p(this), m_xEnd_p(this),
      m_xPixelSize_p(this), m_xStart_p(this), m_yEnd_p(this), m_yPixelSize_p(this),
      m_yStart_p(this)
{
  ACS::Time time_stamp(0);

  m_componentStatus_p = new ROEnumImpl<ACS_ENUM_T(irisStatus::status), POA_irisStatus::ROstatus> (
      name + ":componentStatus", getComponent());
  m_componentStatus_p->getDevIO()->write(irisStatus::UNKNOWN, time_stamp);
  m_actualAirTemperature_p = new ROdouble(name + ":actualAirTemperature", getComponent());
  m_actualCCDTemperature_p = new ROdouble(name + ":actualCCDTemperature", getComponent());
  m_cameraName_p = new RWstring(name + ":cameraName", getComponent());
  m_commandedCCDTemperature_p = new RWdouble(name + ":commandedCCDTemperature", getComponent());
  m_darkFrame_p = new RWlong(name + ":darkFrame", getComponent());
  m_exposureSequence_p = new RWlong(name + ":exposureSequence", getComponent());
  m_exposureTime_p = new RWdouble(name + ":exposureTime", getComponent());
  m_filterName_p = new RWstring(name + ":filterName", getComponent());
  m_focalLength_p = new RWdouble(name + ":focalLength", getComponent());
  m_gain_p = new ROdouble(name + ":gain", getComponent());
  m_imageData_p = new ROlongSeq(name + ":imageData", getComponent());
  m_imageReady_p = new ROlong(name + ":imageReady", getComponent());
  m_numberOfExposuresInSequence_p = new RWlong(name + ":numberOfExposuresInSequence",
      getComponent());
  m_numberOfFlushes_p = new RWlong(name + ":numberOfFlushes", getComponent());
  m_objectName_p = new RWstring(name + ":objectName", getComponent());
  m_observerName_p = new RWstring(name + ":observerName", getComponent());
  m_simulationAmplitude_p = new RWdoubleSeq(name + ":simulationAmplitude", getComponent());
  m_simulationBackgroundNoise_p = new RWdouble(name + ":simulationBackgroundNoise", getComponent());
  m_simulationFieldRotation_p = new RWdouble(name + ":simulationFieldRotation", getComponent());
  m_simulationFwhmX_p = new RWdouble(name + ":simulationFwhmX", getComponent());
  m_simulationFwhmY_p = new RWdouble(name + ":simulationFwhmY", getComponent());
  m_simulationNoise_p = new RWlong(name + ":simulationNoise", getComponent());
  m_simulationReadoutNoise_p = new RWdouble(name + ":simulationReadoutNoise", getComponent());
  m_simulationRotationCentreX_p = new RWdouble(name + ":simulationRotationCentreX", getComponent());
  m_simulationRotationCentreY_p = new RWdouble(name + ":simulationRotationCentreY", getComponent());
  m_simulationX_p = new RWdoubleSeq(name + ":simulationX", getComponent());
  m_simulationY_p = new RWdoubleSeq(name + ":simulationY", getComponent());
  m_status_p = new ROpattern(name + ":status", getComponent());
  m_telescopeName_p = new RWstring(name + ":telescopeName", getComponent());
  m_timeExposureEnd_p = new ROstring(name + ":timeExposureEnd", getComponent());
  m_timeExposureStart_p = new ROstring(name + ":timeExposureStart", getComponent());
  m_waitTimeBetweenExposuresInSequence_p = new RWdouble(name
      + ":waitTimeBetweenExposuresInSequence", getComponent());
  m_xEnd_p = new RWlong(name + ":xEnd", getComponent());
  m_xPixelSize_p = new ROdouble(name + ":xPixelSize", getComponent());
  m_xStart_p = new RWlong(name + ":xStart", getComponent());
  m_yEnd_p = new RWlong(name + ":yEnd", getComponent());
  m_yPixelSize_p = new ROdouble(name + ":yPixelSize", getComponent());
  m_yStart_p = new RWlong(name + ":yStart", getComponent());

#include <irisCCDImplInit.cpp>
#include <irisCCDThreadInit.cpp>

  m_componentStatus_p->getDevIO()->write(irisStatus::RUNNING, time_stamp);
}

#include <irisCCDThreadImpl.cpp>

CCD::~CCD()
{
  ACS::Time time_stamp(0);

  m_componentStatus_p->getDevIO()->write(irisStatus::STOPPED, time_stamp);
  if (getComponent())
  {
    getComponent()->stopAllThreads();
    ACE_OS::sleep(2);
  }
  m_componentStatus_p->getDevIO()->write(irisStatus::UNKNOWN, time_stamp);
}

void CCD::cleanUp()
{
  if (getComponent())
  {
#include <irisCCDImplCleanUp.body>
    CharacteristicComponentImpl::cleanUp();
  }
}

/* --------------- [ Action implementator interface ] -------------- */

ActionRequest CCD::invokeAction(int function, BACIComponent *cob, const int& callbackID,
    const CBDescIn& descIn, BACIValue* value, Completion& completion, CBDescOut& descOut)
{
  switch (function)
  {
  case off_ACTION:
  {
    return offAction(cob, callbackID, descIn, value, completion, descOut);
  }
  case on_ACTION:
  {
    return onAction(cob, callbackID, descIn, value, completion, descOut);
  }
  case resetCamera_ACTION:
  {
    return resetCameraAction(cob, callbackID, descIn, value, completion, descOut);
  }
  case setTemperature_ACTION:
  {
    return setTemperatureAction(cob, callbackID, descIn, value, completion, descOut);
  }
  case startExposure_ACTION:
  {
    return startExposureAction(cob, callbackID, descIn, value, completion, descOut);
  }
  case stopExposure_ACTION:
  {
    return stopExposureAction(cob, callbackID, descIn, value, completion, descOut);
  }
  default:
  {
    return reqDestroy;
  }
  }
}

/* ------------------ [ Action implementations ] ----------------- */

ActionRequest CCD::offAction(BACIComponent* cob, const int& callbackID, const CBDescIn& descIn,
    BACIValue* value, Completion& completion, CBDescOut& descOut)
{
  completion.type = ACSErr::ACSErrTypeOK;
  completion.code = ACSErr::ACSErrOK;
  if (component_running)
  {
    ACS::Time time_stamp(0);
    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDoffAction.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::offAction: Action is not executed. Check if component is running!"));
  }
  completion.timeStamp = getTimeStamp();
  return reqInvokeDone;
}

ActionRequest CCD::onAction(BACIComponent* cob, const int& callbackID, const CBDescIn& descIn,
    BACIValue* value, Completion& completion, CBDescOut& descOut)
{
  completion.type = ACSErr::ACSErrTypeOK;
  completion.code = ACSErr::ACSErrOK;
  if (!component_running)
  {
    ACS::Time time_stamp(0);
    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDonAction.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::onAction: Action is not executed. Check if component is running!"));
  }
  completion.timeStamp = getTimeStamp();
  return reqInvokeDone;
}

ActionRequest CCD::resetCameraAction(BACIComponent* cob, const int& callbackID,
    const CBDescIn& descIn, BACIValue* value, Completion& completion, CBDescOut& descOut)
{
  completion.type = ACSErr::ACSErrTypeOK;
  completion.code = ACSErr::ACSErrOK;
  if (component_running)
  {
    ACS::Time time_stamp(0);
    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDresetCameraAction.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::resetCameraAction: Action is not executed. Check if component is running!"));
  }
  completion.timeStamp = getTimeStamp();
  return reqInvokeDone;
}

ActionRequest CCD::setTemperatureAction(BACIComponent* cob, const int& callbackID,
    const CBDescIn& descIn, BACIValue* value, Completion& completion, CBDescOut& descOut)
{
  completion.type = ACSErr::ACSErrTypeOK;
  completion.code = ACSErr::ACSErrOK;
  if (component_running)
  {
    ACS::Time time_stamp(0);
    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDsetTemperatureAction.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::setTemperatureAction: Action is not executed. Check if component is running!"));
  }
  completion.timeStamp = getTimeStamp();
  return reqInvokeDone;
}

ActionRequest CCD::startExposureAction(BACIComponent* cob, const int& callbackID,
    const CBDescIn& descIn, BACIValue* value, Completion& completion, CBDescOut& descOut)
{
  completion.type = ACSErr::ACSErrTypeOK;
  completion.code = ACSErr::ACSErrOK;
  if (component_running)
  {
    ACS::Time time_stamp(0);
    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDstartExposureAction.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::startExposureAction: Action is not executed. Check if component is running!"));
  }
  completion.timeStamp = getTimeStamp();
  return reqInvokeDone;
}

ActionRequest CCD::stopExposureAction(BACIComponent* cob, const int& callbackID,
    const CBDescIn& descIn, BACIValue* value, Completion& completion, CBDescOut& descOut)
{
  completion.type = ACSErr::ACSErrTypeOK;
  completion.code = ACSErr::ACSErrOK;
  if (component_running)
  {
    ACS::Time time_stamp(0);
    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDstopExposureAction.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::stopExposureAction: Action is not executed. Check if component is running!"));
  }
  completion.timeStamp = getTimeStamp();
  return reqInvokeDone;
}

/* ------------------ [ Functions ] ----------------- */

CORBA::Long CCD::exit_wheel() throw (CORBA::SystemException)
{
  CORBA::Long ret_value(1);

  if (component_running)
  {
    ACS::Time time_stamp(0);

    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDexit_wheelFunct.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::exit_wheel: Function is not executed. Check if component is running!"));
  }
  return ret_value;
}

CORBA::Long CCD::get_wheel_position() throw (CORBA::SystemException)
{
  CORBA::Long ret_value(1);

  if (component_running)
  {
    ACS::Time time_stamp(0);

    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDget_wheel_positionFunct.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::get_wheel_position: Function is not executed. Check if component is running!"));
  }
  return ret_value;
}

CORBA::Long CCD::init_wheel() throw (CORBA::SystemException)
{
  CORBA::Long ret_value(1);

  if (component_running)
  {
    ACS::Time time_stamp(0);

    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDinit_wheelFunct.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::init_wheel: Function is not executed. Check if component is running!"));
  }
  return ret_value;
}

CORBA::Long CCD::move_wheel_down() throw (CORBA::SystemException)
{
  CORBA::Long ret_value(1);

  if (component_running)
  {
    ACS::Time time_stamp(0);

    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDmove_wheel_downFunct.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::move_wheel_down: Function is not executed. Check if component is running!"));
  }
  return ret_value;
}

CORBA::Long CCD::move_wheel_to(CORBA::Long position) throw (CORBA::SystemException)
{
  CORBA::Long ret_value(1);

  if (component_running)
  {
    ACS::Time time_stamp(0);

    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDmove_wheel_toFunct.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::move_wheel_to: Function is not executed. Check if component is running!"));
  }
  return ret_value;
}

CORBA::Long CCD::move_wheel_up() throw (CORBA::SystemException)
{
  CORBA::Long ret_value(1);

  if (component_running)
  {
    ACS::Time time_stamp(0);

    irisStatus::status old_component_status(m_componentStatus_p->getDevIO()->read(time_stamp));
    m_componentStatus_p->getDevIO()->write(irisStatus::WORKING, time_stamp);

#include "irisCCDmove_wheel_upFunct.body"

    m_componentStatus_p->getDevIO()->write(old_component_status, time_stamp);
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::move_wheel_up: Function is not executed. Check if component is running!"));
  }
  return ret_value;
}

/* --------------------- [ CORBA interface ] ----------------------*/
void CCD::off(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw (CORBA::SystemException)
{
  getComponent()->registerAction(BACIValue::type_null, cb, desc, this, off_ACTION);
}

void CCD::on(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw (CORBA::SystemException)
{
  getComponent()->registerAction(BACIValue::type_null, cb, desc, this, on_ACTION);
}

void CCD::resetCamera(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw (CORBA::SystemException)
{
  getComponent()->registerAction(BACIValue::type_null, cb, desc, this, resetCamera_ACTION);
}

void CCD::setTemperature(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc)
    throw (CORBA::SystemException)
{
  getComponent()->registerAction(BACIValue::type_null, cb, desc, this, setTemperature_ACTION);
}

void CCD::startExposure(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc)
    throw (CORBA::SystemException)
{
  getComponent()->registerAction(BACIValue::type_null, cb, desc, this, startExposure_ACTION);
}

void CCD::stopExposure(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc)
    throw (CORBA::SystemException)
{
  getComponent()->registerAction(BACIValue::type_null, cb, desc, this, stopExposure_ACTION);
}

irisStatus::ROstatus_ptr CCD::componentStatus() throw (CORBA::SystemException)
{
  if (!m_componentStatus_p)
  {
    return irisStatus::ROstatus::_nil();
  }
  irisStatus::ROstatus_var prop = irisStatus::ROstatus::_narrow(
      m_componentStatus_p->getCORBAReference());
  return prop._retn();
}

ACS::ROdouble_ptr CCD::actualAirTemperature() throw (CORBA::SystemException)
{
  if (!m_actualAirTemperature_p)
  {
    return ACS::ROdouble::_nil();
  }
  ACS::ROdouble_var prop = ACS::ROdouble::_narrow(m_actualAirTemperature_p->getCORBAReference());
  return prop._retn();
}

ACS::ROdouble_ptr CCD::actualCCDTemperature() throw (CORBA::SystemException)
{
  if (!m_actualCCDTemperature_p)
  {
    return ACS::ROdouble::_nil();
  }
  ACS::ROdouble_var prop = ACS::ROdouble::_narrow(m_actualCCDTemperature_p->getCORBAReference());
  return prop._retn();
}

ACS::RWstring_ptr CCD::cameraName() throw (CORBA::SystemException)
{
  if (!m_cameraName_p)
  {
    return ACS::RWstring::_nil();
  }
  ACS::RWstring_var prop = ACS::RWstring::_narrow(m_cameraName_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::commandedCCDTemperature() throw (CORBA::SystemException)
{
  if (!m_commandedCCDTemperature_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_commandedCCDTemperature_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::darkFrame() throw (CORBA::SystemException)
{
  if (!m_darkFrame_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_darkFrame_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::exposureSequence() throw (CORBA::SystemException)
{
  if (!m_exposureSequence_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_exposureSequence_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::exposureTime() throw (CORBA::SystemException)
{
  if (!m_exposureTime_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_exposureTime_p->getCORBAReference());
  return prop._retn();
}

ACS::RWstring_ptr CCD::filterName() throw (CORBA::SystemException)
{
  if (!m_filterName_p)
  {
    return ACS::RWstring::_nil();
  }
  ACS::RWstring_var prop = ACS::RWstring::_narrow(m_filterName_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::focalLength() throw (CORBA::SystemException)
{
  if (!m_focalLength_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_focalLength_p->getCORBAReference());
  return prop._retn();
}

ACS::ROdouble_ptr CCD::gain() throw (CORBA::SystemException)
{
  if (!m_gain_p)
  {
    return ACS::ROdouble::_nil();
  }
  ACS::ROdouble_var prop = ACS::ROdouble::_narrow(m_gain_p->getCORBAReference());
  return prop._retn();
}

ACS::ROlongSeq_ptr CCD::imageData() throw (CORBA::SystemException)
{
  if (!m_imageData_p)
  {
    return ACS::ROlongSeq::_nil();
  }
  ACS::ROlongSeq_var prop = ACS::ROlongSeq::_narrow(m_imageData_p->getCORBAReference());
  return prop._retn();
}

ACS::ROlong_ptr CCD::imageReady() throw (CORBA::SystemException)
{
  if (!m_imageReady_p)
  {
    return ACS::ROlong::_nil();
  }
  ACS::ROlong_var prop = ACS::ROlong::_narrow(m_imageReady_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::numberOfExposuresInSequence() throw (CORBA::SystemException)
{
  if (!m_numberOfExposuresInSequence_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_numberOfExposuresInSequence_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::numberOfFlushes() throw (CORBA::SystemException)
{
  if (!m_numberOfFlushes_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_numberOfFlushes_p->getCORBAReference());
  return prop._retn();
}

ACS::RWstring_ptr CCD::objectName() throw (CORBA::SystemException)
{
  if (!m_objectName_p)
  {
    return ACS::RWstring::_nil();
  }
  ACS::RWstring_var prop = ACS::RWstring::_narrow(m_objectName_p->getCORBAReference());
  return prop._retn();
}

ACS::RWstring_ptr CCD::observerName() throw (CORBA::SystemException)
{
  if (!m_observerName_p)
  {
    return ACS::RWstring::_nil();
  }
  ACS::RWstring_var prop = ACS::RWstring::_narrow(m_observerName_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdoubleSeq_ptr CCD::simulationAmplitude() throw (CORBA::SystemException)
{
  if (!m_simulationAmplitude_p)
  {
    return ACS::RWdoubleSeq::_nil();
  }
  ACS::RWdoubleSeq_var prop = ACS::RWdoubleSeq::_narrow(
      m_simulationAmplitude_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::simulationBackgroundNoise() throw (CORBA::SystemException)
{
  if (!m_simulationBackgroundNoise_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
      m_simulationBackgroundNoise_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::simulationFieldRotation() throw (CORBA::SystemException)
{
  if (!m_simulationFieldRotation_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_simulationFieldRotation_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::simulationFwhmX() throw (CORBA::SystemException)
{
  if (!m_simulationFwhmX_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_simulationFwhmX_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::simulationFwhmY() throw (CORBA::SystemException)
{
  if (!m_simulationFwhmY_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_simulationFwhmY_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::simulationNoise() throw (CORBA::SystemException)
{
  if (!m_simulationNoise_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_simulationNoise_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::simulationReadoutNoise() throw (CORBA::SystemException)
{
  if (!m_simulationReadoutNoise_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_simulationReadoutNoise_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::simulationRotationCentreX() throw (CORBA::SystemException)
{
  if (!m_simulationRotationCentreX_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
      m_simulationRotationCentreX_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::simulationRotationCentreY() throw (CORBA::SystemException)
{
  if (!m_simulationRotationCentreY_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
      m_simulationRotationCentreY_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdoubleSeq_ptr CCD::simulationX() throw (CORBA::SystemException)
{
  if (!m_simulationX_p)
  {
    return ACS::RWdoubleSeq::_nil();
  }
  ACS::RWdoubleSeq_var prop = ACS::RWdoubleSeq::_narrow(m_simulationX_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdoubleSeq_ptr CCD::simulationY() throw (CORBA::SystemException)
{
  if (!m_simulationY_p)
  {
    return ACS::RWdoubleSeq::_nil();
  }
  ACS::RWdoubleSeq_var prop = ACS::RWdoubleSeq::_narrow(m_simulationY_p->getCORBAReference());
  return prop._retn();
}

ACS::ROpattern_ptr CCD::status() throw (CORBA::SystemException)
{
  if (!m_status_p)
  {
    return ACS::ROpattern::_nil();
  }
  ACS::ROpattern_var prop = ACS::ROpattern::_narrow(m_status_p->getCORBAReference());
  return prop._retn();
}

ACS::RWstring_ptr CCD::telescopeName() throw (CORBA::SystemException)
{
  if (!m_telescopeName_p)
  {
    return ACS::RWstring::_nil();
  }
  ACS::RWstring_var prop = ACS::RWstring::_narrow(m_telescopeName_p->getCORBAReference());
  return prop._retn();
}

ACS::ROstring_ptr CCD::timeExposureEnd() throw (CORBA::SystemException)
{
  if (!m_timeExposureEnd_p)
  {
    return ACS::ROstring::_nil();
  }
  ACS::ROstring_var prop = ACS::ROstring::_narrow(m_timeExposureEnd_p->getCORBAReference());
  return prop._retn();
}

ACS::ROstring_ptr CCD::timeExposureStart() throw (CORBA::SystemException)
{
  if (!m_timeExposureStart_p)
  {
    return ACS::ROstring::_nil();
  }
  ACS::ROstring_var prop = ACS::ROstring::_narrow(m_timeExposureStart_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr CCD::waitTimeBetweenExposuresInSequence() throw (CORBA::SystemException)
{
  if (!m_waitTimeBetweenExposuresInSequence_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
      m_waitTimeBetweenExposuresInSequence_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::xEnd() throw (CORBA::SystemException)
{
  if (!m_xEnd_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_xEnd_p->getCORBAReference());
  return prop._retn();
}

ACS::ROdouble_ptr CCD::xPixelSize() throw (CORBA::SystemException)
{
  if (!m_xPixelSize_p)
  {
    return ACS::ROdouble::_nil();
  }
  ACS::ROdouble_var prop = ACS::ROdouble::_narrow(m_xPixelSize_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::xStart() throw (CORBA::SystemException)
{
  if (!m_xStart_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_xStart_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::yEnd() throw (CORBA::SystemException)
{
  if (!m_yEnd_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_yEnd_p->getCORBAReference());
  return prop._retn();
}

ACS::ROdouble_ptr CCD::yPixelSize() throw (CORBA::SystemException)
{
  if (!m_yPixelSize_p)
  {
    return ACS::ROdouble::_nil();
  }
  ACS::ROdouble_var prop = ACS::ROdouble::_narrow(m_yPixelSize_p->getCORBAReference());
  return prop._retn();
}

ACS::RWlong_ptr CCD::yStart() throw (CORBA::SystemException)
{
  if (!m_yStart_p)
  {
    return ACS::RWlong::_nil();
  }
  ACS::RWlong_var prop = ACS::RWlong::_narrow(m_yStart_p->getCORBAReference());
  return prop._retn();
}

/* --------------- [ MACI DLL support functions ] -----------------*/

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS( CCD)
