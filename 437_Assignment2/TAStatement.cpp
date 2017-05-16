#include "TAStatement.h"
#include "TAType.h"


TAStatement::TAStatement() : TAObj()
{
}


TAStatement::~TAStatement()
{
}

const TAType & TAStatement::getType() const
{
	return TAType::getTypeInstance(TA_STATEMENT);
}