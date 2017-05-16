#include "TALoopStatement.h"



TALoopStatement::TALoopStatement() :
	TAAtomicStatement(), m_condition(), m_statement()
{
}


TALoopStatement::TALoopStatement(TAFormula * condition, TAStatement * statement) :
	TAAtomicStatement(), m_condition(condition), m_statement(statement)
{
}

TALoopStatement::~TALoopStatement()
{
}

void TALoopStatement::evaluate()
{
	while (m_condition->evaluate().getBool()) 
	{
		m_statement->evaluate();
	}
}

void TALoopStatement::list(ostream & os) const
{
	os << "while ";
	m_condition->list(os);
	os << " do ";
	m_statement->list(os);
}

void TALoopStatement::concurrentEvaluate()
{
	evaluate();
}

void TALoopStatement::concurrentAssign()
{
}
