#include "TAPair.hpp"
#include <iostream>

TAPair::TAPair(TAPrimitive &lhs, TAPrimitive &rhs) : TAPrimitive(), m_lhs(lhs), m_rhs(rhs) {
	TAPrimitive::setType(Type::pairType);
}


TAPair::TAPair(const std::string &name, TAPrimitive &lhs, TAPrimitive &rhs) : TAPrimitive(name), m_lhs(lhs), m_rhs(rhs) {
	TAPrimitive::setType(Type::pairType);
}

TAPrimitive& TAPair::first() {
	return m_lhs;
}

TAPrimitive& TAPair::next() {
	return m_rhs;
}

void TAPair::list() const {
	std::cout << "(";
	m_lhs.list();
	std::cout << ", ";
	m_rhs.list();
	std::cout << ")";
}