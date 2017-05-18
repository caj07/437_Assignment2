#include "TAPort.h"
#include "TAType.h"
#include <ostream>


TAPort::TAPort() : TAObj()
{
}

const TAType & TAPort::getType() const
{
	return TAType::getTypeInstance(TA_PORT);
}


TAPort::TAPort(const std::string & name) : m_name(name)
{
}

TAPort::~TAPort()
{
}

std::string TAPort::getName() const
{
	return m_name;
}

void TAPort::list(std::ostream & os)
{
	os << "Port{" << m_name << "}";
}
