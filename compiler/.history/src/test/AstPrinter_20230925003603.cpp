#include "Expr.h"

using namespace std;

class AstPrinter : public Visitor{
public:
    string print(Expr* expr){
        return expr->accept(this);
    }

    string visitBinary(Binary binary){
        return "(" + binary.op.lexeme + " " + binary.left->accept(this) + " " + binary.right->accept(this) + ")";
    }

    string visitGrouping(Grouping grouping){
        return grouping.expression->accept(this);
    }

    string visitLiteral(Literal literal){
        return literal.value;
    }

    string visitUnary(Unary unary){
        return unary.op.lexeme + " " + unary.right->accept(this);
    }
};

