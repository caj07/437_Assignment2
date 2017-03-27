#include "TAUnaryOp.h"

struct TASecond : public TAUnaryOp {
  TASecond (TAPair & pair) : 
    TAUnaryOp(pair) 
  {
  }

  virtual TAPair & getPair() const {
    return (TAPair&) getOperand();
  }

  virtual TAValue & evaluateExecute(TAValue & v) {
    return getPair().getValue().getSecond();
  }

  virtual void printState(ostream & os) const {
    getPair().getValue().getSecond().print(os);
  }

  virtual const TAType & getType() const {
	 return getPair().getValue().getSecond().getType();
  };

  virtual const string operatorSign () const {
    return "second";
  }
};
