#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
#include "test/Expr.h"

using namespace std;

class Parser{
public:
    Parser(vector<Token> tokens);
    static void error(Token token, string message);
private:
    int current = 0;
    const vector<Token> tokens; 

    Expr* expression();
    // equality -> comparison ( ( "!=" | "==" ) comparison )* ;
    Expr* equality();
    bool match(vector<TokenType> tokenTypes);
    bool check(TokenType type);
    Token advance();
    bool isAtEnd();
    Token peek();
    Token previous();
    Expr* comparison();
    Expr* term();
    Expr* factor();
    Expr* unary();
    Expr* primary();

    // Error correction
    Token consume(TokenType type, string message);
    class ParseError : public exception {};

};
