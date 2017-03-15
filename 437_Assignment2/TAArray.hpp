#ifndef TAARRAY_HPP
#define TAARRAY_HPP

#include "TAConstant.hpp"
#include <vector>

class TAArray : public TAPrimitive {
public:
	// The constructor takes in a name, a type and a constant size
	TAArray(const std::string &name, Type type, const TAConstant &size);

	// This function returns the array size
	int size() const;

	// This function returns a reference to the array member (a pointer to TAPrimitive) that corresponds to the index
	TAPrimitive *&accessArray(int index);

	// This function returns the type of the members of the array
	Type getMemberType() const;

	// This function prints the members of the array
	// Uninitialized members are printed as "uninitialized"
	void list() const;

private:
	// The array, its type and its size
	std::vector<TAPrimitive*> m_arr;
	Type m_memberType;
	int m_size;
};

#endif