#include "Expr.h"

using namespace std;

class AstPrinter : public Visitor{
public:
    void print(Expr* expr){
        expr->accept(*this);
    }
    
    string visitUnary(Unary unary){
        return unary.op.lexeme + " " + unary.right->accept(*this);
    }
};

