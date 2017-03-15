#include "TACeiling.hpp"
#include <iostream>

TACeiling::TACeiling(const TADouble &d) : TAInt(), m_d(d) {
}

TACeiling::TACeiling(const std::string &name, const TADouble &d) : TAInt(name), m_d(d) {
}

void TACeiling::list() const {
	std::cout << "(ceiling ";
	m_d.list();
	std::cout << " )";
}

void TACeiling::evaluate() {
	TAInt::set(ceil(m_d.getValue()));
}

void TACeiling::printState() const {
	std::cout << TAInt::getValue();
}