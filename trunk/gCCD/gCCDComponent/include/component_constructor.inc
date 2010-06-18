CCDComponent::CCDComponent(const ACE_CString& name,
		maci::ContainerServices * containerServices) :
	CharacteristicComponentImpl(name, containerServices),
			m_actualAirTemperature_sp(this), m_actualCCDTemperature_sp(this),
			m_commandedCCDTemperature_sp(this), m_cameraName_sp(this),
			m_cameraModel_sp(this), m_filterName_sp(this),
			m_objectName_sp(this), m_observerName_sp(this), m_exposureTime_sp(
					this), m_acquisitionMode_sp(this),
			m_numberOfAcquisitions_sp(this), m_focalLength_sp(this), m_gain_sp(
					this), m_xPixelSize_sp(this), m_yPixelSize_sp(this),
			m_xStart_sp(this), m_xEnd_sp(this), m_yStart_sp(this), m_yEnd_sp(
					this) {
	m_actualAirTemperature_sp = new ROdouble(name + ":actualAirTemperature",
			getComponent());
	m_actualCCDTemperature_sp = new ROdouble(name + ":actualCCDTemperature",
			getComponent());
	m_commandedCCDTemperature_sp = new RWdouble(name
			+ ":commandedCCDTemperature", getComponent());
	m_cameraName_sp = new ROstring(name + ":cameraName", getComponent());
	m_cameraModel_sp = new ROlong(name + ":cameraModel", getComponent());
	m_filterName_sp = new RWstring(name + ":filterName", getComponent());
	m_objectName_sp = new RWstring(name + ":objectName", getComponent());
	m_observerName_sp = new RWstring(name + ":observerName", getComponent());
	m_exposureTime_sp = new RWdouble(name + ":exposureTime", getComponent());
	m_acquisitionMode_sp
			= new RWlong(name + ":acquisitionMode", getComponent());
	m_numberOfAcquisitions_sp = new RWlong(name + ":numberOfAcquisitions",
			getComponent());
	m_focalLength_sp = new RWdouble(name + ":focalLength", getComponent());
	m_gain_sp = new ROdouble(name + ":gain", getComponent());
	m_xPixelSize_sp = new ROdouble(name + ":xPixelSize", getComponent());
	m_yPixelSize_sp = new ROdouble(name + ":yPixelSize", getComponent());
	m_xStart_sp = new RWlong(name + ":xStart", getComponent());
	m_xEnd_sp = new RWlong(name + ":xEnd", getComponent());
	m_yStart_sp = new RWlong(name + ":yStart", getComponent());
	m_yEnd_sp = new RWlong(name + ":yEnd", getComponent());
}
