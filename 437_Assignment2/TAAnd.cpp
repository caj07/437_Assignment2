#include "TAAnd.hpp"
#include <iostream>

TAAnd::TAAnd(const TABool &lhs, const TABool &rhs) : TABool(), m_lhs(lhs), m_rhs(rhs) {
}

TAAnd::TAAnd(const std::string &name, const TABool &lhs, const TABool &rhs) : TABool(name), m_lhs(lhs), m_rhs(rhs) {
}

void TAAnd::list() const {
	std::cout << "(& ";
	m_lhs.list();
	std::cout << " ";
	m_rhs.list();
	std::cout << " )";
}

void TAAnd::evaluate() {
	TABool::set(m_rhs.getValue() && m_lhs.getValue());
}

void TAAnd::printState() const {
	if (TABool::getValue()) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
}