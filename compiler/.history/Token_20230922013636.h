#include <string>
#include "TokenType.h"

using namespace std;

class Token{
public:
    Token(TokenType type, string lexeme, string literal, int line);
    const string toString();
};