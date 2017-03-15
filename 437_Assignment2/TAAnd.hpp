#ifndef TAAND_HPP
#define TAAND_HPP

#include "TABool.hpp"
#include "TAOperation.hpp"

class TAAnd : public TABool, public TAOperation {
public:
	// Constructor that takes in two references to TABool variables so it can AND them
	TAAnd(const TABool &lhs, const TABool &rhs);

	// Constructor that takes in a variable name as well as two references to TABool variables so it can AND them
	TAAnd(const std::string &name, const TABool &lhs, const TABool &rhs);

	// Lists the operation and the two operands
	void list() const;

	// ANDs the two TABool variables and saves the result/state
	void evaluate();

	// Prints the state
	// Should be called after evaluate()
	void printState() const;

private:
	// The function set() cannot be used on TAXor objects
	using TABool::set;

	// References to the two TABool objects given in constructor
	const TABool &m_lhs, &m_rhs;
};

#endif