#include "TAStatementType.h"

TAStatementType TAStatementType::the;

unsigned int TAStatementType::getTypeNumber() const
{
	return TA_STATEMENT;
}

const string TAStatementType::getTypeString() const
{
	return "statement";
}

TAStatementType::TAStatementType()
{
}

TAStatementType::~TAStatementType()
{
}
