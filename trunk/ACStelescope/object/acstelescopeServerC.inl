// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.5 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ci.cpp:70

#if !defined (_ACSTELESCOPESERVER_TELESCOPESERVER___CI_)
#define _ACSTELESCOPESERVER_TELESCOPESERVER___CI_

ACE_INLINE
acstelescopeServer::TelescopeServer::TelescopeServer (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_TelescopeServer_Proxy_Broker_ (0)
{
  this->acstelescopeServer_TelescopeServer_setup_collocation ();
}

ACE_INLINE
acstelescopeServer::TelescopeServer::TelescopeServer (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc)
    , the_TAO_TelescopeServer_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

