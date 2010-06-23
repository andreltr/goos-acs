ACS::ROdouble_ptr CCDComponent::actualAirTemperature()
		throw (CORBA::SystemException) {
	if (!m_actualAirTemperature_sp) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_actualAirTemperature_sp->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::actualCCDTemperature()
		throw (CORBA::SystemException) {
	if (!m_actualCCDTemperature_sp) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_actualCCDTemperature_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWdouble_ptr CCDComponent::commandedCCDTemperature()
		throw (CORBA::SystemException) {
	if (!m_commandedCCDTemperature_sp) {
		return ACS::RWdouble::_nil();
	}
	ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
			m_commandedCCDTemperature_sp->getCORBAReference());
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

ACS::ROlong_ptr CCDComponent::cameraModel()
		throw (CORBA::SystemException) {
	if (!m_cameraModel_sp) {
		return ACS::ROlong::_nil();
	}
	ACS::ROlong_var prop = ACS::ROlong::_narrow(
			m_cameraModel_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWstring_ptr CCDComponent::filterName()
		throw (CORBA::SystemException) {
	if (!m_filterName_sp) {
		return ACS::RWstring::_nil();
	}
	ACS::RWstring_var prop = ACS::RWstring::_narrow(
			m_filterName_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWstring_ptr CCDComponent::objectName()
		throw (CORBA::SystemException) {
	if (!m_objectName_sp) {
		return ACS::RWstring::_nil();
	}
	ACS::RWstring_var prop = ACS::RWstring::_narrow(
			m_objectName_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWstring_ptr CCDComponent::observerName()
		throw (CORBA::SystemException) {
	if (!m_observerName_sp) {
		return ACS::RWstring::_nil();
	}
	ACS::RWstring_var prop = ACS::RWstring::_narrow(
			m_observerName_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWdouble_ptr CCDComponent::exposureTime()
		throw (CORBA::SystemException) {
	if (!m_exposureTime_sp) {
		return ACS::RWdouble::_nil();
	}
	ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
			m_exposureTime_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::acquisitionMode()
		throw (CORBA::SystemException) {
	if (!m_acquisitionMode_sp) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(
			m_acquisitionMode_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::numberOfAcquisitions()
		throw (CORBA::SystemException) {
	if (!m_numberOfAcquisitions_sp) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(
			m_numberOfAcquisitions_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWdouble_ptr CCDComponent::focalLength()
		throw (CORBA::SystemException) {
	if (!m_focalLength_sp) {
		return ACS::RWdouble::_nil();
	}
	ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
			m_focalLength_sp->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::gain()
		throw (CORBA::SystemException) {
	if (!m_gain_sp) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_gain_sp->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::xPixelSize()
		throw (CORBA::SystemException) {
	if (!m_xPixelSize_sp) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_xPixelSize_sp->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::yPixelSize()
		throw (CORBA::SystemException) {
	if (!m_yPixelSize_sp) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_yPixelSize_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::xStart()
		throw (CORBA::SystemException) {
	if (!m_xStart_sp) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(
			m_xStart_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::xEnd()
		throw (CORBA::SystemException) {
	if (!m_xEnd_sp) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(
			m_xEnd_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::yStart()
		throw (CORBA::SystemException) {
	if (!m_yStart_sp) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(
			m_yStart_sp->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::yEnd()
		throw (CORBA::SystemException) {
	if (!m_yEnd_sp) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(
			m_yEnd_sp->getCORBAReference());
	return prop._retn();
}

