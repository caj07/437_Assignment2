#ifndef TAMINUS_HPP
#define TAMINUS_HPP

#include "TAOperation.hpp"
#include "TANumber.hpp"
#include "TAInt.hpp"
#include "TADouble.hpp"

class TAMinus : public TANumber, public TAOperation {
public:
	// The following TAMinus constructors take and save a reference to a number: either a TAInt or a TADouble object
	// Names are optional
	// The input is saved as the right-hand-side operand, the left-hand-side operand is initialized to ZERO (a static member of TAInt or TADouble)
	TAMinus(const TAInt &i);
	TAMinus(const std::string &name, const TAInt &i);
	TAMinus(const TADouble &d);
	TAMinus(const std::string &name, const TADouble &d);

	// The following TAMinus constructors take and save two references to numbers: either two TAInt or two TADouble objects
	// Names are optional
	TAMinus(const TAInt &lhs, const TAInt &rhs);
	TAMinus(const std::string &name, const TAInt &lhs, const TAInt &rhs);
	TAMinus(const TADouble &lhs, const TADouble &rhs);
	TAMinus(const std::string &name, const TADouble &lhs, const TADouble &rhs);

	// This function prints information about the operation and the operand(s)
	void list() const;

	// This function subtracts the right-hand-side number from the left-hand-side number, and saves the result/state
	void evaluate();

	// This function prints the current state of the object
	// evaluate() should be called first
	void printState() const;

	// This function returns the state of the object
	// evaluate() should be called first
	double getValue() const;

private:
	// References to the two objects given in the constructor (or reference to ZERO and the object given in the constructor)
	const TANumber &m_lhs, &m_rhs;

	// State of the object
	double m_value;
};

#endif