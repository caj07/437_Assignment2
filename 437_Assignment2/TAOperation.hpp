#ifndef TAOPERATION_HPP
#define TAOPERATION_HPP

#include "Type.hpp"

class TAOperation {
public:
	// Classes that implement TAOperation should provide the following functions
	// evaluate() computes and saves the state of the operation
	virtual void evaluate() = 0;

	// printState() prints the state of the operation
	// evaluate() should be called first
	virtual void printState() const = 0;
};

#endif