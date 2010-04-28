/*
 * "@(#) $Id: irisCameraFactory.h,v 1.4 2004/05/28 11:03:02 tjuerges Exp $"
 */

#ifndef irisCameraFactory_h
#define irisCameraFactory_h

#include <string>
#include <irisCamera.h>

class irisCameraFactory
{

  public:

    static irisCamera* getCamera(const std::string&);
};
#endif // irisCameraFactory_h
