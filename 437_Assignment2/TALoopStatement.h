#pragma once
#include "TAAtomicStatement.h"
#include "TAFormula.h"

class TALoopStatement :
	public TAAtomicStatement
{
public:
	TALoopStatement(TAFormula * condition, TAStatement * statement);
	virtual ~TALoopStatement();

	// Inherited via TAAtomicStatement
	virtual void evaluate() override;
	virtual void list(ostream & os) const override;

protected:
	TALoopStatement();

private:
	TAFormula * m_condition;
	TAStatement * m_statement;

};

