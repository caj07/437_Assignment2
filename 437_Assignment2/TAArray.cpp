#include "TAArray.hpp"
#include <iostream>

TAArray::TAArray(const std::string &name, Type type, const TAConstant &size) : TAPrimitive(name), m_memberType(type), m_size(size.getValue()), m_arr(size.getValue(), NULL) {
	TAPrimitive::setType(Type::arrayType);
}

int TAArray::size() const {
	return m_size;
}

TAPrimitive*& TAArray::accessArray(int index) {
	return m_arr[index];
}

Type TAArray::getMemberType() const {
	return m_memberType;
}

void TAArray::list() const {
	std::cout << "{";
	for (auto it = m_arr.begin(); it != m_arr.end(); ++it) {
		if (*it == NULL) {
			std::cout << "uninitialized ";
		}
		else {
			(*it)->list();
			std::cout << ", ";
		}
	}
	std::cout << "}";
}