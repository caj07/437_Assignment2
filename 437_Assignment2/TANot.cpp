#include "TANot.hpp"
#include <iostream>

TANot::TANot(const TABool &b) : TABool(), m_b(b) {
}

TANot::TANot(const std::string &name, const TABool &b) : TABool(name), m_b(b) {
}

void TANot::list() const {
	std::cout << "(! ";
	m_b.list();
	std::cout << " )";
}

void TANot::evaluate() {
	TABool::set(!m_b.getValue());
}

void TANot::printState() const {
	if (TABool::getValue()) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
}