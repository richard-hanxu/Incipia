#ifndef Expr_H
#define Expr_H

#include <string>
#include <vector>
#include "../Token.h"

using namespace std;

template<class T> class Visitor{
public:
	virtual T visitUnary(Unary unary) const = 0;
	virtual T visitGrouping(Grouping grouping) const = 0;
	virtual T visitLiteral(Literal literal) const = 0;
	virtual T visitBinary(Binary binary) const = 0;
};

class Expr{ 
public:
	virtual ~Expr() {}
	virtual void accept(Visitor<int> *visitor) const = 0;
};

class Unary : public Expr {
public:
	Expr* right;
	Token op;
	Unary(Expr* right, Token op);
	void accept(Visitor<int> *visitor) const override;
};

class Grouping : public Expr {
public:
	Expr* expression;
	Grouping(Expr* expression);
	void accept(Visitor *visitor) const override;
};

class Literal : public Expr {
public:
	string value;
	Literal(string value);
	void accept(Visitor *visitor) const override;
};

class Binary : public Expr {
public:
	Expr* right;
	Token op;
	Expr* left;
	Binary(Expr* right, Token op, Expr* left);
	void accept(Visitor *visitor) const override;
};

#endif
