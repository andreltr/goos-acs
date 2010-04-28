/*
 * "@(#) $Id: irisGeoImpl.h,v 1.3 2010/01/02 09:27:09 mparra Exp $"
 *
 * Revision 1.3 2010/01/02 09:27:09  mparra
 * - Adapted to IRIS telescope name.
 * - Replace deprecate constructor Geo(PortableServer::POA_ptr poa, const ACE_CString &name)
 *   by Geo(const ACE_CString &name, maci::ContainerServices *containerServices).
 *
 */

#ifndef irisGeoImpl_h
#define irisGeoImpl_h

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <baciCharacteristicComponentImpl.h>

#include <irisExport.h>
#include <irisGeoS.h>

#include <baciROlong.h>
#include <baciRWlong.h>
#include <baciROstring.h>
#include <baciRWstring.h>
#include <baciROdouble.h>
#include <baciRWdouble.h>
#include <baciROpattern.h>
#include <baciRWpattern.h>

#include <baciSmartPropertyPointer.h>

#include <irisGeoIncludes.h>

using namespace baci;

class IRIS_EXPORT Geo: public virtual CharacteristicComponentImpl,
public virtual POA_irisGeo::Geo,
public ActionImplementator

{

  public:
  /*
   * Constructor
   * @param poa poa which will activate this and also all other COBs
   * @param name DO name
   */
  Geo(const ACE_CString &name, maci::ContainerServices *containerServices);

  /*
   * Destructor
   */
  virtual ~Geo();

  virtual void cleanUp();

  virtual ActionRequest invokeAction (int function,
      BACIComponent *cob_p,
      const int &callbackID,
      const CBDescIn &descIn,
      BACIValue *value_p,
      Completion &completion,
      CBDescOut &descOut);

  /* --------------- [ Action START implementator interface ] ------ */

  /* --------------- [ Action END   implementator interface ] ------ */

  /* --------------------- [ CORBA START interface ] ----------------*/
  virtual ACS::RWdouble_ptr longitude () throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr latitude () throw(CORBA::SystemException);

  virtual ACS::RWdouble_ptr height () throw(CORBA::SystemException);

  /* --------------------- [ CORBA END interface ] ----------------*/

  /* ----------------------------------------------------------------*/

  private:
  /* --------------------- [ Properties START ] ----------------------*/
  SmartPropertyPointer< RWdouble > m_longitude_p;
  SmartPropertyPointer< RWdouble > m_latitude_p;
  SmartPropertyPointer< RWdouble > m_height_p;

  /* --------------------- [ Properties END ] ------------------------*/

  /* --------------------- [ Local properties START ] ----------------*/
#include <irisGeoLocalProperties.h>
  /* --------------------- [ Local properties END ] ------------------*/
};

#endif /* irisGeoImpl_h */
