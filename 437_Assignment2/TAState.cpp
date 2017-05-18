#include "TAState.h"
#include "TAType.h"


TAState::TAState() : TAObj()
{
}

const TAType & TAState::getType() const
{
	return TAType::getTypeInstance(TA_STATE);
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
