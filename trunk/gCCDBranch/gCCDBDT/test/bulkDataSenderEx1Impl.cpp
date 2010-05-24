#include "bulkDataSenderEx1Impl.h"

using namespace ACSBulkDataError;

BulkDataSenderEx1Impl::BulkDataSenderEx1Impl(const ACE_CString& name,maci::ContainerServices* containerServices) :
    BulkDataSenderDefaultImpl(name,containerServices)
{
    ACS_TRACE("BulkDataSenderEx1Impl::BulkDataSenderEx1Impl");
}


BulkDataSenderEx1Impl::~BulkDataSenderEx1Impl()
{
    ACS_TRACE("BulkDataSenderEx1Impl::~BulkDataSenderEx1Impl");
}



void BulkDataSenderEx1Impl::startSend(const char * currFilename)
{
    ACS_TRACE("BulkDataSenderEx1Impl::startSend");

    try
	{

	int size;
	CORBA::ULong flowNumber;
	/******************************** flow 3 *********************************/

	size = 256;

	//ACS_SHORT_LOG((LM_DEBUG,"IMAGEN SIN EXT %s", currFilename));
    
	char outputFilename[size];

	//Name of the received file

	//currFilename: name of the file to be read without extension "NAME"
	//fileName: name of the output file (received file) "NAME_out.bmp"
	//currentFilename: name of the input file "NAME.bmp"
	ACE_OS::strcpy(outputFilename, currFilename);
	ACE_OS::strcat(outputFilename, "_out.fits");

	ACE_OS::strcpy(inputFilename, currFilename);
	ACE_OS::strcat(inputFilename, ".fits");
	
	//ACS_SHORT_LOG((LM_DEBUG,"IMAGEN CON EXT %s", outputFilename));

	const char * ptr = outputFilename;

	flowNumber = 3;
	getSender()->startSend(flowNumber,ptr,size);
    
	ACS_SHORT_LOG ((LM_DEBUG,"flow 3 start parameter sent = %s", outputFilename));

	}

    catch (AVInvalidFlowNumberExImpl & ex)
	{   
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::startSend AVInvalidFlowNumberExImpl exception catched !"));
	AVStartSendErrorExImpl err = AVStartSendErrorExImpl(ex,__FILE__,__LINE__,"BulkDataSenderImpl::startSend");
	throw err.getAVStartSendErrorEx();
	}
    catch (AVSendFrameErrorExImpl & ex)
	{   
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::startSend AVSendFrameErrorExImpl exception catched !"));
	AVStartSendErrorExImpl err = AVStartSendErrorExImpl(ex,__FILE__,__LINE__,"BulkDataSenderImpl::startSend");
	throw err.getAVStartSendErrorEx();
	}
    catch (AVFlowEndpointErrorExImpl & ex)
	{   
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::startSend  AVFlowEndpointErrorExImplexception catched !"));
	AVStartSendErrorExImpl err = AVStartSendErrorExImpl(ex,__FILE__,__LINE__,"BulkDataSenderImpl::startSend");
	throw err.getAVStartSendErrorEx();
	}
    catch (AVProtocolErrorExImpl & ex)
	{   
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::startSend  AVProtocolErrorExImplexception catched !"));
	AVStartSendErrorExImpl err = AVStartSendErrorExImpl(ex,__FILE__,__LINE__,"BulkDataSenderImpl::startSend");
	throw err.getAVStartSendErrorEx();
	}
    catch (...)
	{
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::startSend UNKNOWN exception"));
	AVStartSendErrorExImpl err = AVStartSendErrorExImpl(__FILE__,__LINE__,"BulkDataSenderImpl::startSend");
	throw err.getAVStartSendErrorEx();
	}
}


void BulkDataSenderEx1Impl::paceData()
{
    ACS_TRACE("BulkDataSenderImpl::paceData");

    try
	{
	CORBA::ULong flowNumber;

	/******************************** flow 3 *********************************/


	ACE_Message_Block mb(BUFSIZ);

	//Name of the file to send
	FILE * fp = ACE_OS::fopen(inputFilename,"r");
	if (fp == 0)
	    {
	    ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl<>::paceData file not open successfully"));
	    AVCouldNotOpenFileExImpl err = AVCouldNotOpenFileExImpl(__FILE__,__LINE__,"BulkDataSenderImpl::paceData");
	    throw err;
	    }
	
	// Continue to send data till the file is read to the end.
	while (1)
	    {
	    // Read from the file into a message block.
	    int n = ACE_OS::fread(mb.rd_ptr (),
				  1,
				  mb.size (),
				  fp);
	
	    if (n < 0)
		{
		ACS_SHORT_LOG((LM_DEBUG," BulkDataSenderImpl<>::paceData sending file"));
		break;
		}	

	    if (n == 0)
		{
		if (feof (fp))
		    {
		    // At end of file break the loop and end the client.
		    ACS_SHORT_LOG((LM_DEBUG,"BulkDataSenderImpl<>::paceData end of file"));
		    break;
		    }
		}
	
	    mb.wr_ptr (n);
	

	    flowNumber = 3;
	    getSender()->sendData(flowNumber,&mb);
    
	    ACS_SHORT_LOG ((LM_DEBUG,"flow 3 file %s sent", inputFilename));

	    // Reset the mb.
	    mb.reset ();	
	    } // end while
	
	// Close the input file
	ACE_OS::fclose(fp);	    

	}

    catch (AVInvalidFlowNumberExImpl & ex)
	{   
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::paceData AVInvalidFlowNumberExImpl exception catched !"));
	AVPaceDataErrorExImpl err = AVPaceDataErrorExImpl(ex,__FILE__,__LINE__,"BulkDataSenderImpl::paceData");
	throw err.getAVPaceDataErrorEx();
	}
    catch (AVSendFrameErrorExImpl & ex)
	{
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::paceData AVSendFrameErrorExImpl exception catched !"));
	AVPaceDataErrorExImpl err = AVPaceDataErrorExImpl(ex,__FILE__,__LINE__,"BulkDataSenderImpl::paceData");
	throw err.getAVPaceDataErrorEx();
	}
    catch (AVCouldNotOpenFileExImpl & ex)
	{
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::paceData AVCouldNotOpenFileExImpl exception catched !"));
	AVPaceDataErrorExImpl err = AVPaceDataErrorExImpl(ex,__FILE__,__LINE__,"BulkDataSenderImpl::paceData");
	throw err.getAVPaceDataErrorEx();
	}
    catch (...)
	{
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::paceData UNKNOWN exception"));
	AVPaceDataErrorExImpl err = AVPaceDataErrorExImpl(__FILE__,__LINE__,"BulkDataSenderImpl::paceData");
	throw err.getAVPaceDataErrorEx();
	}
}


void BulkDataSenderEx1Impl::stopSend()
{
    ACS_TRACE("BulkDataSenderImpl::stopSend");

    try
	{
	CORBA::ULong flowNumber = 3;
	getSender()->stopSend(flowNumber);
	}

    catch (AVInvalidFlowNumberExImpl & ex)
	{   
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::stopSend AVInvalidFlowNumberExImpl exception catched !"));
	AVStopSendErrorExImpl err = AVStopSendErrorExImpl(ex,__FILE__,__LINE__,"BulkDataSenderImpl::stopSend");
	throw err.getAVStopSendErrorEx();
	}
    catch (...)
	{
	ACS_SHORT_LOG((LM_INFO,"BulkDataSenderImpl::stopSend UNKNOWN exception"));
	AVStopSendErrorExImpl err = AVStopSendErrorExImpl(__FILE__,__LINE__,"BulkDataSenderImpl::stopSend");
	throw err.getAVStopSendErrorEx();
	}
}

/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(BulkDataSenderEx1Impl)
/* ----------------------------------------------------------------*/


