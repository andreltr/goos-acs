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
// be/be_codegen.cpp:703

#ifndef _TAO_IDL____OBJECT_TCSSERVERS_CPP_
#define _TAO_IDL____OBJECT_TCSSERVERS_CPP_


#include "tcsServerS.h"
#include "tao/PortableServer/Operation_Table_Perfect_Hash.h"
#include "tao/PortableServer/Upcall_Command.h"
#include "tao/PortableServer/Upcall_Wrapper.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/DynamicC.h"
#include "tao/CDR.h"
#include "tao/operation_details.h"
#include "tao/PortableInterceptor.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Object_SArgument_T.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/TypeCode_SArg_Traits.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include "tao/Basic_Arguments.h"
#include "tao/Object_Argument_T.h"
#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"

#if !defined (__ACE_INLINE__)
#include "tcsServerS.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:73

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:141

#if !defined (_ACS_RWDOUBLE__SARG_TRAITS_)
#define _ACS_RWDOUBLE__SARG_TRAITS_
  
  template<>
  class  SArg_Traits<ACS::RWdouble>
    : public
        Object_SArg_Traits_T<
            ACS::RWdouble_ptr,
            ACS::RWdouble_var,
            ACS::RWdouble_out,
            TAO::Any_Insert_Policy_Stream <ACS::RWdouble_ptr>
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:73

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:141

#if !defined (_ACS_RWDOUBLE__ARG_TRAITS_)
#define _ACS_RWDOUBLE__ARG_TRAITS_
  
  template<>
  class  Arg_Traits<ACS::RWdouble>
    : public
        Object_Arg_Traits_T<
            ACS::RWdouble_ptr,
            ACS::RWdouble_var,
            ACS::RWdouble_out,
            TAO::Objref_Traits<ACS::RWdouble>,
            TAO::Any_Insert_Policy_Stream <ACS::RWdouble_ptr>
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_interface.cpp:1555

class TAO_acstcsServer_tcsServer_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: /alma/ACS-8.1/TAO/ACE_wrappers/build/linux/bin/gperf -m -M -J -c -C -D -E -T -f 0 -F 0,0 -a -o -t -p -K opname -L C++ -Z TAO_acstcsServer_tcsServer_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_acstcsServer_tcsServer_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37,  0,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37,  0,
      0, 15,  0, 10,  0,  0, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37,  5, 37, 37, 37, 37, 37, 37,
     37, 37,  0,  0, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37,
#else
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37, 37,  0, 37,  0,  0, 15,
      0, 10,  0,  0, 37, 37, 37, 37, 37, 37,
     37, 37, 37, 37,  5,  0,  0, 37, 37, 37,
     37, 37, 37, 37, 37, 37, 37, 37,
#endif /* ACE_MVS */
    };
  return len + asso_values[(int) str[len - 1]] + asso_values[(int) str[0]];
}

const TAO_operation_db_entry *
TAO_acstcsServer_tcsServer_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 15,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 26,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 36,
      HASH_VALUE_RANGE = 32,
      DUPLICATES = 2,
      WORDLIST_SIZE = 20
    };

  static const TAO_operation_db_entry  wordlist[] =
    {
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"_is_a", &POA_acstcsServer::tcsServer::_is_a_skel, 0},
      {"badMethod", &POA_acstcsServer::tcsServer::badMethod_skel, 0},
      {"_component", &POA_acstcsServer::tcsServer::_component_skel, 0},
      {"_non_existent", &POA_acstcsServer::tcsServer::_non_existent_skel, 0},
      {"_repository_id", &POA_acstcsServer::tcsServer::_repository_id_skel, 0},
      {"descriptor", &POA_acstcsServer::tcsServer::descriptor_skel, 0},
      {"_get_name", &POA_acstcsServer::tcsServer::_get_name_skel, 0},
      {"_interface", &POA_acstcsServer::tcsServer::_interface_skel, 0},
      {"get_all_characteristics", &POA_acstcsServer::tcsServer::get_all_characteristics_skel, 0},
      {"displayMessage", &POA_acstcsServer::tcsServer::displayMessage_skel, 0},
      {"_get_currentPositionAlpha", &POA_acstcsServer::tcsServer::_get_currentPositionAlpha_skel, 0},
      {"_get_currentPositionDelta", &POA_acstcsServer::tcsServer::_get_currentPositionDelta_skel, 0},
      {"_get_componentState", &POA_acstcsServer::tcsServer::_get_componentState_skel, 0},
      {"find_characteristic", &POA_acstcsServer::tcsServer::find_characteristic_skel, 0},
      {"get_characteristic_by_name", &POA_acstcsServer::tcsServer::get_characteristic_by_name_skel, 0},
    };

  static const signed char lookup[] =
    {
       -1,  -1,  -1,  -1,  -1,   5,  -1,  -1,  -1,   6,   7,  -1,  -1,   8, 
        9,  10,  -1,  -1,  -1,  11,  12, -15,  -2,  13,  14, -40,  -1,  -1, 
       -1,  17,  -1,  -1,  -1,  -1,  18,  -1,  19, 
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          int slot = lookup[key];

          if (slot >= 0 && slot < WORDLIST_SIZE)
            {
              const char *s = wordlist[slot].opname;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
                return &wordlist[slot];
            }
          else if (slot < 0 && slot >= -MAX_HASH_VALUE)
            return 0;
          else
            {
              unsigned int offset = key + slot + (slot > 0 ? -MAX_HASH_VALUE : MAX_HASH_VALUE);
              const TAO_operation_db_entry  *base = &wordlist[-lookup[offset]];
              const TAO_operation_db_entry  *ptr = base + -lookup[offset + 1];

              while (--ptr >= base)
                if (*str == *ptr->opname && !strncmp (str + 1, ptr->opname + 1, len - 1))
                  return ptr;
            }
        }
    }
  return 0;
}

static TAO_acstcsServer_tcsServer_Perfect_Hash_OpTable tao_acstcsServer_tcsServer_optable;

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:984

TAO::Collocation_Proxy_Broker *
acstcsServer__TAO_tcsServer_Proxy_Broker_Factory_function ( ::CORBA::Object_ptr)
{
  return reinterpret_cast<TAO::Collocation_Proxy_Broker *> (0xdead); // Dummy
}

int
acstcsServer__TAO_tcsServer_Proxy_Broker_Factory_Initializer (size_t)
{
  acstcsServer__TAO_tcsServer_Proxy_Broker_Factory_function_pointer = 
    acstcsServer__TAO_tcsServer_Proxy_Broker_Factory_function;
  
  return 0;
}

static int
acstcsServer__TAO_tcsServer_Proxy_Broker_Stub_Factory_Initializer_Scarecrow =
  acstcsServer__TAO_tcsServer_Proxy_Broker_Factory_Initializer (
      reinterpret_cast<size_t> (acstcsServer__TAO_tcsServer_Proxy_Broker_Factory_Initializer)
    );

// TAO_IDL - Generated from 
// be/be_visitor_interface/interface_ss.cpp:103

POA_acstcsServer::tcsServer::tcsServer (void)
  : TAO_ServantBase ()
{
  this->optable_ = &tao_acstcsServer_tcsServer_optable;
}

POA_acstcsServer::tcsServer::tcsServer (const tcsServer& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs),
    POA_ACS::ACSComponent (rhs),
    POA_ACS::CharacteristicModel (rhs),
    POA_ACS::CharacteristicComponent (rhs)
{
}

POA_acstcsServer::tcsServer::~tcsServer (void)
{
}
namespace POA_acstcsServer
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:136
  
  class displayMessage_tcsServer
    : public TAO::Upcall_Command
  {
  public:
    inline displayMessage_tcsServer (
      POA_acstcsServer::tcsServer * servant)
      : servant_ (servant)
    {
    }
    
    virtual void execute (void)
    {
      this->servant_->displayMessage ();
    }
  
  private:
    POA_acstcsServer::tcsServer * const servant_;
  };
}


// TAO_IDL - Generated from 
// be/be_visitor_operation/operation_ss.cpp:190

void POA_acstcsServer::tcsServer::displayMessage_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */
  
  TAO::SArg_Traits< void>::ret_val retval;
  
  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);

  displayMessage_tcsServer command (
    impl);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

namespace POA_acstcsServer
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:136
  
  class badMethod_tcsServer
    : public TAO::Upcall_Command
  {
  public:
    inline badMethod_tcsServer (
      POA_acstcsServer::tcsServer * servant)
      : servant_ (servant)
    {
    }
    
    virtual void execute (void)
    {
      this->servant_->badMethod ();
    }
  
  private:
    POA_acstcsServer::tcsServer * const servant_;
  };
}


// TAO_IDL - Generated from 
// be/be_visitor_operation/operation_ss.cpp:190

void POA_acstcsServer::tcsServer::badMethod_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const exceptions[] = 
    {
      ACSErrTypeCommon::_tc_UnknownEx
    };
  static ::CORBA::ULong const nexceptions = 1;
#endif /* TAO_HAS_INTERCEPTORS */
  
  TAO::SArg_Traits< void>::ret_val retval;
  
  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);

  badMethod_tcsServer command (
    impl);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

namespace POA_acstcsServer
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:136
  
  class _get_currentPositionAlpha_tcsServer
    : public TAO::Upcall_Command
  {
  public:
    inline _get_currentPositionAlpha_tcsServer (
      POA_acstcsServer::tcsServer * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }
    
    virtual void execute (void)
    {
      TAO::SArg_Traits< ::ACS::RWdouble>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACS::RWdouble> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_->currentPositionAlpha ();
    }
  
  private:
    POA_acstcsServer::tcsServer * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}


// TAO_IDL - Generated from 
// be/be_visitor_operation/operation_ss.cpp:190

void POA_acstcsServer::tcsServer::_get_currentPositionAlpha_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */
  
  TAO::SArg_Traits< ::ACS::RWdouble>::ret_val retval;
  
  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);

  _get_currentPositionAlpha_tcsServer command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

namespace POA_acstcsServer
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:136
  
  class _get_currentPositionDelta_tcsServer
    : public TAO::Upcall_Command
  {
  public:
    inline _get_currentPositionDelta_tcsServer (
      POA_acstcsServer::tcsServer * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }
    
    virtual void execute (void)
    {
      TAO::SArg_Traits< ::ACS::RWdouble>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACS::RWdouble> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_->currentPositionDelta ();
    }
  
  private:
    POA_acstcsServer::tcsServer * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}


// TAO_IDL - Generated from 
// be/be_visitor_operation/operation_ss.cpp:190

void POA_acstcsServer::tcsServer::_get_currentPositionDelta_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */
  
  TAO::SArg_Traits< ::ACS::RWdouble>::ret_val retval;
  
  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);

  _get_currentPositionDelta_tcsServer command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}



// TAO_IDL - Generated from 
// be/be_visitor_interface/interface_ss.cpp:169

namespace POA_acstcsServer
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:136
  
  class _is_a_tcsServer_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _is_a_tcsServer_Upcall_Command (
      POA_acstcsServer::tcsServer * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }
    
    virtual void execute (void)
    {
      TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACE_InputCDR::to_boolean> (
          this->operation_details_,
          this->args_);
      
      TAO::SArg_Traits< ::CORBA::Char *>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< ::CORBA::Char *> (
          this->operation_details_,
          this->args_,
          1);
        
      retval =
        this->servant_-> _is_a (
          arg_1);
    }
  
  private:
    POA_acstcsServer::tcsServer * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}


void POA_acstcsServer::tcsServer::_is_a_skel (
    TAO_ServerRequest & server_request, 
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */
  
  TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_val retval;
  TAO::SArg_Traits< ::CORBA::Char *>::in_arg_val _tao_repository_id;
  
  TAO::Argument * const args[] =
    {
      &retval,
      &_tao_repository_id
    };
  
  static size_t const nargs = 2;
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);
  
  _is_a_tcsServer_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

namespace POA_acstcsServer
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:136
  
  class _non_existent_tcsServer_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _non_existent_tcsServer_Upcall_Command (
      POA_acstcsServer::tcsServer * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }
    
    virtual void execute (void)
    {
      TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACE_InputCDR::to_boolean> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_-> _non_existent ();
    }
  
  private:
    POA_acstcsServer::tcsServer * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}


void POA_acstcsServer::tcsServer::_non_existent_skel (
    TAO_ServerRequest & server_request, 
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */
  
  TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_val retval;
  
  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);
  
  _non_existent_tcsServer_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}
namespace POA_acstcsServer
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:136
  
  class _repository_id_tcsServer_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _repository_id_tcsServer_Upcall_Command (
      POA_acstcsServer::tcsServer * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }
    
    virtual void execute (void)
    {
      TAO::SArg_Traits< ::CORBA::Char *>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::CORBA::Char *> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_-> _repository_id ();
    }
  
  private:
    POA_acstcsServer::tcsServer * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}


void POA_acstcsServer::tcsServer::_repository_id_skel (
    TAO_ServerRequest & server_request, 
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */
  
  TAO::SArg_Traits< ::CORBA::Char *>::ret_val retval;
  
  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);
  
  _repository_id_tcsServer_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

// TAO_IDL - Generated from 
// be/be_visitor_interface/interface_ss.cpp:508

void POA_acstcsServer::tcsServer::_interface_skel (
    TAO_ServerRequest & server_request, 
    void * /* servant_upcall */,
    void * servant)
{
  TAO_IFR_Client_Adapter *_tao_adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );
    
  if (_tao_adapter == 0)
    {
      throw ::CORBA::INTF_REPOS (::CORBA::OMGVMCID | 1, ::CORBA::COMPLETED_NO);
    }
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);
  ::CORBA::InterfaceDef_ptr _tao_retval = impl->_get_interface ();
  server_request.init_reply ();
  TAO_OutputCDR &_tao_out = *server_request.outgoing ();
  
  ::CORBA::Boolean const _tao_result =
    _tao_adapter->interfacedef_cdr_insert (_tao_out, _tao_retval);
  
  _tao_adapter->dispose (_tao_retval);
  
  if (_tao_result == false)
    {
      throw ::CORBA::MARSHAL ();
    }
}

namespace POA_acstcsServer
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:136
  
  class _get_component_tcsServer_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _get_component_tcsServer_Upcall_Command (
      POA_acstcsServer::tcsServer * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }
    
    virtual void execute (void)
    {
      TAO::SArg_Traits< ::CORBA::Object>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::CORBA::Object> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_-> _get_component ();
    }
  
  private:
    POA_acstcsServer::tcsServer * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}


void POA_acstcsServer::tcsServer::_component_skel (
    TAO_ServerRequest & server_request, 
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant
  )
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */
  
  TAO::SArg_Traits< ::CORBA::Object>::ret_val retval;
  
  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;
  
  POA_acstcsServer::tcsServer * const impl =
    static_cast<POA_acstcsServer::tcsServer *> (servant);
  
  _get_component_tcsServer_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

::CORBA::Boolean POA_acstcsServer::tcsServer::_is_a (const char* value)
{
  return
    (
      !ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/ACSComponent:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/CharacteristicModel:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/CharacteristicComponent:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:alma/acstcsServer/tcsServer:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    );
}

const char* POA_acstcsServer::tcsServer::_interface_repository_id (void) const
{
  return "IDL:alma/acstcsServer/tcsServer:1.0";
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:926

void POA_acstcsServer::tcsServer::_dispatch (TAO_ServerRequest & req, void * servant_upcall)
{
  this->synchronous_upcall_dispatch (req, servant_upcall, this);
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:852

acstcsServer::tcsServer *
POA_acstcsServer::tcsServer::_this (void)
{
  TAO_Stub *stub = this->_create_stub ();
  
  TAO_Stub_Auto_Ptr safe_stub (stub);
  ::CORBA::Object_ptr tmp = CORBA::Object_ptr ();
  
  ::CORBA::Boolean const _tao_opt_colloc =
    stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ();
  
  ACE_NEW_RETURN (
      tmp,
      ::CORBA::Object (stub, _tao_opt_colloc, this),
      0
    );
  
  ::CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();
  
  typedef ::acstcsServer::tcsServer STUB_SCOPED_NAME;
  return
    TAO::Narrow_Utils<STUB_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        acstcsServer__TAO_tcsServer_Proxy_Broker_Factory_function_pointer
      );
}

#endif /* ifndef */

