#include "TAState.h"



TAState::TAState() : TAObj()
{
}


TAState::TAState(const std::string & name) : m_name(name)
{
}

TAState::~TAState()
{
}

std::string TAState::getName() const
{
	return m_name;
}

void TAState::list(std::ostream & os) const
{
	os << "State{" << m_name << "}";
}
