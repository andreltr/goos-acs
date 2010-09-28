#ifndef _TCS_SERVER_H
#define _TCS_SERVER_H

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <ACSErrTypeCommon.h>
#include <tcsServerS.h>

#include <baciCharacteristicComponentImpl.h>
#include <baciRWdouble.h>

#include <baciSmartPropertyPointer.h>

/*
 * El componente se debe crear a partir del CharacteristicComponentImpl,
 * a traves de la herencia de dicho componente.
 * Esto permite que podamos implementar las distintas caracteristicas que
 * este componente tiene implementados.
 */
class tcsServer: public baci::CharacteristicComponentImpl,
			  public virtual POA_acstcsServer::tcsServer
{
  public:
	tcsServer(
	       const ACE_CString& name,
	       maci::ContainerServices * containerServices);

    virtual ~tcsServer();

    virtual void displayMessage();
    virtual void badMethod();
    //virtual CORBA::Double getCurrentPosition() throw(CORBA::SystemException);

    // ATRIBUTOS
    virtual ACS::RWdouble_ptr
    currentPositionAlpha ();

    virtual ACS::RWdouble_ptr
    currentPositionDelta ();


    private:
    	/*
    	 * Se utilizan SmartPropertyPointer para el manejo de los distintos
    	 * atributos, su obtencion y seteo.
    	 */
        baci::SmartPropertyPointer<baci::RWdouble> m_currentPositionAlpha_sp;
        baci::SmartPropertyPointer<baci::RWdouble> m_currentPositionDelta_sp;

};

#endif
