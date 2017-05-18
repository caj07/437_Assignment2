#include "TASystemType.h"

TASystemType TASystemType::the;

unsigned int TASystemType::getTypeNumber() const
{
	return TA_SYSTEM;
}

const string TASystemType::getTypeString() const
{
	return "system";
}

TASystemType::TASystemType()
{
}

TASystemType::~TASystemType()
{
}
