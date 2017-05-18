#include "TAPort.h"
#include <ostream>


TAPort::TAPort() : TAObj()
{
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
