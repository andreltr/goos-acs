	m_actualAirTemperature_sp->getDevIO()->write(
		componentProperties->getactualAirTemperature(), timestamp);
	m_actualCCDTemperature_sp->getDevIO()->write(
		componentProperties->getactualCCDTemperature(), timestamp);
	m_cameraName_sp->getDevIO()->write(
		componentProperties->getcameraName().c_str(), timestamp);
	m_cameraModel_sp->getDevIO()->write(
		componentProperties->getcameraModel(), timestamp);
	m_gain_sp->getDevIO()->write(
		componentProperties->getgain(), timestamp);
	m_xPixelSize_sp->getDevIO()->write(
		componentProperties->getxPixelSize(), timestamp);
	m_yPixelSize_sp->getDevIO()->write(
		componentProperties->getyPixelSize(), timestamp);
	commandedCCDTemperature()->set_sync(
		componentProperties->getcommandedCCDTemperature());
	filterName()->set_sync(
		componentProperties->getfilterName().c_str());
	objectName()->set_sync(
		componentProperties->getobjectName().c_str());
	observerName()->set_sync(
		componentProperties->getobserverName().c_str());
	exposureTime()->set_sync(
		componentProperties->getexposureTime());
	acquisitionMode()->set_sync(
		componentProperties->getacquisitionMode());
	numberOfAcquisitions()->set_sync(
		componentProperties->getnumberOfAcquisitions());
	focalLength()->set_sync(
		componentProperties->getfocalLength());
	xStart()->set_sync(
		componentProperties->getxStart());
	xEnd()->set_sync(
		componentProperties->getxEnd());
	yStart()->set_sync(
		componentProperties->getyStart());
	yEnd()->set_sync(
		componentProperties->getyEnd());
