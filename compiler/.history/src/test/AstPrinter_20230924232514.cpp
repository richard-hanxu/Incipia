#include "Expr.h"

using namespace std;

class AstPrinter : public Visitor{
public:
    void printdfas(Expr* expr){
        std::cout << expr->accept(*this) << std::endl;
    }
};

