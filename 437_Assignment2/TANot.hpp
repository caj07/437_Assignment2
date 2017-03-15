#ifndef TANOT_HPP
#define TANOT_HPP

#include "TABool.hpp"
#include "TAOperation.hpp"

class TANot : public TABool, public TAOperation {
public:
	// Constructor that takes in a references to a TABool variable so it can NOT it
	TANot(const TABool &b);

	// Constructor that takes in a variable name as well as a references to a TABool variable so it can NOT it
	TANot(const std::string &name, const TABool &b);

	// Lists the operation and the operand
	void list() const;

	// NOTs the TABool variable and saves the result/state
	void evaluate();

	// Prints the state
	// Should be called after evaluate()
	void printState() const;

private:
	// The function set() cannot be used on TANot objects
	using TABool::set;

	// Reference to the TABool object given in constructor
	const TABool &m_b;
};

#endif