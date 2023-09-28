#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
#include "test/Expr.h"

using namespace std;

class Parser{
public:
    Parser(vector<Token> tokens);
private:
    int current = 0;
    const vector<Token> tokens; 

    Expr expression();
    // equality -> comparison ( ( "!=" | "==" ) comparison )* ;
    Expr equality();
    bool match(vector<TokenType> tokenTypes);

};
