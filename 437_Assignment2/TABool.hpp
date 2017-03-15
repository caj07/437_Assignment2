#ifndef TABOOL_HPP
#define TABOOL_HPP

#include "TAPrimitive.hpp"

class TABool : public TAPrimitive {
public:
	// The only public constructor for TABool takes in a variable name as input, and saves it by calling the appropriate constructor from TAPrimitive
	TABool(const std::string &name);

	// Sets the value of TABool
	// This function takes in a double (so it can override the method in TAPrimitive), then saves it as a Boolean value
	void set(double value) override;

	// This function returns the Boolean value it has saved
	bool getValue() const;

protected:
	// Default constructor
	TABool();

private:
	// Value of the Boolean
	bool m_value;
};

#endif