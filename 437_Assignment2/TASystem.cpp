#include "TASystem.h"
#include <algorithm>

TASystem::TASystem() : m_components(), m_interactions()
{
}

TASystem::~TASystem()
{
}

void TASystem::addComponent(TAComponent * component)
{
	m_components.push_back(component);
}

void TASystem::addInteractions(TAInteraction * interaction)
{
	m_interactions.push_back(interaction);
}

void TASystem::prepareConflictFreeInteraction()
{
	bool fail = false;
	for (std::vector<TAInteraction*>::iterator it = m_interactions.begin();it != m_interactions.end();++it)
	{
		m_nonConflictingInteractions.push_back((*it));

		for (std::vector<TAInteraction*>::iterator it2 = m_interactions.begin() ;it2 != m_interactions.end();++it2)
		{
			std::vector<std::pair<TAComponent*, TAPort*>> p1 = (*it)->getPairs();
			for (std::vector<std::pair<TAComponent*, TAPort*>>::iterator pit = p1.begin(); pit != p1.end();++it2)
			{
				std::vector<std::pair<TAComponent*, TAPort*>> p2 = (*it2)->getPairs();
				for (std::vector<std::pair<TAComponent*, TAPort*>>::iterator pit2 = p2.begin(); pit2 != p2.end();++it2)
				{
					if (pit->first == pit2->first)
					{
						//there is a conflict: if it does not exist keep it else remove it
						if (std::find(m_nonConflictingInteractions.begin(), m_nonConflictingInteractions.end(), *it2) != m_nonConflictingInteractions.end())
						{
							m_nonConflictingInteractions.erase(std::remove(m_nonConflictingInteractions.begin(), m_nonConflictingInteractions.end(), *it), m_nonConflictingInteractions.end());
							fail = true;
							break;
						}					
					}
				}
				if (fail) { break; };
			}
			if (fail) { break; };
		}
		fail = false;
	}
}

void TASystem::list(ostream & os)
{
}

bool TASystem::isDeadlock()
{
	return false;
}

void TASystem::printState(ostream & os)
{
}

void TASystem::evaluate()
{
	prepareConflictFreeInteraction();
	for (std::vector<TAInteraction*>::iterator it = m_nonConflictingInteractions.begin();it != m_nonConflictingInteractions.end();++it)
	{
		(*it)->evaluate();
	}
}

void TASystem::evaluate(int numberOfSteps)
{
	int count = 0;
	prepareConflictFreeInteraction();
	for (std::vector<TAInteraction*>::iterator it = m_nonConflictingInteractions.begin();it != m_nonConflictingInteractions.end();++it)
	{
		count++;
		if (count < numberOfSteps)
		{
			(*it)->evaluate();
		}
	}
}
