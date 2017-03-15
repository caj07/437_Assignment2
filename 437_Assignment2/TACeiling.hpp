#ifndef TACEILING_HPP
#define TACEILING_HPP

#include "TAInt.hpp"
#include "TAOperation.hpp"
#include "TADouble.hpp"

class TACeiling : public TAInt, public TAOperation {
public:
	// The constructors take as input a reference to a double and save it
	// The name is optional
	TACeiling(const TADouble &d);
	TACeiling(const std::string &name, const TADouble &d);

	// This function prints information about the operation and the operand
	void list() const;

	// This function evaluates the ceiling of the number, and saves the result/state
	void evaluate();

	// This function prints the current state of the object
	// evaluate() should be called first
	void printState() const;

private:
	// It isn't possible to manually change the value of this object
	using TAInt::set;

	// Reference to the double given in the constructor
	const TADouble &m_d;
};

#endif