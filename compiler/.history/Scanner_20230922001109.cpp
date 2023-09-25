#include <string>
#include <vector>
#include "TokenType.h"
#include "Token.h"

using namespace std;

class Scanner{
public:
    Scanner(std::string source) : source(source){ 
    }

private:
    const vector<Token> tokens;
    const string source;

    vector<Token> scanTokens(){
        while (!isAtEnd()){
            // We are at the beginning of the next lexeme
            start = current;
            scanToken();
        }
        string lexeme = "";
        string literal = "";
        tokens.insert(Token(eof, lexeme, nullptr, 1))
        return tokens
    }
};