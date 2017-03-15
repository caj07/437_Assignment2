#include "TADouble.hpp"
#include "TACeiling.hpp"
#include "TALessThan.hpp"
#include "TAAnd.hpp"
#include "TAConstant.hpp"
#include "TAPair.hpp"
#include "TAArray.hpp"
#include "TAPlus.hpp"
#include "TAArrayAccess.hpp"
#include <iostream>

int main() {
	// Problem 3
	TAConstant N(16); // surprise
	TAConstant one(1);
	TAInt x("x");
	TADouble d("d");
	TAPair p(x, d);

	//The following line is tricky:
	// what type should the second argument be declared as?
	TAArray a("a", x.type(), N); //instantiate an array of integer with capacity 16
	TAInt i("i");
	TAPlus exp(i, one);
	TAArrayAccess ai(a, exp);
	TAPair p2(ai, x);
	i.set(1);
	exp.evaluate();
	a.list();
	std::cout << std::endl;
	ai.set(7); // The type of the argument of set for array access is also tricky
	a.list();

	// Problem 2
	//TAInt x("x");
	//TADouble d("d");
	//TACeiling y(d); // denotes y is the ceiling of d
	//TABool b("b");
	//TALessThan t1(x, y); // denotes x < y
	//TAAnd t2(b, t1); // denotes b and t1
	//t2.list();// should print: ( &b (< x (ceiling d ) ) )
	//std::cout << std::endl;
	//x.set(5);
	//d.set(2.3);
	//b.set(true);
	//y.evaluate();
	//t1.evaluate();
	//t1.printState();// should print: false
	//std::cout << std::endl;
	//d.set(5.3);
	//y.evaluate();
	//t1.evaluate();
	//t1.printState();// should print: true
	//std::cout << std::endl;

	// Problem 1:
	//TAInt x;
	//TADouble d;
	//TACeiling y(d); // denotes y is the ceiling of d
	//TABool b;
	//TALessThan t1(x, y); // denotes x < y
	//TAAnd t2(b, t1); // denotes b and t1

	//TAInt x;
	//TADouble d;
	//TALessThan t1(x, d); // x and d are not of the same type and
	//					 //thus TALessThan should not accept to perform the construction
	return 0;
}