#include "TADomain.h"

TADomain::TADomain(const TAType &type) : TAObj(), m_type(type) {
}

const TAType &TADomain::getType() const {
	return m_type;
}