#include "TAUnaryOp.h"
#include "TAPairValue.h"

struct TAFirst : public TAUnaryOp {
  TAFirst (TAPair & pair) : 
    TAUnaryOp(pair) 
  {
  }

  virtual TAPair & getPair() const {
    return (TAPair&) getOperand();
  }

  virtual TAValue & evaluateExecute(TAValue & v) {
	  return getPair().getValue().getPairValue().getFirst();
  }

  virtual void printState(ostream & os) const {
	  getPair().getValue().getPairValue().getFirst().print(os);
  }

  virtual const TAType & getType() const {
    return getPair().getValue().getPairValue().getFirst().getType();
  };

  virtual const string operatorSign () const {
    return "first";
  }
};
