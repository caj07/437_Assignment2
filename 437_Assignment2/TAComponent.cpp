#include "TAComponent.h"
#include "TAType.h"


TAComponent::TAComponent()
{
}

bool TAComponent::checkTransition(TATransition * transition)
{
	return false;
}

bool TAComponent::checkTransitionLabel(TATransitionLabel * transitionLabel)
{
	return false;
}

bool TAComponent::checkTransitionMapping(TATransition * transition, TATransitionLabel * transitionLabel)
{
	return false;
}

TAComponent::TAComponent(const std::vector<TAState*>& states, TAState * initialState, const std::vector<TAPort*>& ports, 
	const std::vector<TATransition*>& transitions, const std::vector<TATransitionLabel*>& transitionLabels,
	const std::unordered_map<TATransition*, TATransitionLabel*>& transitionMap) :
	TAObj(), m_states(states), m_currentState(initialState), m_ports(ports), m_transitions(transitions),
	m_transitionLabels(transitionLabels), m_transitionMap(transitionMap)
{
	if (std::find(states.begin(), states.end(), initialState) == states.end())
	{
		throw std::invalid_argument("Initial state not in given states");
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
}

void TAComponent::addPort(TAPort * port)
{
}

void TAComponent::addTransition(TATransition * transition)
{
}

void TAComponent::addTransitionLabel(TATransitionLabel * transitionLabel)
{
}

void TAComponent::mapTransitionToTransitionLabel(TATransition * transition, TATransitionLabel * transitionLabel)
{
}

void TAComponent::list(ostream & os)
{
}

void TAComponent::printVariableNames(ostream & os)
{
}

void TAComponent::printState(ostream & os)
{
}

bool TAComponent::isReady(TAPort * port)
{
	return false;
}

TATransition * TAComponent::getTransitionAtCurrentState(TAPort * port)
{
	return nullptr;
}

void TAComponent::evaluate()
{
}

const TAType & TAComponent::getType() const
{
	return TAType::getTypeInstance(TA_COMPONENT);
}
