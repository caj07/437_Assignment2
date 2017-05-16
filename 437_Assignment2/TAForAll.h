#pragma once
#include "TAFormula.h"
#include "TADomain.h"
#include "TABool.h"

class TAForAll :
	public TATerm, public TAFormula
{
public:
	TAForAll(TATerm * x, TADomain * domain, TAFormula * formula);
	virtual ~TAForAll();

	// Inherited via TATerm
	virtual const TAType & getType() const override;
	virtual void list(ostream & os) const override;
	virtual TAValue & evaluate() override;

protected:
	TAForAll();

private:
	TATerm * m_x;
	TADomain * m_domain;
	TAFormula * m_formula;
};

