#pragma once
#include "TAObj.h"
#include "TAComponent.h"
#include <vector>
#include "TAFormula.h"
#include "TAStatement.h"

class TAInteraction : public TAObj
{
public:
	TAInteraction();
	TAInteraction(const TAInteraction& other);
	TAInteraction & operator=(const TAInteraction& rhs);
	~TAInteraction();

	void addComponent(TAComponent * component, TAPort* port);
	void addGuard(TAFormula * guard);
	void addAction(TAStatement * statement);
	std::vector<std::pair<TAComponent*, TAPort*>> getPairs();


	void list(ostream & os);

	bool isReadyForExecution();

	void evaluate();

private:
	std::vector<std::pair<TAComponent*,TAPort*>> m_pairs;
	TAFormula * m_guard;
	TAStatement * m_action;

};