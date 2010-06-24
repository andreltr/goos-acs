#include "CCDStatesHeaders/CCDState.h"
//#include "CCD.h"

CCDState::CCDState(CCDComponent* ccd, STRContext* strContext) {
	ccd_p = ccd;
	strContext_p = strContext;
	/*strContext_p = new STRContext(ccd_p->getCCDModel(),
	 ccd_p->getComponentProperties());*/
}

CCDState::~CCDState() {
	/*if (strContext_p != 0) {
	 delete strContext_p;
	 }*/
}
