#include <string>
#include "TokenType.h"

class Token{
public:
    Token(TokenType type, string lexeme, string literal, int line);
    string toString();
};