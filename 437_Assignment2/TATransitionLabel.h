#pragma once
#include "TAObj.h"
#include "TAPort.h"
#include "TAFormula.h"
#include "TAStatement.h"
#include <ostream>

class TATransitionLabel :
	public TAObj
{
public:
	TATransitionLabel(TAPort * port, TAFormula * guard, TAStatement * action);
	~TATransitionLabel();

	TAPort * getPort() const;
	TAFormula * getGuard() const;
	TAStatement * getAction() const;

	void list(std::ostream & os);

protected:
	TATransitionLabel();

private:
	TAPort * m_port;
	TAFormula * m_guard;
	TAStatement * m_action;
};

