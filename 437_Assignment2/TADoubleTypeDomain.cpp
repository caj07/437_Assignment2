#include "TADoubleTypeDomain.h"
#include "TADoubleType.h"

TADoubleTypeDomain::TADoubleTypeDomain(double start, double end, double step) : TATypeDomain(TADoubleType::the), m_start(start), m_end(end), m_step(step), m_current(start), m_endOfDomain(false)
{
}

const TAValue * TADoubleTypeDomain::firstElement()
{
	m_endOfDomain = false;
	m_current = m_start;
	return new TAValue(m_start);
}

const TAValue * TADoubleTypeDomain::next()
{
	if (m_current >= m_end || m_start > m_end || (long double)m_current + m_step > m_end) {
		m_endOfDomain = true;
		return NULL;
	}
	m_current = m_current + m_step;
	return new TAValue(m_current);
}

bool TADoubleTypeDomain::endOfDomain()
{
	return m_endOfDomain;
}