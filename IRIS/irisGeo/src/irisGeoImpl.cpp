/*
 * "@(#) $Id: irisGeoImpl.cpp,v 1.3 2010/01/02 13:21:21  mparra Exp $"
 *
 * Revision 1.2 2010/01/02 13:21:21  mparra
 * - Adapted to IRIS telescope name.
 * - Replace deprecate constructor Geo(PortableServer::POA_ptr poa, const ACE_CString &name)
 *   by Geo(const ACE_CString &name, maci::ContainerServices *containerServices) and call the
 *   new CharacteristicComponentImpl.
 *
 */

#include <vltPort.h>

static char *rcsId = "@(#) $Id: irisGeoImpl.cpp,v 1.3 2010/01/02 13:21:21  mparra Exp $";
static void *use_rcsId = ((void) &use_rcsId, (void *) &rcsId);

#include <baciDB.h>
#include <irisGeoImpl.h>
#include <irisGeoImplIncludes.h>
#include <irisGeoHelperFunctions.cpp>

using namespace baci;

Geo::Geo(const ACE_CString &name, maci::ContainerServices *containerServices) :
  CharacteristicComponentImpl(name, containerServices), m_longitude_p(this), m_latitude_p(this), m_height_p(this)
{
  ACS_TRACE("::Geo::Geo");
  m_longitude_p = new RWdouble(name + ":longitude", getComponent());
  m_latitude_p = new RWdouble(name + ":latitude", getComponent());
  m_height_p = new RWdouble(name + ":height", getComponent());
#include <irisGeoImplInit.cpp>
#include <irisGeoThreadInit.cpp>
}

#include <irisGeoThreadImpl.cpp>
Geo::~Geo()
{
  ACS_TRACE("::Geo::~Geo");
  if (getComponent())
  {
    ACS_DEBUG_PARAM("::Geo::~Geo", "Destroying %s...", getComponent()->getName());
    getComponent()->stopAllThreads();
  }
  ACS_DEBUG("::Geo::~Geo", "Properties destroyed");
}

void Geo::cleanUp()
{
  ACS_TRACE("::cleanUp()");
  if (getComponent())
  {
#include <irisGeoImplCleanUp.body>
    CharacteristicComponentImpl::cleanUp();
  }
}

/* --------------- [ Action implementator interface ] -------------- */
ActionRequest Geo::invokeAction(int function, BACIComponent *cob, const int &callbackID,
    const CBDescIn &descIn, BACIValue *value, Completion &completion, CBDescOut &descOut)
{
  switch (function)
  {
  default:
  {
    return reqDestroy;
  }
  }
}

/* ------------------ [ Action implementations ] ----------------- */

/* ------------------ [ Functions ] ----------------- */

/* --------------------- [ CORBA interface ] ----------------------*/
ACS::RWdouble_ptr Geo::longitude() throw (CORBA::SystemException)
{
  if (!m_longitude_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_longitude_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr Geo::latitude() throw (CORBA::SystemException)
{
  if (!m_latitude_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_latitude_p->getCORBAReference());
  return prop._retn();
}

ACS::RWdouble_ptr Geo::height() throw (CORBA::SystemException)
{
  if (!m_height_p)
  {
    return ACS::RWdouble::_nil();
  }
  ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_height_p->getCORBAReference());
  return prop._retn();
}

/* --------------- [ MACI DLL support functions ] -----------------*/

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS( Geo)
