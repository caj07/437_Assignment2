#pragma once
#include "TAValueBase.h"
#include "TAPairType.h"


struct TAPairValue : public TAValueBase {
private:
	std::pair<TAValue, TAValue> values;
public:
	const TAPairType & type;

	TAPairValue(const TAPairType & t) :
		type(t)
	{
		initValuesPair();		
	}
	
	void initValuesPair() {
		values.first.set(type.baseType1.getDefaultValue());
		values.second.set(type.baseType2.getDefaultValue());
	}

	virtual const TAType & getType() const {
		return type;
	}

	virtual void set(TAValue & v1, TAValue & v2) {
		values.first.set(v1);
		values.second.set(v2);
	}

	virtual void setFirst(TAValue & v) {
		values.first.set(v);
	}
	virtual void setSecond(TAValue & v) {
		values.second.set(v);
	}

	virtual bool isPair() const { return true; }
	virtual TAValue & getFirst() { return values.first; }
	virtual TAValue & getSecond() { return values.second; }
	virtual std::pair<TAValue, TAValue> & getPair() { return values; }

	virtual void setValue(const TAValue & v) {
		assert(v.isPair());

		std::pair<TAValue, TAValue>* vs = v.getValue().getPair();
		set(vs->first, vs->second);
	}

	virtual void print(ostream & os) const {
		os << "<";
		values.first.print(os);
		os << ",";
		values.second.print(os);
		os << ">";
	}
	virtual TAValueBase * clone() const {
		TAPairValue * val = new TAPairValue(type);
		return val;
	}

};
