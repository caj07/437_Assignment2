#pragma once
#include "TAType.h"
class TAStateType :
	public TAType
{
public:
	virtual ~TAStateType();

	virtual unsigned int getTypeNumber() const;
	virtual const string getTypeString() const;
	static TAStateType the;

private:
	TAStateType();
};

