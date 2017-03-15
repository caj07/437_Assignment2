#ifndef TAARRAYACCESS_HPP
#define TAARRAYACCESS_HPP

#include "TAPrimitive.hpp"
#include "TAArray.hpp"
#include "TAInt.hpp"

class TAArrayAccess : public TAPrimitive {
public:
	// The constructor takes in and saves references to the array and the index
	TAArrayAccess(TAArray &arr, const TANumber &index);

	// These functions set m_arr[m_arrIndex] into the value given
	// An exception is thrown if the types do not match
	void set(TAPrimitive &val);
	void set(double val);

	// This function calls the list() function of m_arr[m_arrIndex]
	void list() const;

private:
	// References to the array and to the index
	TAArray &m_arr;
	const TANumber &m_arrIndex;

	// Whenever set(double val) is called, a new object is created depending on the array type
	// This object is given an automatically created name with this index to prevent duplicate names
	static int m_numberOfNewlyCreatedPrimitiveObjects;
};

#endif