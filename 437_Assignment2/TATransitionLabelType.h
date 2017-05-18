#pragma once
#include "TAType.h"
class TATransitionLabelType :
	public TAType
{
public:
	virtual ~TATransitionLabelType();

	virtual unsigned int getTypeNumber() const;
	virtual const string getTypeString() const;
	static TATransitionLabelType the;

private:
	TATransitionLabelType();
};

