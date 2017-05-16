#pragma once
#include "TAObj.h"
#include "TAState.h"

class TATransition :
	public TAObj
{
public:
	TATransition(TAState * initial, TAState * next);
	~TATransition();
	TAState * getInitial() const;
	TAState * getNext() const;

protected:
	TATransition();

private:
	TAState *m_initial, *m_next;
};

