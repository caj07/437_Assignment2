#include "TAFloor.hpp"
#include <iostream>

TAFloor::TAFloor(const TADouble &d) : TAInt(), m_d(d) {
}

TAFloor::TAFloor(const std::string &name, const TADouble &d) : TAInt(name), m_d(d) {
}

void TAFloor::list() const {
	std::cout << "(floor ";
	m_d.list();
	std::cout << " )";
}

void TAFloor::evaluate() {
	TAInt::set(floor(m_d.getValue()));
}

void TAFloor::printState() const {
	std::cout << TAInt::getValue();
}