#include "CCDState.h"
#include "CCD.h"

CCDState::CCDState(CCDComponent * ccd) {
	ccd_p = ccd;
	strContext_p = new STRContext(ccd_p->getCCDModel());
}
