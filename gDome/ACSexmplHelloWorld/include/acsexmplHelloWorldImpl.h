#ifndef _HELLO_WORLD_H
#define _HELLO_WORLD_H
/*******************************************************************************
*    ALMA - Atacama Large Millimiter Array
*    (c) Associated Universities Inc., 2002
*    (c) European Southern Observatory, 2002
*    Copyright by ESO (in the framework of the ALMA collaboration)
*    and Cosylab 2002, All rights reserved
*
*    This library is free software; you can redistribute it and/or
*    modify it under the terms of the GNU Lesser General Public
*    License as published by the Free Software Foundation; either
*    version 2.1 of the License, or (at your option) any later version.
*
*    This library is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    Lesser General Public License for more details.
*
*    You should have received a copy of the GNU Lesser General Public
*    License along with this library; if not, write to the Free Software
*    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*
* "@(#) $Id: acsexmplHelloWorldImpl.h,v 1.98 2008/10/01 04:30:47 cparedes Exp $"
*
* who       when      what
* --------  --------  ----------------------------------------------
* david 2002-09-26 added more comments
* david  25/09/02  created
*/

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

///This example is unique because it is derived from CharacteristicComponent's
///superclass, ACSComponent.
#include <acscomponentImpl.h>

///This is the CORBA stub client header for ACSErrTypeCommon.idl where the
///definition of the CORBA exception is found.
#include <ACSErrTypeCommon.h>

/**
 *  The empty CORBA servant interface, POA_acsexmplHelloWorld::HelloWorld,
 *  is obtained from this header file and is automatically generated from
 *  HelloWorld's Interface Definition File (i.e., acsexmplHelloWorld.idl)
 *  by CORBA.
 */
#include <acsexmplHelloWorldS.h>

/** @file acsexmplHelloWorldImpl.h
 */
/** @addtogroup ACSEXMPLTOC
*/
/*@{
*/

/** @addtogroup ACSEXMPLTOCCOMPONENTS
*/
/*@{
*/

/** @defgroup ACSEXMPLHWDOC Hello World
 *  @{
 * @htmlonly
<hr size="2" width="100%">
<div align="left">
<h2>Description</h2>
Hello World is the simplest component within the acsexmpl module. It provides
two methods, displayMessage() which prints "Hello World" to standard out and
badMethod which raises a CORBA exception.
<br>
<br>
<h2>What can I gain from this example?</h2>
<ul>
  <li>an example derived from the ACS::ACSComponent IDL interface.</li>
  <li>an introduction to the ACS API.</li>
  <li>limited ACS logging macros.</li>
  <li>raising CORBA exceptions.</li>
</ul>
<br>
<br>
<h2>Links</h2>
<ul>
  <li><a href="classHelloWorld.html">Hello World Class Reference</a></li>
  <li><a href="interfaceacsexmplHelloWorld_1_1HelloWorld.html">Hello World IDL Documentation</a></li>
</ul>
</div>
   @endhtmlonly
 * @}
 */

/**
 * This class shows how to make an ACS Hello World component.
 * It provides one synchronous method: displayMessage() which just prints
 * "Hello World" to the command-line where the container that activated
 * an instance of this component was started from. badMethod() is a trivial
 * method showing developers how to raise ACS (i.e., CORBA) exceptions.
 *
 * All components should inherit from CharacteristicComponentImpl or it's
 * superclass, ACSComponentImpl, to remain  compatiable with ACS tools such
 * as objexp (i.e., a GUI used to manipulate components).  This class also
 * derives from POA_acsexmplHelloWorld::HelloWorld which is a class automatically
 * generated by CORBA from HelloWorld's IDL file.
 * @version "@(#) $Id: acsexmplHelloWorldImpl.h,v 1.98 2008/10/01 04:30:47 cparedes Exp $"
 */
class HelloWorld: public virtual acscomponent::ACSComponentImpl,     //Component superclass
		  public POA_acsexmplHelloWorld::HelloWorld    //CORBA servant stub
{
  public:
    /**
     * Constructor
     * @param poa Poa which will activate this and also all other components. Developers need
     * not be concerned with what a PortableServer does...just pass it to the superclass's
     * constructor.
     * @param name component's name. All components have a name associated with them so other
     * components and clients can access them.
     */
    HelloWorld(
	       const ACE_CString& name,
	       maci::ContainerServices * containerServices);

    /**
     * Destructor
     */
    virtual ~HelloWorld();

    /* --------------------- [ CORBA interface ] ----------------------*/
    /**
     * Displays "Hello World" to the console.
     * Implementation of IDL displayMessage().
     * @htmlonly
       <br><hr>
       @endhtmlonly
     */
    virtual void
    displayMessage ();

    /**
     * Simple method raises a remote exception within the calling client.
     * Implementation of IDL badMethod().
     * @throw ACSErrTypeCommon::UnknownEx
     * @htmlonly
       <br><hr>
       @endhtmlonly
     */
    virtual void
    badMethod();
};
/*\@}*/
/*\@}*/

#endif /*!_HELLO_WORLD_H*/



