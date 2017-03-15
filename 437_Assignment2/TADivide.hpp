#ifndef TADIVIDE_HPP
#define TADIVIDE_HPP

#include "TAOperation.hpp"
#include "TANumber.hpp"
#include "TAInt.hpp"
#include "TADouble.hpp"

class TADivide : public TANumber, public TAOperation {
public:
	// TADivide constructors take and save two references to numbers: either two TAInt or two TADouble objects
	// Names are optional
	TADivide(const TAInt &lhs, const TAInt &rhs);
	TADivide(const std::string &name, const TAInt &lhs, const TAInt &rhs);
	TADivide(const TADouble &lhs, const TADouble &rhs);
	TADivide(const std::string &name, const TADouble &lhs, const TADouble &rhs);

	// This function prints information about the operation and the two operands
	void list() const;

	// This function divides the two numbers declared in the constructor, and saves the result/state
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