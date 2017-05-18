#include "TATransition.h"



TATransition::TATransition() : TAObj(), m_initial(nullptr), m_next(nullptr)
{
}


TATransition::TATransition(TAState * initial, TAState * next) :
	TAObj(), m_initial(initial), m_next(next)
{
}

TATransition::~TATransition()
{
}

TAState * TATransition::getInitial() const
{
	return m_initial;
}

TAState * TATransition::getNext() const
{
	return m_next;
}

void TATransition::list(std::ostream & os)
{
	os << "Transition:{";
	m_initial->list(os);
	os << ",";
	m_next->list(os);
	os << "}";
}
