#include "TAComponentType.h"

TAComponentType TAComponentType::the;

unsigned int TAComponentType::getTypeNumber() const
{
	return TA_COMPONENT;
}

const string TAComponentType::getTypeString() const
{
	return "component";
}

TAComponentType::TAComponentType()
{
}

TAComponentType::~TAComponentType()
{
}
