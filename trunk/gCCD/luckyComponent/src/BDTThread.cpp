#include "BDTThread.h"

/**
 * Implementation of BDThread. Used to ensure GUI responsiveness
 */

void BDTThread::run() {
	ACS_TRACE("BDTThread::run()");
	try {
		ACS_SHORT_LOG((LM_INFO, "BDTThread::run(): sender->connect"));
		ccd_p->sender->connect(ccd_p->receiver.in());

		/**Create an event with the filename, type, id, and total*/
		CCDmodule::ncCCDFilename * fileEvent;

		int i = 0;
		while (filesQueue[i] != "null") {
			ACS_SHORT_LOG((LM_INFO, "BDTThread::run(): startSend()"));
			ccd_p->sender->startSend(filesQueue[i].c_str());

			ACS_SHORT_LOG((LM_INFO, "BDTThread::run(): paceData()"));
			ccd_p->sender->paceData();

			ACS_SHORT_LOG((LM_INFO, "BDTThread::run(): stopSend()"));
			ccd_p->sender->stopSend();

			/**create an event with the filename, type, id, and total*/
			fileEvent = new CCDmodule::ncCCDFilename;
			fileEvent->type = CCDmodule::FILENAME;
			char fName[256];
			ACE_OS::strcpy(fName, filesQueue[i].c_str());
			ACE_OS::strcat(fName, "_out.fits");
			fileEvent->fileName = fName;
			fileEvent->id = i + 1;
			fileEvent->total = 3;

			ACS_SHORT_LOG(
					(LM_INFO, "BDTThread::run(): sendNotification() FILENAME"));
			/**Send the notification to the client*/
			ccd_p->ncSupplier->sendNotification(*fileEvent);
			ACS_SHORT_LOG((LM_INFO, "BDTThread::run(): notification sent!"));
			i++;
		}
		/**change event type to END_SUBSCRIPTION*/
		fileEvent->type = CCDmodule::END_SUBSCRIPTION;
		/**Send the notification to the client*/
		ACS_SHORT_LOG(
				(LM_INFO, "BDTThread::run(): sendNotification() END_SUBSCRIPTION"));
		ccd_p->ncSupplier->sendNotification(*fileEvent);
		ACS_SHORT_LOG((LM_INFO, "BDTThread::run(): notification sent!"));

		ACS_SHORT_LOG((LM_INFO, "BDTThread::run(): disconnect()"));
		ccd_p->sender->disconnect();

		ACS_SHORT_LOG((LM_INFO, "BDTThread::run(): closeReceiver()"));
		ccd_p->receiver->closeReceiver();
	}

	catch (AVConnectErrorEx & ex) {
		ACS_SHORT_LOG((LM_INFO, "AVConnectErrorEx exception catched !"));
		AVConnectErrorExImpl ex1(ex);
		ex1.log();
	} catch (AVStartSendErrorEx & ex) {
		ACS_SHORT_LOG((LM_INFO, "AVStartSendErrorEx exception catched !"));
		AVStartSendErrorExImpl ex1(ex);
		ex1.log();
	} catch (AVPaceDataErrorEx & ex) {
		ACS_SHORT_LOG((LM_INFO, "AVPaceDataErrorEx exception catched !"));
		AVPaceDataErrorExImpl ex1(ex);
		ex1.log();
	} catch (AVStopSendErrorEx & ex) {
		ACS_SHORT_LOG((LM_INFO, "AVStopSendErrorEx exception catched !"));
		AVStopSendErrorExImpl ex1(ex);
		ex1.log();
	} catch (AVDisconnectErrorEx & ex) {
		ACS_SHORT_LOG((LM_INFO, "AVDisconnectErrorEx exception catched !"));
		AVDisconnectErrorExImpl ex1(ex);
		ex1.log();
	} catch (AVCloseReceiverErrorEx & ex) {
		ACS_SHORT_LOG((LM_INFO, "AVCloseReceiverErrorEx exception catched !"));
		AVCloseReceiverErrorExImpl ex1(ex);
		ex1.log();
	} catch (...) {
		ACS_SHORT_LOG((LM_INFO, "UNKNOWN exception catched!"));
	}
}

void BDTThread::onStart() {
	ACS_TRACE("BDTThread::onStart()");
}

void BDTThread::onStop() {
	ACS_TRACE("BDTThread::onStop()");
	ACS_SHORT_LOG((LM_INFO, "BDT thread stopped."));
	ccd_p->context->setState(STATE_CONNECTED);
}

void BDTThread::setQueue(std::string * filesQ, const int qSize) {
	queueSize = qSize;
	filesQueue = filesQ;
}
