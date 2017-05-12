#include "TAConcurrentStatements.h"



TAConcurrentStatements::TAConcurrentStatements() :
	TAStatement(), m_head(), m_tail()
{
}


TAConcurrentStatements::TAConcurrentStatements(TAAtomicStatement * head, TAStatement * tail) :
	TAStatement(), m_head(head), m_tail(tail)
{
}

TAConcurrentStatements::~TAConcurrentStatements()
{
}

void TAConcurrentStatements::evaluate()
{
	m_head->concurrentEvaluate();
	m_tail->evaluate();
	m_head->concurrentAssign();
}

void TAConcurrentStatements::list(ostream & os) const
{
	m_head->list(os);
	os << " | ";
	m_tail->list(os);
}
