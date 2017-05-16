#pragma once
#include "TAStatement.h"
class TAAtomicStatement :
	public TAStatement
{
public:
	TAAtomicStatement();
	virtual ~TAAtomicStatement();

	virtual void concurrentEvaluate() = 0;
	virtual void concurrentAssign() = 0;
	
};

