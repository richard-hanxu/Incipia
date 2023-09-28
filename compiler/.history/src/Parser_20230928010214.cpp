#ifndef PARSER_CPP
#define PARSER_CPP

#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"
#include "Incipia.h"

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

Expr* Parser::term() {
    Expr* expr = factor();
    while (match({MINUS, PLUS})) {
      Token op = previous();
      Expr* right = factor();
      expr = & Binary(expr, op, right);
    }
    return expr;
}

Expr* Parser::factor() {
    Expr* expr = unary();
    while (match({SLASH, STAR})) {
      Token op = previous();
      Expr* right = unary();
      expr = & Binary(expr, op, right);
    }
    return expr;
}

Expr* Parser::unary() {
    if (match({BANG, MINUS})) {
      Token op = previous();
      Expr* right = unary();
      return & Unary(op, right);
    }
    return primary();
}

Expr* Parser::primary() {
    if (match({FALSE})) return & Literal("false");
    if (match({TRUE})) return & Literal("true");
    if (match({NIL})) return & Literal("null");

    if (match({NUMBER, STRING})) {
      return & Literal(previous().literal);
    }

    if (match({LEFT_PAREN})) {
      Expr* expr = expression();
      consume(RIGHT_PAREN, "Expect ')' after expression.");
      return & Grouping(expr);
    }

    throw error(peek(), "Expect expression.");
}

Token Parser::consume(TokenType type, string message) {
    if (check(type)) return advance();
    throw error(peek(), message);
}

Parser::ParseError Parser::error(Token token, string message) {
    Incipia::error(token, message);
    return ParseError();
}

void Parser::synchronize() {
    advance();

    while (!isAtEnd()) {
      if (previous().type == SEMICOLON) return;

      switch (peek().type) {
        case CLASS:
        case FUN:
        case VAR:
        case FOR:
        case IF:
        case WHILE:
        case PRINT:
        case RETURN:
          return;
      }

      advance();
    }
}

Expr* Parser::parse() {
    try {
      return expression();
    } catch (ParseError error) {
      return NULL;
    }
}


// comparison -> term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
Expr* Parser::comparison() {
    Expr* expr = term();

    while (match({GREATER, GREATER_EQUAL, LESS, LESS_EQUAL})) {
      Token op = previous();
      Expr* right = term();
      expr = & Binary(expr, op, right);
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

#endif
