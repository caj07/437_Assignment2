#pragma once
#include "TAStatement.h"
#include "TAAtomicStatement.h"

class TAConcurrentStatements :
	public TAStatement
{
public:
	TAConcurrentStatements(TAAtomicStatement * head, TAStatement * tail);
	virtual ~TAConcurrentStatements();

	// Inherited via TAStatement
	virtual void evaluate() override;
	virtual void list(ostream & os) const override;

protected:
	TAConcurrentStatements();

private:
	TAAtomicStatement * m_head;
	TAStatement * m_tail;
};

