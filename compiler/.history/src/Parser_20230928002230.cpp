#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"

Parser::Parser(vector<Token> tokens) : tokens(tokens){
}

Expr* Parser::expression(){
    return equality();
}

bool Parser::match(vector<TokenType> tokenTypes) {
    for (TokenType type : tokenTypes) {
      if (check(type)) {
        advance();
        return true;
      }
    }
    return false;
}

bool Parser::check(TokenType type) {
    if (isAtEnd()) return false;
    return peek().type == type;
}

Token Parser::advance() {
    if (!isAtEnd()) current++;
    return previous();
}

bool Parser::isAtEnd() {
    return peek().type == eof;
}

Token Parser::peek() {
    return tokens[current];
}

Token Parser::previous() {
    return tokens[current - 1];
}

// comparison -> term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
Expr* Parser::comparison() {
    Expr* expr = term();

    while (match({GREATER, GREATER_EQUAL, LESS, LESS_EQUAL})) {
      Token op = previous();
      Expr right = term();
      expr = new Expr.Binary(expr, op, right);
    }

    return expr;
  }
Expr* Parser::equality(){
    Expr* expr = comparison();
    while(match({BANG_EQUAL, EQUAL_EQUAL})){
        Token op = previous();
        Expr* right = comparison();
        expr = & Binary(expr, op, right);
    }
}





using namespace std;