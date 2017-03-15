#include "TABool.hpp"
#include <iostream>

TABool::TABool(const std::string &name) : TAPrimitive(name), m_value() {
	setType(Type::boolType);
}

void TABool::set(double value) {
	m_value = value;
}

bool TABool::getValue() const {
	return m_value;
}

TABool::TABool() : TAPrimitive() {
	setType(Type::boolType);
}