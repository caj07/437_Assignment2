#include "TAStateType.h"

TAStateType TAStateType::the;

unsigned int TAStateType::getTypeNumber() const
{
	return TA_STATE;
}

const string TAStateType::getTypeString() const
{
	return "state";
}

TAStateType::TAStateType()
{
}

TAStateType::~TAStateType()
{
}
