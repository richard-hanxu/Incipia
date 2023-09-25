#ifndef Expr_CPP
#define Expr_CPP

#include <string>
#include <vector>
#include "Token.h"

using namespace std;

class Expr{
public:
	virtual ~Expr() {}
};

class Binary : public Expr {
public:
	Expr* right;
	Token op;
	Expr* left;
	Binary(Expr* right, Token op, Expr* left) : right(right), op(op), left(left) {}
};
class Grouping : public Expr {
public:
	Expr* expression;
	Grouping(Expr* expression) : expression(expression) {}
};
class Literal : public Expr {
public:
	string value;
	Literal(string value) : value(value) {}
};
class Unary : public Expr {
public:
	Expr* right;
	Token op;
	Unary(Expr* right, Token op) : right(right), op(op) {}
};
#endif
