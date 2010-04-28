/*
 *
 * "@(#) $Id: irisExport.h,v 1.11  2009/12/04 10:37:25  mparra Exp $"
 *
 * $Log: irisExport.h,v $
 * Revision 1.11  2009/12/04 10:37:25  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.10  2005/03/09 14:33:58  tjuerges
 * - Changed filename because Doxagen is irritated by the wrong one.
 *
 *
 */

#ifndef irisExport_h
#define irisExport_h

#include <acsutil.h>

/* @file irisExport.h
 *  Header file used for Win32 Export directives.
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
