#pragma once
#include "TAType.h"
class TAPortType :
	public TAType
{
public:
	virtual ~TAPortType();

	virtual unsigned int getTypeNumber() const;
	virtual const string getTypeString() const;
	static TAPortType the;

private:
	TAPortType();
};

