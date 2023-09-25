#ifndef Expr_CPP
#define Expr_CPP

#include <string>
#include <vector>
#include "Expr.h"

using namespace std;

Unary::Unary(Expr* right, Token op) : right(right), op(op) {}
string Unary::accept(const Visitor *visitor) const {
	visitor->visitUnary(*this);
}

Grouping::Grouping(Expr* expression) : expression(expression) {}
string Grouping::accept(const Visitor *visitor) const {
	visitor->visitGrouping(*this);
}

Literal::Literal(string value) : value(value) {}
string Literal::accept(const Visitor *visitor) const {
	visitor->visitLiteral(*this);
}

Binary::Binary(Expr* right, Token op, Expr* left) : right(right), op(op), left(left) {}
string Binary::accept(const Visitor *visitor) const {
	visitor->visitBinary(*this);
}

#endif
