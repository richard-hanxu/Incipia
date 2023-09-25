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
        TokenType toktype = eof;
        string lexeme = "";
        string literal = "";
        Token t(eof, lexeme, literal, -1);
        return tokens;
    }
};