#include <string>
#include "Token.h"

using namespace std;

Token::Token(TokenType type, string lexeme, string literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line) {
}

const string Token::toString(){
    return type + " " + lexeme + " " + literal;
}