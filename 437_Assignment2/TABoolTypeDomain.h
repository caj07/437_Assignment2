#pragma once

#include "TATypeDomain.h"

class TABoolTypeDomain : TATypeDomain {
public:
	TABoolTypeDomain();
	const TAValue *firstElement();
	const TAValue *next();
	bool endOfDomain();

private:
	bool m_current;
	bool m_endOfDomain;
};