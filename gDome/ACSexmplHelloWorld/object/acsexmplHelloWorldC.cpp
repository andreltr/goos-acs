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
// be/be_codegen.cpp:381


#include "acsexmplHelloWorldC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/Basic_Arguments.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "acsexmplHelloWorldC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:73

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for acsexmplHelloWorld::HelloWorld.

acsexmplHelloWorld::HelloWorld_ptr
TAO::Objref_Traits<acsexmplHelloWorld::HelloWorld>::duplicate (
    acsexmplHelloWorld::HelloWorld_ptr p)
{
  return acsexmplHelloWorld::HelloWorld::_duplicate (p);
}

void
TAO::Objref_Traits<acsexmplHelloWorld::HelloWorld>::release (
    acsexmplHelloWorld::HelloWorld_ptr p)
{
  ::CORBA::release (p);
}

acsexmplHelloWorld::HelloWorld_ptr
TAO::Objref_Traits<acsexmplHelloWorld::HelloWorld>::nil (void)
{
  return acsexmplHelloWorld::HelloWorld::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<acsexmplHelloWorld::HelloWorld>::marshal (
    const acsexmplHelloWorld::HelloWorld_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*acsexmplHelloWorld__TAO_HelloWorld_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:78

void acsexmplHelloWorld::HelloWorld::displayMessage (
    void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_HelloWorld_Proxy_Broker_ == 0)
    {
      acsexmplHelloWorld_HelloWorld_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  
  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "displayMessage",
      14,
      this->the_TAO_HelloWorld_Proxy_Broker_
    );
  
  _tao_call.invoke (0, 0);
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:78

void acsexmplHelloWorld::HelloWorld::badMethod (
    void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_HelloWorld_Proxy_Broker_ == 0)
    {
      acsexmplHelloWorld_HelloWorld_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  
  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };
  
  static TAO::Exception_Data
  _tao_acsexmplHelloWorld_HelloWorld_badMethod_exceptiondata [] = 
    {
      {
        "IDL:alma/ACSErrTypeCommon/UnknownEx:1.0",
        ACSErrTypeCommon::UnknownEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , ACSErrTypeCommon::_tc_UnknownEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "badMethod",
      9,
      this->the_TAO_HelloWorld_Proxy_Broker_
    );
  
  _tao_call.invoke (
      _tao_acsexmplHelloWorld_HelloWorld_badMethod_exceptiondata,
      1
    );
}

acsexmplHelloWorld::HelloWorld::HelloWorld (void)
 : the_TAO_HelloWorld_Proxy_Broker_ (0)
{
  this->acsexmplHelloWorld_HelloWorld_setup_collocation ();
}

void
acsexmplHelloWorld::HelloWorld::acsexmplHelloWorld_HelloWorld_setup_collocation ()
{
  if (::acsexmplHelloWorld__TAO_HelloWorld_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_HelloWorld_Proxy_Broker_ =
        ::acsexmplHelloWorld__TAO_HelloWorld_Proxy_Broker_Factory_function_pointer (this);
    }
  
  this->ACS_ACSComponent_setup_collocation ();
}

acsexmplHelloWorld::HelloWorld::~HelloWorld (void)
{}

void 
acsexmplHelloWorld::HelloWorld::_tao_any_destructor (void *_tao_void_pointer)
{
  HelloWorld *_tao_tmp_pointer =
    static_cast<HelloWorld *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

acsexmplHelloWorld::HelloWorld_ptr
acsexmplHelloWorld::HelloWorld::_narrow (
    ::CORBA::Object_ptr _tao_objref
  )
{
  return
    TAO::Narrow_Utils<HelloWorld>::narrow (
        _tao_objref,
        "IDL:alma/acsexmplHelloWorld/HelloWorld:1.0",
        acsexmplHelloWorld__TAO_HelloWorld_Proxy_Broker_Factory_function_pointer
      );
}

acsexmplHelloWorld::HelloWorld_ptr
acsexmplHelloWorld::HelloWorld::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
  )
{
  return
    TAO::Narrow_Utils<HelloWorld>::unchecked_narrow (
        _tao_objref,
        "IDL:alma/acsexmplHelloWorld/HelloWorld:1.0",
        acsexmplHelloWorld__TAO_HelloWorld_Proxy_Broker_Factory_function_pointer
      );
}

acsexmplHelloWorld::HelloWorld_ptr
acsexmplHelloWorld::HelloWorld::_duplicate (HelloWorld_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
acsexmplHelloWorld::HelloWorld::_tao_release (HelloWorld_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
acsexmplHelloWorld::HelloWorld::_is_a (const char *value)
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/ACSComponent:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:alma/acsexmplHelloWorld/HelloWorld:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* acsexmplHelloWorld::HelloWorld::_interface_repository_id (void) const
{
  return "IDL:alma/acsexmplHelloWorld/HelloWorld:1.0";
}

::CORBA::Boolean
acsexmplHelloWorld::HelloWorld::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_acsexmplHelloWorld_HelloWorld (
    ::CORBA::tk_objref,
    "IDL:alma/acsexmplHelloWorld/HelloWorld:1.0",
    "HelloWorld");
  
namespace acsexmplHelloWorld
{
  ::CORBA::TypeCode_ptr const _tc_HelloWorld =
    &_tao_tc_acsexmplHelloWorld_HelloWorld;
}



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:51
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<acsexmplHelloWorld::HelloWorld>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace acsexmplHelloWorld
{
  
  
  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      HelloWorld_ptr _tao_elem)
  {
    HelloWorld_ptr _tao_objptr =
      HelloWorld::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }
  
  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      HelloWorld_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<HelloWorld>::insert (
        _tao_any,
        HelloWorld::_tao_any_destructor,
        _tc_HelloWorld,
        *_tao_elem)
  }
  
  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      HelloWorld_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<HelloWorld>::extract (
          _tao_any,
          HelloWorld::_tao_any_destructor,
          _tc_HelloWorld,
          _tao_elem)
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    acsexmplHelloWorld::HelloWorld_ptr _tao_elem)
{
  acsexmplHelloWorld::HelloWorld_ptr _tao_objptr =
    acsexmplHelloWorld::HelloWorld::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    acsexmplHelloWorld::HelloWorld_ptr *_tao_elem)
{
  TAO::Any_Impl_T<acsexmplHelloWorld::HelloWorld>::insert (
      _tao_any,
      acsexmplHelloWorld::HelloWorld::_tao_any_destructor,
      acsexmplHelloWorld::_tc_HelloWorld,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    acsexmplHelloWorld::HelloWorld_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<acsexmplHelloWorld::HelloWorld>::extract (
        _tao_any,
        acsexmplHelloWorld::HelloWorld::_tao_any_destructor,
        acsexmplHelloWorld::_tc_HelloWorld,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:63

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const acsexmplHelloWorld::HelloWorld_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    acsexmplHelloWorld::HelloWorld_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;
  
  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::acsexmplHelloWorld::HelloWorld RHS_SCOPED_NAME;
  
  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        acsexmplHelloWorld__TAO_HelloWorld_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



