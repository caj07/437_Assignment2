#include "TAXor.hpp"
#include <iostream>

TAXor::TAXor(const TABool &lhs, const TABool &rhs) : TABool(), m_lhs(lhs), m_rhs(rhs) {
}

TAXor::TAXor(const std::string &name, TABool &lhs, const TABool &rhs) : TABool(name), m_lhs(lhs), m_rhs(rhs) {
}

void TAXor::list() const {
	std::cout << "(XOR ";
	m_lhs.list();
	std::cout << " ";
	m_rhs.list();
	std::cout << " )";
}

void TAXor::evaluate() {
	TABool::set(m_rhs.getValue() != m_lhs.getValue());
}

void TAXor::printState() const {
	if (TABool::getValue()) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
}