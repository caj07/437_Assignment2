#ifndef TAPRIMITIVE_HPP
#define TAPRIMITIVE_HPP

#include "Type.hpp"
#include <string>

// Parent class of all classes
class TAPrimitive {
public:
	// Returns the object type
	Type type() const;

	// Unless it is overriden, this function prints the name of the variable
	virtual void list() const;

	// Unless it is overriden, this function does nothing
	// It isn't purely virtual/abstract because it is optional to implement it
	virtual void set(double d);

protected:
	// All constructors are protected because this is an abstract class
	// Default constructor calls the default constructor of m_name
	TAPrimitive();

	// This constructor initializes m_name to the given name
	// If the name already exists, an exception is thrown
	TAPrimitive(const std::string &name);

	// This function takes in a type and sets the object type to it
	void setType(Type t);

private:
	// Object type
	Type m_type;

	// Object name
	std::string m_name;
};

#endif