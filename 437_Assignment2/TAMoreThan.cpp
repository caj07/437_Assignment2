#include "TAMoreThan.hpp"
#include <iostream>

TAMoreThan::TAMoreThan(const TAInt &lhs, const TAInt &rhs) : TABool(), m_lhs(lhs), m_rhs(rhs) {
}

TAMoreThan::TAMoreThan(const std::string &name, const TAInt &lhs, const TAInt &rhs) : TABool(name), m_lhs(lhs), m_rhs(rhs) {
}

TAMoreThan::TAMoreThan(const TADouble &lhs, const TADouble &rhs) : TABool(), m_lhs(lhs), m_rhs(rhs) {
}

TAMoreThan::TAMoreThan(const std::string &name, const TADouble &lhs, const TADouble &rhs) : TABool(name), m_lhs(lhs), m_rhs(rhs) {
}

void TAMoreThan::list() const {
	std::cout << "(> ";
	m_lhs.list();
	std::cout << " ";
	m_rhs.list();
	std::cout << " )";
}

void TAMoreThan::evaluate() {
	TABool::set(m_lhs.getValue() > m_rhs.getValue());
}

void TAMoreThan::printState() const {
	if (TABool::getValue()) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
}