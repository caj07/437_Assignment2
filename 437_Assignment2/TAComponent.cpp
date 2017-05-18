#include "TAComponent.h"
#include "TAType.h"


TAComponent::TAComponent() :
	TAObj(), m_states(), m_currentState(), m_ports(), m_transitions(), m_transitionLabels(), m_transitionMap()
{
}

bool TAComponent::checkTransition(TATransition * transition)
{
	return (std::find(m_states.begin(), m_states.end(), transition->getInitial()) != m_states.end()) &&
		(std::find(m_states.begin(), m_states.end(), transition->getNext()) != m_states.end());
}

bool TAComponent::checkTransitionLabel(TATransitionLabel * transitionLabel)
{
	return std::find(m_ports.begin(), m_ports.end(), transitionLabel->getPort()) != m_ports.end();
}

bool TAComponent::checkTransitionMapping(TATransition * transition, TATransitionLabel * transitionLabel)
{
	return (std::find(m_transitions.begin(), m_transitions.end(), transition) != m_transitions.end()) &&
		(std::find(m_transitionLabels.begin(), m_transitionLabels.end(), transitionLabel) != m_transitionLabels.end());
}

TAComponent::TAComponent(const std::vector<TAState*>& states, TAState * initialState, const std::vector<TAPort*>& ports, 
	const std::vector<TATransition*>& transitions, const std::vector<TATransitionLabel*>& transitionLabels,
	const std::unordered_map<TATransition *, std::vector<TATransitionLabel *>>& transitionMap) :
	TAObj(), m_states(states), m_currentState(initialState), m_ports(ports), m_transitions(transitions),
	m_transitionLabels(transitionLabels), m_transitionMap(transitionMap)
{
	if (std::find(states.begin(), states.end(), initialState) == states.end())
	{
		throw std::invalid_argument("Initial state not in given states");
	}

	for (std::vector<TATransition*>::const_iterator it = transitions.begin(); it != transitions.end(); ++it)
	{
		if (!checkTransition(*it))
		{
			throw std::invalid_argument("Not all transitions are between given states");
		}
	}

	for (std::vector<TATransitionLabel*>::const_iterator it = transitionLabels.begin(); it != transitionLabels.end(); ++it)
	{
		if (!checkTransitionLabel(*it))
		{
			throw std::invalid_argument("Not all transition labels have ports in given ports");
		}
	}

	for (std::unordered_map<TATransition *, std::vector<TATransitionLabel *>>::const_iterator it = transitionMap.begin(); it != transitionMap.end(); ++it)
	{
		for (std::vector<TATransitionLabel*>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
		{
			if (!checkTransitionMapping(it->first, *it2))
			{
				throw std::invalid_argument("Not all mappings are between given transitions and given transition labels");
			}
		}
	}
}

TAComponent::TAComponent(const TAComponent & other) :
	TAObj(), m_states(other.m_states), m_currentState(other.m_currentState), m_ports(other.m_ports), m_transitions(other.m_transitions),
	m_transitionLabels(other.m_transitionLabels), m_transitionMap(other.m_transitionMap)
{
}

TAComponent::~TAComponent()
{
}

TAComponent & TAComponent::operator=(const TAComponent & rhs)
{
	m_states = rhs.m_states;
	m_currentState = rhs.m_currentState;
	m_ports = rhs.m_ports;
	m_transitions = rhs.m_transitions;
	m_transitionLabels = rhs.m_transitionLabels;
	m_transitionMap = rhs.m_transitionMap;
	return *this;
}

void TAComponent::addState(TAState * state)
{
	m_states.push_back(state);
}

void TAComponent::addPort(TAPort * port)
{
	m_ports.push_back(port);
}

void TAComponent::addTransition(TATransition * transition)
{
	if (checkTransition(transition))
	{
		m_transitions.push_back(transition);
	}
	else
	{
		throw std::invalid_argument("The transition is not between two given states");
	}
}

void TAComponent::addTransitionLabel(TATransitionLabel * transitionLabel)
{
	if (checkTransitionLabel(transitionLabel))
	{
		m_transitionLabels.push_back(transitionLabel);
	}
	else
	{
		throw std::invalid_argument("The transition label port is not given");
	}
}

void TAComponent::mapTransitionToTransitionLabel(TATransition * transition, TATransitionLabel * transitionLabel)
{
	if (checkTransitionMapping(transition, transitionLabel)) 
	{
		m_transitionMap[transition].push_back(transitionLabel);
	}
	else
	{
		throw std::invalid_argument("Mapping is not between a given transition and a given transition label");
	}
}

void TAComponent::list(ostream & os)
{
	std::cout << "Component{ states: ";
	for (TAState * state : m_states)
	{
		state->list(os);
		os << " ";
	}
	std::cout << "; current State: ";
	m_currentState->list(os);

	std::cout << "; ports: ";
	for (TAPort * port : m_ports)
	{
		port->list(os);
		os << " ";
	}
	std::cout << "; transitions: ";
	for (TATransition * transition : m_transitions)
	{
		transition->list(os);
		os << " ";
	}
	std::cout << "; transition labels: ";
	for (TATransitionLabel * transitionLabel : m_transitionLabels)
	{
		transitionLabel->list(os);
		os << " ";
	}
	os << "}" << std::endl;
}

void TAComponent::printVariableNames(ostream & os)
{
	for (std::vector<TATransitionLabel *>::const_iterator it = m_transitionLabels.begin(); it != m_transitionLabels.end(); ++it)
	{
		(*it)->getGuard()->list(os);
		(*it)->getAction()->list(os);
	}
}

void TAComponent::printState(ostream & os)
{
	m_currentState->list(os);
}

bool TAComponent::isReady(TAPort * port)
{
	for (std::unordered_map<TATransition *, std::vector<TATransitionLabel *>>::const_iterator it = m_transitionMap.begin(); it != m_transitionMap.end(); ++it)
	{
		if (it->first->getInitial() == m_currentState)
		{
			for (std::vector<TATransitionLabel *> ::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
			{
				TATransitionLabel * transitionLabel = *it2;
				if (transitionLabel->getPort() == port && transitionLabel->getGuard()->evaluate().getBool())
				{
					return true;
				}
			}
		}
	}
	return false;
}

TATransition * TAComponent::getTransitionAtCurrentState(TAPort * port)
{
	for (std::unordered_map<TATransition *, std::vector<TATransitionLabel *>>::const_iterator it = m_transitionMap.begin(); it != m_transitionMap.end(); ++it)
	{
		if (it->first->getInitial() == m_currentState)
		{
			for (std::vector<TATransitionLabel *> ::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
			{
				TATransitionLabel * transitionLabel = *it2;
				if (transitionLabel->getPort() == port && transitionLabel->getGuard()->evaluate().getBool())
				{
					return it->first;
				}
			}
		}
	}
	return nullptr;
}

void TAComponent::evaluate()
{
	std::vector< std::pair<TATransition *, TATransitionLabel *>> possibleTransitions;
	for (std::unordered_map<TATransition *, std::vector<TATransitionLabel *>>::const_iterator it = m_transitionMap.begin(); it != m_transitionMap.end(); ++it)
	{
		if (it->first->getInitial() == m_currentState)
		{
			for (std::vector<TATransitionLabel *> ::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
			{
				TATransitionLabel * transitionLabel = *it2;
				if (transitionLabel->getGuard()->evaluate().getBool())
				{
					possibleTransitions.push_back(std::pair<TATransition*, TATransitionLabel*>(it->first, transitionLabel));
				}
			}
		}
	}
	int size = possibleTransitions.size();
	if (size != 0)
	{
		std::pair<TATransition *, TATransitionLabel *> transition = possibleTransitions[rand() % size];
		m_currentState = transition.first->getNext();
		transition.second->getAction()->evaluate();
	}
}

const TAType & TAComponent::getType() const
{
	return TAType::getTypeInstance(TA_COMPONENT);
}
