#include "TAForAll.h"
#include "TAType.h"

TAForAll::TAForAll() :
	TATerm(), m_x(), m_domain(), m_formula()
{
}

TAForAll::TAForAll(TATerm * x, TADomain * domain, TAFormula * formula) :
	TATerm(), m_x(x), m_domain(domain), m_formula(formula)
{
}

TAForAll::~TAForAll()
{
}

const TAType & TAForAll::getType() const
{
	return TAType::getTypeInstance(TA_BOOL);
}

void TAForAll::list(ostream & os) const
{
	os << "ForAll ";
	m_x->list(os);
	os << " in ";
	m_domain->print(os);
	os << " ";
	m_formula->list(os);
}

TAValue & TAForAll::evaluate()
{
	for (m_x->val = *m_domain->firstElement(); !m_domain->endOfDomain(); m_x->val = *m_domain->next()) {
		m_formula->evaluate();
		if (!m_formula->getValue().getBool()) {
			val.set(false);
			return  val;
		}
	}
	val.set(true);
	return val;
}
