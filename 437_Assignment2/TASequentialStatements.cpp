#include "TASequentialStatements.h"



TASequentialStatements::TASequentialStatements() : 
	TAStatement(), m_head(), m_tail()
{
}

void TASequentialStatements::evaluate()
{
	m_head->evaluate();
	m_tail->evaluate();
}

void TASequentialStatements::list(ostream & os) const
{
	m_head->list(os);
	os << "; ";
	m_tail->list(os);
}


TASequentialStatements::TASequentialStatements(TAAtomicStatement * head, TAStatement * tail) :
	TAStatement(), m_head(head), m_tail(tail)
{
}

TASequentialStatements::~TASequentialStatements()
{
}
