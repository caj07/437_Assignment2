#pragma once
#include "TAType.h"
class TASystemType :
	public TAType
{
public:
	virtual ~TASystemType();

	virtual unsigned int getTypeNumber() const;
	virtual const string getTypeString() const;
	static TASystemType the;

private:
	TASystemType();
};

