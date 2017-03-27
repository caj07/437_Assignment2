#pragma once

#include "TATypeDomain.h"
#include <climits>

class TADoubleTypeDomain : TATypeDomain {
public:
	TADoubleTypeDomain(double start = DBL_MIN, double end = DBL_MAX, double step = .1);
	const TAValue *firstElement();
	const TAValue *next();
	bool endOfDomain();

private:
	double m_start;
	double m_end;
	double m_step;
	double m_current;
	bool m_endOfDomain;
};