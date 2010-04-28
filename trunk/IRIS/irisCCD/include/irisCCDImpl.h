/*
 *
 * "@(#) $Id: irisCCDImpl.h,v 1.15  2009/12/04 10:37:25  mparra Exp $"
 *
 * $Log: irisCCDImpl.h,v $
 * Revision 1.15  2009/12/04 10:37:25  mparra
 * - Adapted to IRIS telescope name.
 * - Change the constructor class, from this moment it's use const ACE_CString&
 *   and maci::ContainerServices*.
 *
 * Revision 1.14  2005/03/09 14:34:42  tjuerges
 * - Added component status.
 *
 *
 */

#ifndef irisCCDImpl_h
#define irisCCDImpl_h

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <baciCharacteristicComponentImpl.h>

#include <irisExport.h>
#include <irisComponentStatusS.h>
#include <irisCCDS.h>

#include <baciROlong.h>
#include <baciRWlong.h>
#include <baciROstring.h>
#include <baciRWstring.h>
#include <baciROdouble.h>
#include <baciRWdouble.h>
#include <baciROpattern.h>
#include <baciRWpattern.h>
#include <baciROlongSeq.h>
#include <baciRWlongSeq.h>
#include <baciROdoubleSeq.h>
#include <baciRWdoubleSeq.h>
#include <enumpropROImpl.h>

#include <baciSmartPropertyPointer.h>

#include <irisCCDIncludes.h>

using namespace baci;

class IRIS_EXPORT CCD: public virtual CharacteristicComponentImpl,
public virtual POA_irisCCD::CCD, public ActionImplementator
{

  public:
  /**
   * Constructor
   * @param poa poa which will activate this and also all other COBs
   * @param name component name
   */
  CCD(const ACE_CString &name, maci::ContainerServices *containerServices);

  /**
   * Destructor
   */
  virtual ~CCD();

  virtual void cleanUp();

  virtual ActionRequest invokeAction (int function,
      BACIComponent* cob_p,
      const int& callbackID,
      const CBDescIn& descIn,
      BACIValue* value_p,
      Completion& completion,
      CBDescOut& descOut);

  /* --------------- [ Action START implementator interface ] ------ */
  virtual ActionRequest offAction (BACIComponent* cob,
      const int& callbackID,
      const CBDescIn& descIn,
      BACIValue* value,
      Completion& completion,
      CBDescOut& descOut);

  virtual ActionRequest onAction (BACIComponent* cob,
      const int& callbackID,
      const CBDescIn& descIn,
      BACIValue* value,
      Completion& completion,
      CBDescOut& descOut);

  virtual ActionRequest resetCameraAction (BACIComponent* cob,
      const int& callbackID,
      const CBDescIn& descIn,
      BACIValue* value,
      Completion& completion,
      CBDescOut& descOut);

  virtual ActionRequest setTemperatureAction (BACIComponent* cob,
      const int& callbackID,
      const CBDescIn& descIn,
      BACIValue* value,
      Completion& completion,
      CBDescOut& descOut);

  virtual ActionRequest startExposureAction (BACIComponent* cob,
      const int& callbackID,
      const CBDescIn& descIn,
      BACIValue* value,
      Completion& completion,
      CBDescOut& descOut);

  virtual ActionRequest stopExposureAction (BACIComponent* cob,
      const int& callbackID,
      const CBDescIn& descIn,
      BACIValue* value,
      Completion& completion,
      CBDescOut& descOut);

  /* --------------- [ Action END   implementator interface ] ------ */

  /* --------------------- [ CORBA START interface ] ----------------*/
  irisStatus::ROstatus_ptr componentStatus() throw(CORBA::SystemException);

  virtual void off(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw(CORBA::SystemException);

  virtual void on(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw(CORBA::SystemException);

  virtual void resetCamera(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw(CORBA::SystemException);

  virtual void setTemperature(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw(CORBA::SystemException);

  virtual void startExposure(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw(CORBA::SystemException);

  virtual void stopExposure(ACS::CBvoid_ptr cb, const ACS::CBDescIn& desc) throw(CORBA::SystemException);

  virtual ACS::ROdouble_ptr actualAirTemperature() throw(CORBA::SystemException);

  virtual ACS::ROdouble_ptr actualCCDTemperature() throw(CORBA::SystemException);

  virtual ACS::RWstring_ptr cameraName() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr commandedCCDTemperature() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr darkFrame() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr exposureSequence() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr exposureTime() throw(CORBA::SystemException);

  virtual ACS::RWstring_ptr filterName() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr focalLength() throw(CORBA::SystemException);

  virtual ACS::ROdouble_ptr gain() throw(CORBA::SystemException);

  virtual ACS::ROlongSeq_ptr imageData() throw(CORBA::SystemException);

  virtual ACS::ROlong_ptr imageReady() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr numberOfExposuresInSequence() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr numberOfFlushes() throw(CORBA::SystemException);

  virtual ACS::RWstring_ptr objectName() throw(CORBA::SystemException);

  virtual ACS::RWstring_ptr observerName() throw(CORBA::SystemException);

  virtual ACS::RWdoubleSeq_ptr simulationAmplitude() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr simulationBackgroundNoise() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr simulationFieldRotation() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr simulationFwhmX() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr simulationFwhmY() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr simulationNoise() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr simulationReadoutNoise() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr simulationRotationCentreX() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr simulationRotationCentreY() throw(CORBA::SystemException);

  virtual ACS::RWdoubleSeq_ptr simulationX() throw(CORBA::SystemException);

  virtual ACS::RWdoubleSeq_ptr simulationY() throw(CORBA::SystemException);

  virtual ACS::ROpattern_ptr status() throw(CORBA::SystemException);

  virtual ACS::RWstring_ptr telescopeName() throw(CORBA::SystemException);

  virtual ACS::ROstring_ptr timeExposureEnd() throw(CORBA::SystemException);

  virtual ACS::ROstring_ptr timeExposureStart() throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr waitTimeBetweenExposuresInSequence() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr xEnd() throw(CORBA::SystemException);

  virtual ACS::ROdouble_ptr xPixelSize() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr xStart() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr yEnd() throw(CORBA::SystemException);

  virtual ACS::ROdouble_ptr yPixelSize() throw(CORBA::SystemException);

  virtual ACS::RWlong_ptr yStart() throw(CORBA::SystemException);

  virtual CORBA::Long exit_wheel() throw(CORBA::SystemException);

  virtual CORBA::Long get_wheel_position() throw(CORBA::SystemException);

  virtual CORBA::Long init_wheel() throw(CORBA::SystemException);

  virtual CORBA::Long move_wheel_down() throw(CORBA::SystemException);

  virtual CORBA::Long move_wheel_to(CORBA::Long position ) throw(CORBA::SystemException);

  virtual CORBA::Long move_wheel_up() throw(CORBA::SystemException);

  /* --------------------- [ CORBA END interface ] ----------------*/

  /* ----------------------------------------------------------------*/

  private:
  /* --------------------- [ Properties START ] ----------------------*/
  SmartPropertyPointer<ROEnumImpl<ACS_ENUM_T(irisStatus::status), POA_irisStatus::ROstatus> > m_componentStatus_p;
  SmartPropertyPointer<ROdouble> m_actualAirTemperature_p;
  SmartPropertyPointer<ROdouble> m_actualCCDTemperature_p;
  SmartPropertyPointer<RWstring> m_cameraName_p;
  SmartPropertyPointer<RWdouble> m_commandedCCDTemperature_p;
  SmartPropertyPointer<RWlong> m_darkFrame_p;
  SmartPropertyPointer<RWlong> m_exposureSequence_p;
  SmartPropertyPointer<RWdouble> m_exposureTime_p;
  SmartPropertyPointer<RWstring> m_filterName_p;
  SmartPropertyPointer<RWdouble> m_focalLength_p;
  SmartPropertyPointer<ROdouble> m_gain_p;
  SmartPropertyPointer<ROlongSeq> m_imageData_p;
  SmartPropertyPointer<ROlong> m_imageReady_p;
  SmartPropertyPointer<RWlong> m_numberOfExposuresInSequence_p;
  SmartPropertyPointer<RWlong> m_numberOfFlushes_p;
  SmartPropertyPointer<RWstring> m_objectName_p;
  SmartPropertyPointer<RWstring> m_observerName_p;
  SmartPropertyPointer<RWdoubleSeq> m_simulationAmplitude_p;
  SmartPropertyPointer<RWdouble> m_simulationBackgroundNoise_p;
  SmartPropertyPointer<RWdouble> m_simulationFieldRotation_p;
  SmartPropertyPointer<RWdouble> m_simulationFwhmX_p;
  SmartPropertyPointer<RWdouble> m_simulationFwhmY_p;
  SmartPropertyPointer<RWlong> m_simulationNoise_p;
  SmartPropertyPointer<RWdouble> m_simulationReadoutNoise_p;
  SmartPropertyPointer<RWdouble> m_simulationRotationCentreX_p;
  SmartPropertyPointer<RWdouble> m_simulationRotationCentreY_p;
  SmartPropertyPointer<RWdoubleSeq> m_simulationX_p;
  SmartPropertyPointer<RWdoubleSeq> m_simulationY_p;
  SmartPropertyPointer<ROpattern> m_status_p;
  SmartPropertyPointer<RWstring> m_telescopeName_p;
  SmartPropertyPointer<ROstring> m_timeExposureEnd_p;
  SmartPropertyPointer<ROstring> m_timeExposureStart_p;
  SmartPropertyPointer<RWdouble> m_waitTimeBetweenExposuresInSequence_p;
  SmartPropertyPointer<RWlong> m_xEnd_p;
  SmartPropertyPointer<ROdouble> m_xPixelSize_p;
  SmartPropertyPointer<RWlong> m_xStart_p;
  SmartPropertyPointer<RWlong> m_yEnd_p;
  SmartPropertyPointer<ROdouble> m_yPixelSize_p;
  SmartPropertyPointer<RWlong> m_yStart_p;

  /* --------------------- [ Properties END ] ------------------------*/

  /* --------------------- [ Local properties START ] ----------------*/
#include <irisCCDLocalProperties.h>
  /* --------------------- [ Local properties END ] ------------------*/
};

#endif /* irisCCDImpl_h */
