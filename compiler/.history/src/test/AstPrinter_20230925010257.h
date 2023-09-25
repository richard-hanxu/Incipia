#include "Expr.h"

using namespace std;

class AstPrinter : public Visitor{
public:
    string print(Expr* expr);
    string visitUnary(Unary unary);
	string visitGrouping(Grouping grouping);
	string visitLiteral(Literal literal);
	string visitBinary(Binary binary);
};