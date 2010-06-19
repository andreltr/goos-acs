CCDComponent::CCDComponent(const ACE_CString& name,
		maci::ContainerServices * containerServices) :
	CharacteristicComponentImpl(name, containerServices)
			, m_ccdTemp_sp(this)
			, m_actualTemp_sp(this)
			, m_acqMode_sp(this)
			, m_cameraName_sp(this)
{
	m_ccdTemp_sp = new RWdouble(name + ":ccdTemp", getComponent());
	m_actualTemp_sp = new ROdouble(name + ":actualTemp", getComponent());
	m_acqMode_sp = new RWlong(name + ":acqMode", getComponent());
	m_cameraName_sp = new ROstring(name + ":cameraName", getComponent());
}
