#include <string>
#include "TokenType.h"

using namespace std;

class Token{
    const TokenType type;
    const string lexeme;
    const string literal;
    const int line;

    Token(TokenType type, string lexeme, string literal, int line);

public:
    string toString();
};