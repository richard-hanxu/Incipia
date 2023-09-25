#ifndef TOKEN
#define TOKEN

#include <string>
#include "TokenType.h"

using namespace std;

class Token{
public:
    const TokenType type;
    const string lexeme;
    const string literal;
    const int line;
    Token(TokenType type, string lexeme, string literal, int line);
    const string toString();
private:
    string typeToString(TokenType type);
};

#endif