#include "TADivide.hpp"
#include <iostream>

TADivide::TADivide(const TAInt &lhs, const TAInt &rhs) : TANumber(), m_lhs(lhs), m_rhs(rhs) {
	setType(Type::intType);
}

TADivide::TADivide(const std::string &name, const TAInt &lhs, const TAInt &rhs) : TANumber(name), m_lhs(lhs), m_rhs(rhs) {
	setType(Type::intType);
}

TADivide::TADivide(const TADouble &lhs, const TADouble &rhs) : TANumber(), m_lhs(lhs), m_rhs(rhs) {
	setType(Type::doubleType);
}

TADivide::TADivide(const std::string &name, const TADouble &lhs, const TADouble &rhs) : TANumber(name), m_lhs(lhs), m_rhs(rhs) {
	setType(Type::doubleType);
}

void TADivide::list() const {
	std::cout << "(/ ";
	m_lhs.list();
	std::cout << " ";
	m_rhs.list();
	std::cout << " )";
}

void TADivide::evaluate() {
	m_value = m_lhs.getValue() / m_rhs.getValue();
}

void TADivide::printState() const {
	if (TAPrimitive::type() == Type::intType) {
		std::cout << (int)m_value;
	}
	else {
		std::cout << m_value;
	}
}

double TADivide::getValue() const {
	return m_value;
}