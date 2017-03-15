#include "TAInt.hpp"
#include <iostream>

TAInt::TAInt(const std::string &name) : TANumber(name), m_value() {
	setType(Type::intType);
}

void TAInt::set(double value) {
	m_value = static_cast<int>(value);
}

double TAInt::getValue() const {
	return m_value;
}

TAInt::TAInt() : TANumber(), m_value() {
	setType(Type::intType);
}

TAInt::TAInt(const std::string &name, int value) : TANumber(name), m_value(value) {
	setType(Type::intType);
}

const TAInt TAInt::ZERO("ZERO_INT",0);