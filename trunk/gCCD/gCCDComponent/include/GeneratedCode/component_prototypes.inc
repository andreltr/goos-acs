virtual ACS::ROdouble_ptr actualAirTemperature() throw (CORBA::SystemException);
virtual ACS::ROdouble_ptr actualCCDTemperature() throw (CORBA::SystemException);
virtual ACS::RWdouble_ptr commandedCCDTemperature() throw (CORBA::SystemException);
virtual ACS::ROstring_ptr cameraName() throw (CORBA::SystemException);
virtual ACS::ROlong_ptr cameraModel() throw (CORBA::SystemException);
virtual ACS::RWstring_ptr filterName() throw (CORBA::SystemException);
virtual ACS::RWstring_ptr objectName() throw (CORBA::SystemException);
virtual ACS::RWstring_ptr observerName() throw (CORBA::SystemException);
virtual ACS::RWdouble_ptr exposureTime() throw (CORBA::SystemException);
virtual ACS::RWlong_ptr acquisitionMode() throw (CORBA::SystemException);
virtual ACS::RWlong_ptr numberOfAcquisitions() throw (CORBA::SystemException);
virtual ACS::RWdouble_ptr focalLength() throw (CORBA::SystemException);
virtual ACS::ROdouble_ptr gain() throw (CORBA::SystemException);
virtual ACS::ROdouble_ptr xPixelSize() throw (CORBA::SystemException);
virtual ACS::ROdouble_ptr yPixelSize() throw (CORBA::SystemException);
virtual ACS::RWlong_ptr xStart() throw (CORBA::SystemException);
virtual ACS::RWlong_ptr xEnd() throw (CORBA::SystemException);
virtual ACS::RWlong_ptr yStart() throw (CORBA::SystemException);
virtual ACS::RWlong_ptr yEnd() throw (CORBA::SystemException);
virtual ACS::RWstring_ptr ipAddress() throw (CORBA::SystemException);
virtual ACS::RWlong_ptr deviceType() throw (CORBA::SystemException);
virtual ACS::RWstring_ptr telescopeName() throw (CORBA::SystemException);