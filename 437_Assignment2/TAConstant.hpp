#ifndef TACONSTANT_HPP
#define TACONSTANT_HPP

#include "TAInt.hpp"

class TAConstant : public TAInt {
public:
	// The constructor takes as input an integer that it saves
	TAConstant(int value);

private:
	// It isn't possible to change the constant value after creation
	using TAInt::set;
};

#endif