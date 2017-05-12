#pragma once
#include "TAAtomicStatement.h"
class TAAssignmentStatement :
	public TAAtomicStatement
{
public:
	TAAssignmentStatement(TATerm * target, TATerm * expression);
	virtual ~TAAssignmentStatement();

	// Inherited via TAAtomicStatement
	virtual void evaluate() override;
	virtual void list(ostream & os) const override;

protected:
	TAAssignmentStatement();

private:
	TATerm *m_target, *m_expression;
};

