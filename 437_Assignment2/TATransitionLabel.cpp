#include "TATransitionLabel.h"



TATransitionLabel::TATransitionLabel() : TAObj(), m_port(), m_guard(), m_action()
{
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
