#include "TAConditionalStatement.h"

TAConditionalStatement::TAConditionalStatement() :
	TAAtomicStatement(), m_condition(), m_ifTrue(), m_ifFalse()
{
}


TAConditionalStatement::TAConditionalStatement(TAFormula * condition, TAStatement * ifTrue, TAStatement * ifFalse) :
	TAAtomicStatement(), m_condition(condition), m_ifTrue(ifTrue), m_ifFalse(ifFalse)
{
}

TAConditionalStatement::~TAConditionalStatement()
{
}

void TAConditionalStatement::evaluate()
{
	if (m_condition->evaluate().getBool())
	{
		m_ifTrue->evaluate();
	}
	else
	{
		m_ifFalse->evaluate();
	}
}

void TAConditionalStatement::list(ostream & os) const
{
	os << "if (";
	m_condition->list(os);
	os << ") then ";
	m_ifTrue->list(os);
	os << " else ";
	m_ifFalse->list(os);
}
