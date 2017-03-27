#pragma once
#include "TANamedObj.h"
#include "TAPairType.h"

struct TAPair : public TANamedObj {
	TAPairType & type;



	TAPair(const string & name, TATerm & t1, TATerm & t2) :
		TANamedObj(name),
		type((TAPairType&)TAType::getPairTypeInstance(t1.getType(), t2.getType()))
	{
		val.set(type);
	}

	virtual const TAType & getType() const {
		return type;
	}

	virtual TAValue & evaluate() {
		return val;
	}

	virtual void printState(ostream & os) const {
		val.print(os);
	}
};
