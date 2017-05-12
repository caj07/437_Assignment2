#include "TAAssignmentStatement.h"
#include "TAType.h"
#include "TATerm.h"

TAAssignmentStatement::TAAssignmentStatement() :
	TAAtomicStatement(), m_target(), m_expression()
{
}


TAAssignmentStatement::TAAssignmentStatement(TATerm * target, TATerm * expression) :
	TAAtomicStatement(), m_target(target), m_expression(expression)
{
	if (target->getType().getTypeNumber() != expression->getType().getTypeNumber()) {
		throw std::invalid_argument("Target and expression are not of the same type");
	}
}

TAAssignmentStatement::~TAAssignmentStatement()
{
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
