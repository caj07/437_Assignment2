#include "TAForEach.h"
#include "TAType.h"

TAForEach::TAForEach() :
	TATerm(), m_x(), m_domain(), m_formula()
{
}

TAForEach::TAForEach(TATerm * x, TADomain * domain, TAFormula * formula) :
	TATerm(), m_x(x), m_domain(domain), m_formula(formula)
{
}

TAForEach::~TAForEach()
{
}

const TAType & TAForEach::getType() const
{
	return TAType::getTypeInstance(TA_BOOL);
}

void TAForEach::list(ostream & os) const
{
	os << "ForAll ";
	m_x->list(os);
	os << " in ";
	m_domain->print(os);
	os << " ";
	m_formula->list(os);
}

TAValue & TAForEach::evaluate()
{
	for (m_x->val = *m_domain->firstElement(); !m_domain->endOfDomain(); m_x->val = *m_domain->next()) {
		m_formula->evaluate();
		if (m_formula->getValue().getBool()) {
			val.set(true);
			return  val;
		}
	}
	val.set(false);
	return val;
}
