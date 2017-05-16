#pragma once
#include "TAObj.h"
#include "TAPort.h"
#include "TAFormula.h"
#include "TAStatement.h"

class TATransitionLabel :
	public TAObj
{
public:
	TATransitionLabel(TAPort * port, TAFormula * guard, TAStatement * action);
	~TATransitionLabel();

	TAPort * getPort() const;
	TAFormula * getGuard() const;
	TAStatement * getAction() const;

protected:
	TATransitionLabel();

private:
	TAPort * m_port;
	TAFormula * m_guard;
	TAStatement * m_action;
};

