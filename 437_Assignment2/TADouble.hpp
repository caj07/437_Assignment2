#ifndef TADOUBLE_HPP
#define TADOUBLE_HPP

#include "TANumber.hpp"

class TADouble : public TANumber {
public:
	// The only public constructor for TADouble takes in a variable name as input, and saves it by calling the appropriate constructor from TANumber
	TADouble(const std::string &name);

	// Sets the value of TADouble
	// This function takes in a double and saves it
	void set(double value) override;

	// This function returns the double value it has saved
	double getValue() const override;

	// This is the double constant ZERO
	static const TADouble ZERO;

protected:
	// Default constructor
	TADouble();

private:
	// Private constructor that takes in a name and a value to save
	TADouble(const std::string &name, double value);

	// Value of the double
	double m_value;
};

#endif