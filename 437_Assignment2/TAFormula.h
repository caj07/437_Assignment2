#pragma once
#include "TAValue.h"

// Base class for formulaE
class TAFormula {
public:
	virtual TAValue & evaluate() = 0;
	virtual void list(ostream & os) const = 0;
	virtual const TAValue & getValue() const = 0;

private:
};