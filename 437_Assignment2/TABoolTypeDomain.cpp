#include "TABoolTypeDomain.h"
#include "TABoolType.h"

TABoolTypeDomain::TABoolTypeDomain() : TATypeDomain(TABoolType::the), m_current(true), m_endOfDomain(false) {
}

const TAValue * TABoolTypeDomain::firstElement()
{
	m_current = true;
	return new TAValue(true);
}

const TAValue * TABoolTypeDomain::next()
{
	if (!m_current) {
		m_endOfDomain = true;
		return NULL;
	}
	m_current = false;
	return new TAValue(false);
}

bool TABoolTypeDomain::endOfDomain()
{
	return m_endOfDomain;
}
