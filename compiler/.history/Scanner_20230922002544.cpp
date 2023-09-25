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
    const string source;
    const vector<Token> tokens;
    int start = 1;
    int current = 1;
    int line = 1;


    vector<Token> scanTokens(){
        while (!isAtEnd()){
            // We are at the beginning of the next lexeme
            start = current;
            scanToken();
        }
        tokens.push_back(Token(eof, "", "", -1));
        return tokens;
    }
};