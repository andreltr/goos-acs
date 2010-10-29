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
// be/be_codegen.cpp:135

#ifndef _TAO_IDL____OBJECT_ACSTELESCOPESERVERC_H_
#define _TAO_IDL____OBJECT_ACSTELESCOPESERVERC_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "ACSErrTypeCommonC.h"
#include "baciC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

// TAO_IDL - Generated from 
// be/be_visitor_root/root_ch.cpp:62
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:49

namespace acstelescopeServer
{
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:644

#if !defined (_ACSTELESCOPESERVER_TELESCOPESERVER__VAR_OUT_CH_)
#define _ACSTELESCOPESERVER_TELESCOPESERVER__VAR_OUT_CH_
  
  class TelescopeServer;
  typedef TelescopeServer *TelescopeServer_ptr;
  
  typedef
    TAO_Objref_Var_T<
        TelescopeServer
      >
    TelescopeServer_var;
  
  typedef
    TAO_Objref_Out_T<
        TelescopeServer
      >
    TelescopeServer_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_ACSTELESCOPESERVER_TELESCOPESERVER_CH_)
#define _ACSTELESCOPESERVER_TELESCOPESERVER_CH_
  
  class  TelescopeServer
    : public virtual ::ACS::CharacteristicComponent
  {
  public:
    friend class TAO::Narrow_Utils<TelescopeServer>;
    typedef TelescopeServer_ptr _ptr_type;
    typedef TelescopeServer_var _var_type;
    typedef TelescopeServer_out _out_type;
    
    // The static operations.
    static TelescopeServer_ptr _duplicate (TelescopeServer_ptr obj);
    
    static void _tao_release (TelescopeServer_ptr obj);
    
    static TelescopeServer_ptr _narrow (::CORBA::Object_ptr obj);
    static TelescopeServer_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static TelescopeServer_ptr _nil (void)
    {
      return static_cast<TelescopeServer_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void displayMessage (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void badMethod (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Double startTelescope (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Double slewTelescope (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Double getAltitude (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Double getAzimuth (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Double stopSlewing (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::ACS::RWdouble_ptr currentPositionAlpha (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::ACS::RWdouble_ptr currentPositionDelta (
        void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_TelescopeServer_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    TelescopeServer (void);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void acstelescopeServer_TelescopeServer_setup_collocation (void);
    
    // Concrete non-local interface only.
    TelescopeServer (
        IOP::IOR *ior,
        TAO_ORB_Core *orb_core = 0);
    
    // Non-local interface only.
    TelescopeServer (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~TelescopeServer (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    TelescopeServer (const TelescopeServer &);
    
    void operator= (const TelescopeServer &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:49
  
  extern  ::CORBA::TypeCode_ptr const _tc_TelescopeServer;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:78

} // module acstelescopeServer

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:139

extern 
TAO::Collocation_Proxy_Broker *
(*acstelescopeServer__TAO_TelescopeServer_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:64

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_ACSTELESCOPESERVER_TELESCOPESERVER__TRAITS_)
#define _ACSTELESCOPESERVER_TELESCOPESERVER__TRAITS_
  
  template<>
  struct  Objref_Traits< ::acstelescopeServer::TelescopeServer>
  {
    static ::acstelescopeServer::TelescopeServer_ptr duplicate (
        ::acstelescopeServer::TelescopeServer_ptr p
      );
    static void release (
        ::acstelescopeServer::TelescopeServer_ptr p
      );
    static ::acstelescopeServer::TelescopeServer_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::acstelescopeServer::TelescopeServer_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace acstelescopeServer
{
   void operator<<= ( ::CORBA::Any &, TelescopeServer_ptr); // copying
   void operator<<= ( ::CORBA::Any &, TelescopeServer_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, TelescopeServer_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, acstelescopeServer::TelescopeServer_ptr); // copying
 void operator<<= (::CORBA::Any &, acstelescopeServer::TelescopeServer_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, acstelescopeServer::TelescopeServer_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:55

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const acstelescopeServer::TelescopeServer_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, acstelescopeServer::TelescopeServer_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_codegen.cpp:1226
#if defined (__ACE_INLINE__)
#include "acstelescopeServerC.inl"
#endif /* defined INLINE */

#endif /* ifndef */

