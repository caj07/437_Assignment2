#pragma once
#include "TAObj.h"
#include "TAState.h"
#include "TAPort.h"
#include "TATransitionLabel.h"
#include "TATransition.h"
#include <vector>
#include <unordered_map>

class TAComponent :
	public TAObj
{
public:
	TAComponent(const std::vector<TAState *> & states, TAState * initialState, const std::vector<TAPort *> & ports = std::vector<TAPort *>(),
		const std::vector<TATransition *> & transitions = std::vector<TATransition *>(),
		const std::vector<TATransitionLabel *> & transitionLabels = std::vector<TATransitionLabel *>(), const std::unordered_map<TATransition *,
		TATransitionLabel *> & transitionMap = std::unordered_map<TATransition *, TATransitionLabel *>());
	TAComponent(const TAComponent & other);
	virtual ~TAComponent();

	TAComponent & operator=(const TAComponent & rhs);

	void addState(TAState * state);
	void addPort(TAPort * port);
	void addTransition(TATransition * transition);
	void addTransitionLabel(TATransitionLabel * transitionLabel);
	void mapTransitionToTransitionLabel(TATransition * transition, TATransitionLabel * transitionLabel);

	void list(ostream & os);
	void printVariableNames(ostream & os);
	void printState(ostream & os);

	bool isReady(TAPort * port);
	TATransition * getTransitionAtCurrentState(TAPort * port);

	void evaluate();

	// Inherited via TAObj
	virtual const TAType & getType() const override;

protected:
	TAComponent();

private:
	std::vector<TAState *> m_states;
	TAState * m_currentState;
	std::vector<TAPort *> m_ports;
	std::vector<TATransition *> m_transitions;
	std::vector<TATransitionLabel *> m_transitionLabels;
	std::unordered_map<TATransition *, TATransitionLabel *> m_transitionMap;

	bool checkTransition(TATransition * transition);
	bool checkTransitionLabel(TATransitionLabel * transitionLabel);
	bool checkTransitionMapping(TATransition * transition, TATransitionLabel * transitionLabel);
};

