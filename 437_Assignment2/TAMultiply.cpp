#include "TAMultiply.hpp"
#include <iostream>

TAMultiply::TAMultiply(const TAInt &lhs, const TAInt &rhs) : TANumber(), m_lhs(lhs), m_rhs(rhs) {
	setType(Type::intType);
}

TAMultiply::TAMultiply(const std::string &name, const TAInt &lhs, const TAInt &rhs) : TANumber(name), m_lhs(lhs), m_rhs(rhs) {
	setType(Type::intType);
}

TAMultiply::TAMultiply(const TADouble &lhs, const TADouble &rhs) : TANumber(), m_lhs(lhs), m_rhs(rhs) {
	setType(Type::doubleType);
}

TAMultiply::TAMultiply(const std::string &name, const TADouble &lhs, const TADouble &rhs) : TANumber(name), m_lhs(lhs), m_rhs(rhs) {
	setType(Type::doubleType);
}

void TAMultiply::list() const {
	std::cout << "(* ";
	m_lhs.list();
	std::cout << " ";
	m_rhs.list();
	std::cout << " )";
}

void TAMultiply::evaluate() {
	m_value = m_rhs.getValue() * m_lhs.getValue();
}

void TAMultiply::printState() const {
	if (TAPrimitive::type() == Type::intType) {
		std::cout << (int)m_value;
	}
	else {
		std::cout << m_value;
	}
}

double TAMultiply::getValue() const {
	return m_value;
}