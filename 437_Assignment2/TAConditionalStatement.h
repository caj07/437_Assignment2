#pragma once
#include "TAAtomicStatement.h"
#include "TAFormula.h"

class TAConditionalStatement :
	public TAAtomicStatement
{
public:
	TAConditionalStatement(TAFormula * condition, TAStatement * ifTrue, TAStatement * ifFalse);
	virtual ~TAConditionalStatement();

	// Inherited via TAAtomicStatement
	virtual void evaluate() override;
	virtual void list(ostream & os) const override;

protected:
	TAConditionalStatement();

private:
	TAFormula *m_condition;
	TAStatement *m_ifTrue, *m_ifFalse;
};

