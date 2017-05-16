#include "TAInteraction.h"

TAInteraction::TAInteraction() :m_components()
{
}

TAInteraction::TAInteraction(const TAInteraction & other)
{
}

TAInteraction & TAInteraction::operator=(const TAInteraction & rhs)
{
	return *this;
}

TAInteraction::~TAInteraction()
{
}

void TAInteraction::addComponent(TAComponent * component, TAPort * port)
{
	std::pair<TAComponent*, TAPort*> p = std::make_pair(component, port);
	m_pairs.push_back(p);
}

void TAInteraction::addGuard(TAFormula * guard)
{
	m_guard = guard;
}

void TAInteraction::addAction(TAStatement * statement)
{
	m_action = statement;
}

void TAInteraction::list(ostream & os)
{
	os << "Interaction{Components:";
	for (std::vector<std::pair<TAComponent*, TAPort*>>::iterator it = m_pairs.begin();it != m_pairs.end();++it)
	{
		(*it)->list(os);
		std::cout << ", ";
	}
	os << ". Guard:";
	m_guard->list(os);
	os << ". Action";
	m_action->list(os);
	os << "}" << std::endl;
}

bool TAInteraction::isReadyForExecution()
{
	m_guard->evaluate();
	if (!m_guard->getValue().getBool())
	{
		return false;
	}

	for (std::vector<TAComponent*>::iterator it = m_components.begin();it != m_components.end();++it)
	{
		if (!(*it)->isReady())
		{
			return false;
		}
	}

	return true;
}

void TAInteraction::evaluate()
{
	if (isReadyForExecution())
	{
		m_action->evaluate();
		for (std::vector<TAComponent*>::iterator it = m_components.begin();it != m_components.end();++it)
		{
			(*it)->evaluate();
		}
	}
}
