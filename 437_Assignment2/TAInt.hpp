#ifndef TAINT_HPP
#define TAINT_HPP

#include "TANumber.hpp"

class TAInt : public TANumber {
public:
	// The only public constructor for TAInt takes in a variable name as input, and saves it by calling the appropriate constructor from TANumber
	TAInt(const std::string &name);

	// Sets the value of TAInt
	// This function takes in a double (so it can override the method in TAPrimitive), then saves it as an integer
	void set(double value) override;

	// This function returns the integer value it has saved (as a double so it can override the method in TANumber)
	double getValue() const override;

	// This is the integer constant ZERO
	static const TAInt ZERO;

protected:
	// Default constructor
	TAInt();

private:
	// Private constructor that takes in a name and a value to save
	TAInt(const std::string &name, int value);

	// Value of the integer
	int m_value;
};

#endif