#pragma once

#include "TATypeDomain.h"
#include <climits>

class TAIntTypeDomain : TATypeDomain {
public:
	TAIntTypeDomain(int start = INT_MIN, int end = INT_MAX, int step = 1);
	const TAValue *firstElement();
	const TAValue *next();
	bool endOfDomain();

private:
	int m_start;
	int m_end;
	int m_step;
	int m_current;
	bool m_endOfDomain;
};