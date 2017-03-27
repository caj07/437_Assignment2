#include "TASetDomain.h"

TASetDomain::TASetDomain(const TAArray &set) : TADomain(set.getBaseType()), m_set(set.getValue().getArray()), m_size(set.getCapacity()), m_pos(0) {
	if (set.getBaseType().getTypeNumber() != TA_BOOL && set.getBaseType().getTypeNumber() != TA_INT && set.getBaseType().getTypeNumber() != TA_DOUBLE) {
		throw std::invalid_argument("Array base type should be a primitive type");
	}
}

const TAValue *TASetDomain::firstElement() {
	if (m_size == 0) {
		return NULL;
	}

	m_pos = 0;
	return &m_set[0];
}

const TAValue *TASetDomain::next() {
	++m_pos;
	if (m_size == 0 || endOfDomain()) {
		return NULL;
	}
	return &m_set[m_pos];
}

bool TASetDomain::endOfDomain() {
	if (m_pos >= m_size) {
		return true;
	}
	else {
		return false;
	}
}