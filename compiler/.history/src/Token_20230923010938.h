#ifndef TOKEN
#define TOKEN

#include <string>
#include "TokenType.h"

using namespace std;

class Token{
public:
    Token(TokenType type, string lexeme, string literal, int line);
    const string toString();
private:
    const TokenType type;
    const string lexeme;
    const string literal;
    const int line;

    string typeToString(TokenType type);
};

#endif