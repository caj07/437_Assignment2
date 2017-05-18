#include "TATransitionLabel.h"
#include "TAType.h"


TATransitionLabel::TATransitionLabel() : TAObj(), m_port(), m_guard(), m_action()
{
}

const TAType & TATransitionLabel::getType() const
{
	return TAType::getTypeInstance(TA_TRANSITIONLABEL);
}


TATransitionLabel::TATransitionLabel(TAPort * port, TAFormula * guard, TAStatement * action) :
	TAObj(), m_port(port), m_guard(guard), m_action(action)
{
}

TATransitionLabel::~TATransitionLabel()
{
}

TAPort * TATransitionLabel::getPort() const
{
	return m_port;
}

TAFormula * TATransitionLabel::getGuard() const
{
	return m_guard;
}

TAStatement * TATransitionLabel::getAction() const
{
	return m_action;
}

void TATransitionLabel::list(std::ostream & os)
{
	os << "TransitionLabel:{";
	m_port->list(os);
	os << ",";
	m_guard->list(os);
	os << ",";
	m_action->list(os);
	os << "}";
}
