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


ACE_INLINE
void
POA_acstcsServer::tcsServer::_get_name_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
  )
{
  POA_ACS::ACSComponent * const impl = static_cast<POA_acstcsServer::tcsServer *> (servant);
  POA_ACS::ACSComponent::_get_name_skel (
      server_request,
      servant_upcall,
      impl
    );
}

ACE_INLINE
void
POA_acstcsServer::tcsServer::_get_componentState_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
  )
{
  POA_ACS::ACSComponent * const impl = static_cast<POA_acstcsServer::tcsServer *> (servant);
  POA_ACS::ACSComponent::_get_componentState_skel (
      server_request,
      servant_upcall,
      impl
    );
}

// TAO_IDL - Generated from
// be/be_interface.cpp:2043

ACE_INLINE
void
POA_acstcsServer::tcsServer::get_characteristic_by_name_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
  )
{
  POA_ACS::CharacteristicModel * const impl = static_cast<POA_acstcsServer::tcsServer *> (servant);
  POA_ACS::CharacteristicModel::get_characteristic_by_name_skel (
      server_request,
      servant_upcall,
      impl
    );
}

// TAO_IDL - Generated from
// be/be_interface.cpp:2043

ACE_INLINE
void
POA_acstcsServer::tcsServer::find_characteristic_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
  )
{
  POA_ACS::CharacteristicModel * const impl = static_cast<POA_acstcsServer::tcsServer *> (servant);
  POA_ACS::CharacteristicModel::find_characteristic_skel (
      server_request,
      servant_upcall,
      impl
    );
}

// TAO_IDL - Generated from
// be/be_interface.cpp:2043

ACE_INLINE
void
POA_acstcsServer::tcsServer::get_all_characteristics_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
  )
{
  POA_ACS::CharacteristicModel * const impl = static_cast<POA_acstcsServer::tcsServer *> (servant);
  POA_ACS::CharacteristicModel::get_all_characteristics_skel (
      server_request,
      servant_upcall,
      impl
    );
}

// TAO_IDL - Generated from
// be/be_interface.cpp:2043

ACE_INLINE
void
POA_acstcsServer::tcsServer::descriptor_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
  )
{
  POA_ACS::CharacteristicComponent * const impl = static_cast<POA_acstcsServer::tcsServer *> (servant);
  POA_ACS::CharacteristicComponent::descriptor_skel (
      server_request,
      servant_upcall,
      impl
    );
}

