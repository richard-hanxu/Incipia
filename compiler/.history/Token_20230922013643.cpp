#include <string>
#include "Token.h"

using namespace std;

class Token{
    const TokenType type;
    const string lexeme;
    const string literal;
    const int line;
public:
    Token(TokenType type, string lexeme, string literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line) {
    }
    const string toString(){
        return type + " " + lexeme + " " + literal;
    }
};