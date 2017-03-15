#include "TALessThan.hpp"
#include <iostream>

TALessThan::TALessThan(const TAInt &lhs, const TAInt &rhs) : TABool(), m_lhs(lhs), m_rhs(rhs) {
}

TALessThan::TALessThan(const std::string &name, const TAInt &lhs, const TAInt &rhs) : TABool(name), m_lhs(lhs), m_rhs(rhs) {
}

TALessThan::TALessThan(const TADouble &lhs, const TADouble &rhs) : TABool(), m_lhs(lhs), m_rhs(rhs) {
}

TALessThan::TALessThan(const std::string &name, const TADouble &lhs, const TADouble &rhs) : TABool(name), m_lhs(lhs), m_rhs(rhs) {
}

void TALessThan::list() const {
	std::cout << "(< ";
	m_lhs.list();
	std::cout << " ";
	m_rhs.list();
	std::cout << " )";
}

void TALessThan::evaluate() {
	TABool::set(m_lhs.getValue() < m_rhs.getValue());
}

void TALessThan::printState() const {
	if (TABool::getValue()) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
}