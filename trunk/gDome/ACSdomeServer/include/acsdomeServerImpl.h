#ifndef _DOME_SERVER_H
#define _DOME_SERVER_H

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <ACSErrTypeCommon.h>
#include <acsdomeServerS.h>

#include <baciCharacteristicComponentImpl.h>
#include <baciRWdouble.h>
#include <baciRWlong.h>

#include <baciSmartPropertyPointer.h>

/*
 * El componente se debe crear a partir del CharacteristicComponentImpl,
 * a traves de la herencia de dicho componente.
 * Esto permite que podamos implementar las distintas caracteristicas que
 * este componente tiene implementados.
 */
class DomeServer: public baci::CharacteristicComponentImpl,
			  public virtual POA_acsdomeServer::DomeServer
{
  public:
	DomeServer(
	       const ACE_CString& name,
	       maci::ContainerServices * containerServices);

    virtual ~DomeServer();

    virtual void displayMessage();
    virtual void badMethod();
    //virtual CORBA::Double getCurrentPosition() throw(CORBA::SystemException);

    // ATRIBUTOS
    virtual ACS::RWdouble_ptr
    domeCurrentPosition ();

    virtual ACS::RWlong_ptr
    slitCurrentState ();

    private:
    	/*
    	 * Se utilizan SmartPropertyPointer para el manejo de los distintos
    	 * atributos, su obtencion y seteo.
    	 */
        baci::SmartPropertyPointer<baci::RWdouble> m_domeCurrentPosition_sp;
        baci::SmartPropertyPointer<baci::RWlong> m_slitCurrentState_sp;
};

#endif
