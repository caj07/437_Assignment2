#include "TABool.h"

TAValue & TABool::evaluate()
{
	return TAPrimitive::evaluate();
}

void TABool::list(ostream & os) const
{
	TAPrimitive::list(os);
}

const TAValue & TABool::getValue() const
{
	return TAPrimitive::getValue();
}
