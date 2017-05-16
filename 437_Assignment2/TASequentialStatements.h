#pragma once

#include "TAStatement.h"
#include "TAAtomicStatement.h"

class TASequentialStatements :
	public TAStatement
{
public:
	TASequentialStatements(TAAtomicStatement * head, TAStatement * tail);
	virtual ~TASequentialStatements();

	// Inherited via TAStatement
	virtual void evaluate() override;
	virtual void list(ostream & os) const override;

protected:
	TASequentialStatements();

private:
	TAAtomicStatement * m_head;
	TAStatement * m_tail;
};

