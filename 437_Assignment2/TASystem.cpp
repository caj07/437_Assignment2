#include "TASystem.h"
#include"TAType.h"
#include <algorithm>

TASystem::TASystem() : m_components(), m_interactions(), deadlock(false)
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

		for (std::vector<TAInteraction*>::iterator it2 = m_interactions.begin();it2 != m_interactions.end();++it2)
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
	os << "System{Interaction: ";
	for (std::vector<TAInteraction*>::iterator it = m_interactions.begin();it != m_interactions.end();++it)
	{
		(*it)->list(os);
		os << ", ";
	}

	os << ". Component: ";
	unsigned int componentSize = static_cast<unsigned int>(m_components.size());
	unsigned int i = 1;
	for (std::vector<TAComponent*>::iterator it = m_components.begin();it != m_components.end();++it)
	{
		(*it)->list(os);
		if (i < componentSize)
			os << ", ";
		i++;
	}
	os << "}";
}

bool TASystem::isDeadlock()
{
	return deadlock;
}

void TASystem::printState(ostream & os)
{
	os << "TASystem State{";
	
	os << isDeadlock() ? "Deadlocked, " : "Deadlock Free, ";
	if (m_nonConflictingInteractions.size() == 0)
	{
		os << isDeadlock() ? "No possible interaction to execute " : "Not ready to evaluate ";
	}
	else
	{ 
		os << isDeadlock() ? "No more possible interaction to execute " : "Ready to evaluate ";
	}
	os << "}" << endl;
}

void TASystem::evaluate()
{
	prepareConflictFreeInteraction();
	for (std::vector<TAInteraction*>::iterator it = m_nonConflictingInteractions.begin();it != m_nonConflictingInteractions.end();++it)
	{
		(*it)->evaluate();
	}
	m_nonConflictingInteractions.clear();
	deadlock = true;
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
		else
		{
			return;
		}
	}
}

const TAType & TASystem::getType() const
{
	return TAType::getTypeInstance(TA_SYSTEM);
}
