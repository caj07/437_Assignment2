#pragma once
#include "TAObj.h"
#include "TAState.h"
#include <ostream>

class TATransition :
	public TAObj
{
public:
	TATransition(TAState * initial, TAState * next);
	~TATransition();
	TAState * getInitial() const;
	TAState * getNext() const;

	void list(std::ostream & os);

protected:
	TATransition();

private:
	TAState *m_initial, *m_next;

	// Inherited via TAObj
	virtual const TAType & getType() const override;
};

