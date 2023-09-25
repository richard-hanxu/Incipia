#ifndef Expr_CPP
#define Expr_CPP

#include <string>
#include <vector>
#include "Expr.h"

using namespace std;

Unary::Unary(Expr* right, Token op) : right(right), op(op) {}
string Unary::accept(Visitor *visitor){
	visitor->visitUnary(this);
}

Grouping::Grouping(Expr* expression) : expression(expression) {}
string Grouping::accept(Visitor *visitor){
	visitor->visitGrouping(this);
}

Literal::Literal(string value) : value(value) {}
string Literal::accept(Visitor *visitor){
	visitor->visitLiteral(this);
}

Binary::Binary(Expr* right, Token op, Expr* left) : right(right), op(op), left(left) {}
string Binary::accept(Visitor *visitor){
	visitor->visitBinary(this);
}

#endif
