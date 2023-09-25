#ifndef Expr_CPP
#define Expr_CPP

#include <string>
#include <vector>
#include "Expr.h"

using namespace std;

Unary::Unary(Expr* right, Token op) : right(right), op(op) {}
string Unary::accept(Visitor *visitor){
	return visitor->visitUnary(this);
}

Grouping::Grouping(Expr* expression) : expression(expression) {}
string Grouping::accept(Visitor *visitor){
	return visitor->visitGrouping(this);
}

Literal::Literal(string value) : value(value) {}
string Literal::accept(Visitor *visitor){
	return visitor->visitLiteral(this);
}

Binary::Binary(Expr* right, Token op, Expr* left) : right(right), op(op), left(left) {}
string Binary::accept(Visitor *visitor){
	return visitor->visitBinary(this);
}

#endif
