#include "TAArrayAccess.hpp"
#include "TABool.hpp"
#include "TAInt.hpp"
#include "TADouble.hpp"

TAArrayAccess::TAArrayAccess(TAArray &arr, const TANumber &index) : TAPrimitive(), m_arr(arr), m_arrIndex(index) {
}

void TAArrayAccess::set(TAPrimitive &val) {
	if (m_arr.getMemberType() == val.type()) {
		TAPrimitive *&member = m_arr.accessArray(m_arrIndex.getValue());
		delete member;
		member = &val;
	}
	else {
		throw std::invalid_argument("Array type and input type do not match.");
	}
}

void TAArrayAccess::set(double val) {
	TAPrimitive *&member = m_arr.accessArray(m_arrIndex.getValue());
	Type arrType = m_arr.getMemberType();
	if (arrType == Type::boolType) {
		member = new TABool("TAArrayAccess_creation_" + std::to_string(++m_numberOfNewlyCreatedPrimitiveObjects));
		member->set(val);
	}
	else if (arrType == Type::intType) {
		member = new TAInt("TAArrayAccess_creation_" + std::to_string(++m_numberOfNewlyCreatedPrimitiveObjects));
		member->set(val);
	}
	else if (arrType == Type::doubleType) {
		member = new TADouble("TAArrayAccess_creation_" + std::to_string(++m_numberOfNewlyCreatedPrimitiveObjects));
		member->set(val);
	}
	else {
		throw std::invalid_argument("Cannot convert input type into array type.");
	}
}

void TAArrayAccess::list() const {
	m_arr.accessArray(m_arrIndex.getValue())->list();
}

int TAArrayAccess::m_numberOfNewlyCreatedPrimitiveObjects = 0;