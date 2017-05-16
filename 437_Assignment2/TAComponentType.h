#pragma once
#include "TAType.h"
class TAComponentType :
	public TAType
{
public:
	virtual ~TAComponentType();

	virtual unsigned int getTypeNumber() const;
	virtual const string getTypeString() const;
	static TAComponentType the;

private:
	TAComponentType();
};

