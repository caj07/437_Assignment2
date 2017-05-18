#pragma once
#include "TAType.h"
class TAInteractionType :
	public TAType
{
public:
	virtual ~TAInteractionType();

	virtual unsigned int getTypeNumber() const;
	virtual const string getTypeString() const;
	static TAInteractionType the;

private:
	TAInteractionType();
};

