#include <iostream>
#include "AstPrinter.h"

using namespace std;


string AstPrinter::print(Expr* expr){
    return expr->accept(this);
}

string AstPrinter::visitBinary(Binary* binary){
    return "(" + binary->op.lexeme + " " + binary->left->accept(this) + " " + binary->right->accept(this) + ")";
}

string AstPrinter::visitGrouping(Grouping* grouping){
    return "(group " + grouping->expression->accept(this) + ")";
}

string AstPrinter::visitLiteral(Literal* literal){
    return literal->value;
}

string AstPrinter::visitUnary(Unary* unary){
    return "(" + unary->op.lexeme + " " + unary->right->accept(this) + ")";
}


int main(){
    Expr* expression = new Binary(
        new Binary(
        new Unary(
            new Literal("1"),
            Token(MINUS, "-", "", 1)
        ),
        Token(STAR, "*", "", 1),
        new Grouping(
            new Literal("2")
        )
        )
    );
    AstPrinter printer;
    cout << printer.print(expression) << endl;
    return 0;
}
