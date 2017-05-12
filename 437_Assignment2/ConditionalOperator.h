#pragma once
#include "TATerm.h"
#include "TAFormula.h"

class ConditionalOperator :
	public TATerm, public TAFormula
{
public:
	ConditionalOperator(TAFormula * conditional, TATerm * ifTrue, TATerm * ifFalse);
	virtual ~ConditionalOperator();

	// Inherited via TATerm
	virtual const TAType & getType() const override;
	virtual void list(ostream & os) const override;
	virtual TAValue & evaluate() override;

protected:
	ConditionalOperator();

private:
	TAFormula *m_conditional;
	TATerm *m_ifTrue, *m_ifFalse;

};

