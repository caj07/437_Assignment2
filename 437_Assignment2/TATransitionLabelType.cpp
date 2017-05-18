#include "TATransitionLabelType.h"

TATransitionLabelType TATransitionLabelType::the;

unsigned int TATransitionLabelType::getTypeNumber() const
{
	return TA_TRANSITIONLABEL;
}

const string TATransitionLabelType::getTypeString() const
{
	return "transitionLabel";
}

TATransitionLabelType::TATransitionLabelType()
{
}

TATransitionLabelType::~TATransitionLabelType()
{
}
