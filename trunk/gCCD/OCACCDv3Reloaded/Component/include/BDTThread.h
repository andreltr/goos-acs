#ifndef BDTTHREAD_H_
#define BDTTHREAD_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "acsThread.h"
#include "CCD.h"

class BDTThread : public ACS::Thread
      {
         public:
         BDTThread(const ACE_CString &name, CCDComponent * ccd_ptr,
                 const ACS::TimeInterval& responseTime=ThreadBase::defaultResponseTime,
                 const ACS::TimeInterval& sleepTime=ThreadBase::defaultSleepTime) :
                 ACS::Thread(name,responseTime,sleepTime)
         {
                 ACS_TRACE("BDTThread::BDTThread");
                 ccd_p = ccd_ptr;
		 queueSize = 0;
         }

         ~BDTThread()
         {
                 ACS_TRACE("BDTThread::~BDTThread");
         }

	 virtual void onStart();
	 virtual void onStop();
	 virtual void run();

	 void setQueue(std::string * filesQ, const int qSize);

	 /****************** [ variables ] *****************/
         private:

	 std::string * filesQueue;
	 int queueSize;
	 CCDComponent * ccd_p;
};

#endif
