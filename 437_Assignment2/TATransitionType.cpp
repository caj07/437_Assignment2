#include "TATransitionType.h"

TATransitionType TATransitionType::the;

unsigned int TATransitionType::getTypeNumber() const
{
	return TA_TRANSITION;
}

const string TATransitionType::getTypeString() const
{
	return "transition";
}

TATransitionType::TATransitionType()
{
}

TATransitionType::~TATransitionType()
{
}