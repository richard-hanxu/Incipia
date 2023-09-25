#ifndef Expr_CPP
#define Expr_CPP

#include <string>
#include <vector>
#include "Expr.h"

using namespace std;

Binary::Binary(Expr* left, Token op, Expr* right) : left(left), op(op), right(right) {}
string Binary::accept(Visitor *visitor){
	return visitor->visitBinary(this);
}

Grouping::Grouping(Expr* expression) : expression(expression) {}
string Grouping::accept(Visitor *visitor){
	return visitor->visitGrouping(this);
}

Literal::Literal(string value) : value(value) {}
string Literal::accept(Visitor *visitor){
	return visitor->visitLiteral(this);
}

Unary::Unary(Token op, Expr* right) : op(op), right(right) {}
string Unary::accept(Visitor *visitor){
	return visitor->visitUnary(this);
}

#endif
