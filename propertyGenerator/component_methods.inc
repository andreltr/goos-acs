ACS::RWdouble_ptr CCDComponent::ccdTemp()
		throw (CORBA::SystemException) {
	if (!m_ccdTemp_sp) {
		return ACS::RWdouble::_nil();
	}
	ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
			m_ccdTemp_sp->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::actualTemp()
		throw (CORBA::SystemException) {
	if (!m_actualTemp_sp) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_actualTemp_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::acqMode()
		throw (CORBA::SystemException) {
	if (!m_acqMode_sp) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(
			m_acqMode_sp->getCORBAReference());
	return prop._retn();
}

ACS::ROstring_ptr CCDComponent::cameraName()
		throw (CORBA::SystemException) {
	if (!m_cameraName_sp) {
		return ACS::ROstring::_nil();
	}
	ACS::ROstring_var prop = ACS::ROstring::_narrow(
			m_cameraName_sp->getCORBAReference());
	return prop._retn();
}

