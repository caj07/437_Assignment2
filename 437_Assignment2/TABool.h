#pragma once
#include "TAPrimitive.h"
#include "TAFormula.h"

struct TABool : public TAPrimitive , public TAFormula {
  TABool (const string & s) : TAPrimitive (s) {
    val.set(false);
  }

  virtual void printState(ostream & os) const {
    os << "(";
    list(os);
    os << "," << val.getBool() << ")";
  }

  void set(bool v) {
    val.set(v);
  }

  virtual void set(const TAValue & v) {
    val.set(v.getBool());
  }

  // Inherited via TAFormula
  virtual TAValue & evaluate() override;
  virtual void list(ostream & os) const override;
  virtual const TAValue & getValue() const override;
};
