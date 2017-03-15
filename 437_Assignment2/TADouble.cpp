#include "TADouble.hpp"
#include <iostream>

TADouble::TADouble(const std::string &name) : TANumber(name), m_value() {
	setType(Type::doubleType);
}

void TADouble::set(double value) {
	m_value = value;
}

double TADouble::getValue() const {
	return m_value;
}

TADouble::TADouble() : TANumber(), m_value() {
	setType(Type::doubleType);
}

TADouble::TADouble(const std::string &name, double value) : TANumber(name), m_value(value) {
	setType(Type::intType);
}

const TADouble TADouble::ZERO("ZERO_DOUBLE", 0.);