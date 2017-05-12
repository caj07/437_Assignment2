#pragma once
#include "TAObj.h"
#include "TAValue.h"

class TAStatement :
	public TAObj
{
public:
	virtual ~TAStatement();

	const TAType & getType() const;

	virtual void evaluate() = 0;
	virtual void list(ostream & os) const = 0;

protected:
	TAStatement();

};

