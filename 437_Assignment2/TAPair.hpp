#ifndef TAPAIR_HPP
#define TAPAIR_HPP

#include "TAPrimitive.hpp"

class TAPair : public TAPrimitive {
public:
	// The constructors take references to two items and save them
	// Providing a name is optional
	TAPair(TAPrimitive &lhs, TAPrimitive &rhs);
	TAPair(const std::string &name, TAPrimitive &lhs, TAPrimitive &rhs);

	// These two functions return a reference to one of the members of the pair
	TAPrimitive& first();
	TAPrimitive& next();

	// This function prints information about the two items it references
	void list() const;

private:
	// References given in the constructor
	TAPrimitive &m_lhs, &m_rhs;
};

#endif