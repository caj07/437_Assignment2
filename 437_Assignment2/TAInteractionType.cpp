#include "TAInteractionType.h"

TAInteractionType TAInteractionType::the;

unsigned int TAInteractionType::getTypeNumber() const
{
	return TA_INTERACTION;
}

const string TAInteractionType::getTypeString() const
{
	return "interaction";
}

TAInteractionType::TAInteractionType()
{
}

TAInteractionType::~TAInteractionType()
{
}
