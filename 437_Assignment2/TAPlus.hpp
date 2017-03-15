#ifndef TAPLUS_HPP
#define TAPLUS_HPP

#include "TAOperation.hpp"
#include "TANumber.hpp"
#include "TAInt.hpp"
#include "TADouble.hpp"

class TAPlus : public TANumber, public TAOperation {
public:
	// TAPlus constructors take and save two references to numbers: either two TAInt or two TADouble objects
	// Names are optional
	TAPlus(const TAInt &lhs, const TAInt &rhs);
	TAPlus(const std::string &name, TAInt &lhs, const TAInt &rhs);
	TAPlus(const TADouble &lhs, const TADouble &rhs);
	TAPlus(const std::string &name, TADouble &lhs, const TADouble &rhs);

	// This function prints information about the operation and the two operands
	void list() const;

	// This function adds the two numbers declared in the constructor, and saves the result/state
	void evaluate();

	// This function prints the current state of the object
	// evaluate() should be called first
	void printState() const;

	// This function returns the state of the object
	// evaluate() should be called first
	double getValue() const;

private:
	// References to the two objects given in the constructor
	const TANumber &m_lhs, &m_rhs;

	// State of the object
	double m_value;
};

#endif