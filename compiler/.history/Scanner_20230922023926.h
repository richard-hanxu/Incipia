#include <string>
#include "Token.h"
#include <vector>

using namespace std;

class Scanner{
public:
    Scanner(string source);
private:
    const string source;
    vector<Token> tokens;
    int start;
    int current;
    int line;
    
    vector<Token> scanTokens();
    void scanToken();
    bool match(char expected);
    bool isAtEnd();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, string literal);

};