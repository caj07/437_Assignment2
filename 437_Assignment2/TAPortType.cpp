#include "TAPortType.h"

TAPortType TAPortType::the;

unsigned int TAPortType::getTypeNumber() const
{
	return TA_PORT;
}

const string TAPortType::getTypeString() const
{
	return "port";
}

TAPortType::TAPortType()
{
}

TAPortType::~TAPortType()
{
}