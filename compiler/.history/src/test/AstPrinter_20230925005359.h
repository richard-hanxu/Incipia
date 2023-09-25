#include "Expr.h"

using namespace std;

class AstPrinter : public Visitor{
public:
    string print(Expr* expr);
    string visitBinary(Binary binary);
    string visitGrouping(Grouping grouping);
    string visitLiteral(Literal literal);
};