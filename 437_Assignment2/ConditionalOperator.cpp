#include "ConditionalOperator.h"
#include "TAType.h"

ConditionalOperator::ConditionalOperator() :
	m_conditional(), m_ifTrue(), m_ifFalse()
{
}

const TAType & ConditionalOperator::getType() const
{
	return m_ifTrue->getType();
}

void ConditionalOperator::list(ostream & os) const
{
	m_conditional->list(os);
	os << " ? ";
	m_ifTrue->list(os);
	os << " : ";
	m_ifFalse->list(os);
}

TAValue & ConditionalOperator::evaluate()
{
	m_conditional->evaluate();
	if (m_conditional->getValue().getBool()) {
		m_ifTrue->evaluate();
		val = m_ifTrue->getValue();
		return val;
	}
	else {
		m_ifFalse->evaluate();
		val = m_ifFalse->getValue();
		return val;
	}
}


ConditionalOperator::ConditionalOperator(TAFormula * conditional, TATerm * ifTrue, TATerm * ifFalse) :
	m_conditional(conditional), m_ifTrue(ifTrue), m_ifFalse(ifFalse)
{
	if (ifTrue->getType().getTypeNumber() != ifFalse->getType().getTypeNumber()) {
		throw std::invalid_argument("Target terms are not of the same type");
	}
}

ConditionalOperator::~ConditionalOperator()
{
}
