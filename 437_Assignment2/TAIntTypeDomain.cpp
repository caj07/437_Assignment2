#include "TAIntTypeDomain.h"
#include "TAIntType.h"

TAIntTypeDomain::TAIntTypeDomain(int start, int end, int step) : TATypeDomain(TAIntType::the), m_start(start), m_end(end), m_step(step), m_current(start), m_endOfDomain(false)
{
}

const TAValue * TAIntTypeDomain::firstElement()
{
	m_endOfDomain = false;
	m_current = m_start;
	return new TAValue(m_start);
}

const TAValue * TAIntTypeDomain::next()
{
	if (m_current >= m_end || m_start > m_end || (long)m_current + m_step > m_end) {
		m_endOfDomain = true;
		return NULL;
	}
	m_current = m_current + m_step;
	return new TAValue(m_current);
}

bool TAIntTypeDomain::endOfDomain()
{
	return m_endOfDomain;
}
