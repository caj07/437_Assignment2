#pragma once 
#include "TABinaryOp.h"
#include "TAFormula.h"
#include "TAType.h"

struct TABoolBinaryOp : public TABinaryOp, public TAFormula {

  TABoolBinaryOp(TATerm & op1, TATerm & op2) :
    TABinaryOp(op1, op2) 
  {
    val.set(false);
  }
  virtual const TAType & getType() const {
    // this is a formula, it returns a boolean type
    return TAType::getTypeInstance(TA_BOOL);
  };


  // Inherited via TAFormula
  virtual TAValue & evaluate() override;

  virtual void list(ostream & os) const override;

  virtual const TAValue & getValue() const override;

};
