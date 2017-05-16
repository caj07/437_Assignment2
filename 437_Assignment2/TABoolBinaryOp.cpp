#include "TABoolBinaryOp.h"

TAValue & TABoolBinaryOp::evaluate()
{
	return TABinaryOp::evaluate();
}

void TABoolBinaryOp::list(ostream & os) const
{
	return TABinaryOp::list(os);
}

const TAValue & TABoolBinaryOp::getValue() const
{
	return TABinaryOp::getValue();
}
