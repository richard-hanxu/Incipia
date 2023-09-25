#include <string>
#include "TokenType.h"

using namespace std;

class Token{
    const TokenType type;
    const string lexeme;
    const string literal;
    const int line;
public:
    Token(TokenType type, string lexeme, string literal, int line){
        type = type;
        lexeme = lexeme;
        literal = literal;
        line = line;
    }
    string toString(){
        return type + " " + lexeme + " " + literal;
    }
};