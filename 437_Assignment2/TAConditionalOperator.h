#pragma once
#include "TATerm.h"
#include "TAFormula.h"

class TAConditionalOperator :
	public TATerm, public TAFormula
{
public:
	TAConditionalOperator(TAFormula * conditional, TATerm * ifTrue, TATerm * ifFalse);
	virtual ~TAConditionalOperator();

	// Inherited via TATerm
	virtual const TAType & getType() const override;
	virtual void list(ostream & os) const override;
	virtual TAValue & evaluate() override;

protected:
	TAConditionalOperator();

private:
	TAFormula *m_conditional;
	TATerm *m_ifTrue, *m_ifFalse;

};

