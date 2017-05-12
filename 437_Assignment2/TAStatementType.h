#pragma once
#include "TAType.h"
class TAStatementType :
	public TAType
{
public:
	virtual ~TAStatementType();

	virtual unsigned int getTypeNumber() const;
	virtual const string getTypeString() const;
	static TAStatementType the;

private:
	TAStatementType();
};

