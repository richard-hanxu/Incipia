#ifndef Expr_H
#define Expr_H

#include <string>
#include <vector>
#include "../Token.h"

using namespace std;

class Visitor{
public:
	virtual void visitUnary(Unary unary) const = 0;
	virtual void visitGrouping(Grouping grouping) const = 0;
	virtual void visitLiteral(Literal literal) const = 0;
	virtual void visitBinary(Binary binary) const = 0;
};
class Expr{ 
public:
	virtual ~Expr() {}
	virtual void accept(Visitor *visitor) const = 0;
};

class Unary : public Expr {
public:
	Expr* right;
	Token op;
	Unary(Expr* right, Token op);
	void accept(Visitor *visitor) const override;
};class Grouping : public Expr {
public:
	Expr* expression;
	Grouping(Expr* expression);
	void accept(Visitor *visitor) const override;
};class Literal : public Expr {
public:
	string value;
	Literal(string value);
	void accept(Visitor *visitor) const override;
};class Binary : public Expr {
public:
	Expr* right;
	Token op;
	Expr* left;
	Binary(Expr* right, Token op, Expr* left);
	void accept(Visitor *visitor) const override;
};#endif
