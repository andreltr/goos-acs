#include "CCDStatesHeaders/CCDState.h"

CCDState::CCDState(CCDComponent* ccd, STRContext* strContext) {
	ccd_p = ccd;
	strContext_p = strContext;
}

CCDState::~CCDState() {
}
