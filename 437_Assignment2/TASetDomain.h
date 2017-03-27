#pragma once

#include "TADomain.h"
#include "TAValue.h"
#include "TAArray.h"

class TASetDomain : public TADomain {
public:
	TASetDomain(const TAArray &set);
	const TAValue *firstElement();
	const TAValue *next();
	bool endOfDomain();

private:
	const TAValue *m_set;
	const int m_size;
	int m_pos;
};