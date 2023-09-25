#ifndef ASTPRINTER_H
#define ASTPRINTER_H

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

#endif