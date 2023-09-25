#ifndef Expr_H
#define Expr_H

#include <string>
#include <vector>
#include "../Token.h"

using namespace std;

class Expr;
class Binary;
class Grouping;
class Literal;
class Unary;

class Visitor{
public:
	virtual string visitBinary(Binary* binary) = 0;
	virtual string visitGrouping(Grouping* grouping) = 0;
	virtual string visitLiteral(Literal* literal) = 0;
	virtual string visitUnary(Unary* unary) = 0;
};
class Expr{ 
public:
	virtual ~Expr() {}
	virtual string accept(Visitor *visitor) = 0;
};

class Binary : public Expr {
public:
	Expr* right;
	Token op;
	Expr* left;
	Binary(Expr* right, Token op, Expr* left);
	string accept(Visitor *visitor) override;
};

class Grouping : public Expr {
public:
	Expr* expression;
	Grouping(Expr* expression);
	string accept(Visitor *visitor) override;
};

class Literal : public Expr {
public:
	string value;
	Literal(string value);
	string accept(Visitor *visitor) override;
};

class Unary : public Expr {
public:
	Expr* right;
	Token op;
	Unary(Expr* right, Token op);
	string accept(Visitor *visitor) override;
};

#endif
