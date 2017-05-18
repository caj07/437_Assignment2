#pragma once
#include "TAType.h"
class TATransitionType :
	public TAType
{
public:
	virtual ~TATransitionType();

	virtual unsigned int getTypeNumber() const;
	virtual const string getTypeString() const;
	static TATransitionType the;

private:
	TATransitionType();
};

