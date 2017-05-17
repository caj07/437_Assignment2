#pragma once

#include "TAObj.h"
#include "TAInteraction.h"
#include <vector>

class TASystem : public TAObj
{
	TASystem();
	~TASystem();

	void addComponent(TAComponent* component);
	void addInteractions(TAInteraction* interaction);

	void prepareConflictFreeInteraction();
	void list(ostream & os);
	bool isDeadlock();
	void printState(ostream & os);
	void evaluate();
	void evaluate(int numberOfSteps);

private:
	std::vector<TAComponent*> m_components;
	std::vector<TAInteraction*> m_interactions;
	std::vector<TAInteraction*> m_nonConflictingInteractions;
	bool deadlock;
};