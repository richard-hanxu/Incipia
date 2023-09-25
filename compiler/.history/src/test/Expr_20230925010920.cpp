#ifndef Expr_CPP
#define Expr_CPP

#include <string>
#include <vector>
#include "Expr.h"

using namespace std;

class AstPrinter : public Visitor{
public:
    string print(Expr* expr);
    string visitUnary(Unary* unary) override;
	string visitGrouping(Grouping* grouping) override;
	string visitLiteral(Literal* literal) override;
	string visitBinary(Binary* binary) override;
};

Unary::Unary(Expr* right, Token op) : right(right), op(op) {}
string Unary::accept(Visitor *visitor) const {
	visitor->visitUnary(*this);
}

Grouping::Grouping(Expr* expression) : expression(expression) {}
string Grouping::accept(Visitor *visitor) const {
	visitor->visitGrouping(*this);
}

Literal::Literal(string value) : value(value) {}
string Literal::accept(Visitor *visitor) const {
	visitor->visitLiteral(*this);
}

Binary::Binary(Expr* right, Token op, Expr* left) : right(right), op(op), left(left) {}
string Binary::accept(Visitor *visitor) const {
	visitor->visitBinary(*this);
}

#endif
