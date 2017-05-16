#include "TAConditionalOperator.h"
#include "TAType.h"

TAConditionalOperator::TAConditionalOperator() :
	TATerm(), m_conditional(), m_ifTrue(), m_ifFalse()
{
}

const TAType & TAConditionalOperator::getType() const
{
	return m_ifTrue->getType();
}

void TAConditionalOperator::list(ostream & os) const
{
	m_conditional->list(os);
	os << " ? ";
	m_ifTrue->list(os);
	os << " : ";
	m_ifFalse->list(os);
}

TAValue & TAConditionalOperator::evaluate()
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


TAConditionalOperator::TAConditionalOperator(TAFormula * conditional, TATerm * ifTrue, TATerm * ifFalse) :
	TATerm(), m_conditional(conditional), m_ifTrue(ifTrue), m_ifFalse(ifFalse)
{
	if (ifTrue->getType().getTypeNumber() != ifFalse->getType().getTypeNumber()) {
		throw std::invalid_argument("Target terms are not of the same type");
	}
}

TAConditionalOperator::~TAConditionalOperator()
{
}
