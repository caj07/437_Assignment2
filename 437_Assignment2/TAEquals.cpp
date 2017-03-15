#include "TAEquals.hpp"
#include <iostream>

TAEquals::TAEquals(const TAInt &lhs, const TAInt &rhs) : TABool(), m_lhs(lhs), m_rhs(rhs) {
}

TAEquals::TAEquals(const std::string &name, const TAInt &lhs, const TAInt &rhs) : TABool(name), m_lhs(lhs), m_rhs(rhs) {
}

TAEquals::TAEquals(const TADouble &lhs, const TADouble &rhs) : TABool(), m_lhs(lhs), m_rhs(rhs) {
}

TAEquals::TAEquals(const std::string &name, const TADouble &lhs, const TADouble &rhs) : TABool(name), m_lhs(lhs), m_rhs(rhs) {
}

void TAEquals::list() const {
	std::cout << "(== ";
	m_lhs.list();
	std::cout << " ";
	m_rhs.list();
	std::cout << " )";
}

void TAEquals::evaluate() {
	TABool::set(m_rhs.getValue() == m_lhs.getValue());
}

void TAEquals::printState() const {
	if (TABool::getValue()) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
}