/*
 * "@(#) $Id: irisExport.h,v 1.2 2004/06/29 14:51:44 rlemke Exp $"
 */
#ifndef IRIS_EXPORT_H
#define IRIS_EXPORT_H

#include <acsutil.h>

/*  @file acsexmplExport.h
 *  Header file used for Win32 Export directives.
 *  
 *  Details goes here.
 */

#if !defined (IRIS_HAS_DLL)
#  define IRIS_HAS_DLL 1
#endif /* ! IRIS_HAS_DLL */

#if defined (IRIS_HAS_DLL) && (IRIS_HAS_DLL == 1)
#  if defined (IRIS_BUILD_DLL)
#    define IRIS_EXPORT ACS_DLL_EXPORT
#    define IRIS_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define IRIS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* IRIS_BUILD_DLL */
#    define IRIS_EXPORT ACS_DLL_IMPORT
#    define IRIS_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define IRIS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* IRIS_BUILD_DLL */
#else /* IRIS_HAS_DLL == 1 */
#  define IRIS_EXPORT
#  define IRIS_SINGLETON_DECLARATION(T)
#  define IRIS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* IRIS_HAS_DLL == 1 */

#endif /* IRIS_EXPORT_H */

// End of auto generated file.
