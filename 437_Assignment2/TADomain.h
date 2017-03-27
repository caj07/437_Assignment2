#pragma once

#include "TAValue.h"

class TADomain : public TAObj
{
public:
	TADomain(const TAType &type);
	virtual const TAValue *firstElement() = 0;
	virtual const TAValue *next() = 0;
	virtual bool endOfDomain() = 0;

private:
	const TAType &m_type;
};