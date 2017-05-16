#pragma once
#include "TAStatement.h"
class TAEmptyStatement :
	public TAStatement
{
public:
	TAEmptyStatement();
	virtual ~TAEmptyStatement();

	// Inherited via TAStatement
	virtual void evaluate() override;
	virtual void list(ostream & os) const override;
};

