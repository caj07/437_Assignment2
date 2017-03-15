#include "TAPrimitive.hpp"
#include <stdexcept>
#include <iostream>
#include <unordered_set>

Type TAPrimitive::type() const {
	return m_type;
}

void TAPrimitive::list() const {
	std::cout << m_name;
}

TAPrimitive::TAPrimitive() : m_name() {
}

TAPrimitive::TAPrimitive(const std::string &name) : m_name(name) {
	// Hashset of existing names
	static std::unordered_set<std::string> names;

	if (names.count(m_name) > 0) {
		throw std::invalid_argument("There is already a variable called: " + m_name);
	}
	else {
		names.insert(m_name);
	}
}

void TAPrimitive::setType(Type t) {
	m_type = t;
}

void TAPrimitive::set(double d) {
}
