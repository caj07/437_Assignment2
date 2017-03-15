#ifndef TANUMBER_HPP
#define TANUMBER_HPP

#include "TAPrimitive.hpp"

class TANumber : public TAPrimitive {
public:
	// Abstract function subclasses need to implement that returns the value of the number
	virtual double getValue() const = 0;

protected:
	// These constructors call their equivalent constructors in TAPrimitive
	TANumber();
	TANumber(const std::string &name);
};

#endif