#pragma once
#include "TATerm.h"
#include "TAFormula.h"
#include "TADomain.h"

class TAForEach :
	public TATerm, public TAFormula
{
public:
	TAForEach(TATerm * x, TADomain * domain, TAFormula * formula);
	virtual ~TAForEach();

	// Inherited via TATerm
	virtual const TAType & getType() const override;
	virtual void list(ostream & os) const override;
	virtual TAValue & evaluate() override;

protected:
	TAForEach();

private:
	TATerm * m_x;
	TADomain * m_domain;
	TAFormula * m_formula;
};

