#include "TAAssignmentStatement.h"
#include "TAType.h"
#include "TATerm.h"

TAAssignmentStatement::TAAssignmentStatement() :
	TAAtomicStatement(), m_target(), m_expression(), m_concurrentTemp()
{
}


TAAssignmentStatement::TAAssignmentStatement(TATerm * target, TATerm * expression) :
	TAAtomicStatement(), m_target(target), m_expression(expression), m_concurrentTemp()
{
	if (target->getType().getTypeNumber() != expression->getType().getTypeNumber()) {
		throw std::invalid_argument("Target and expression are not of the same type");
	}
}

TAAssignmentStatement::~TAAssignmentStatement()
{
}

void TAAssignmentStatement::concurrentEvaluate()
{
	m_concurrentTemp = &m_expression->evaluate();
}

void TAAssignmentStatement::concurrentAssign()
{
	m_target->val = *m_concurrentTemp;
	m_concurrentTemp = nullptr;
}

void TAAssignmentStatement::evaluate()
{
	m_target->val = m_expression->evaluate();
}

void TAAssignmentStatement::list(ostream & os) const
{
	m_target->list(os);
	os << " = ";
	m_expression->list(os);
}
