#include <string>
#include "Token.h"
#include <vector>

using namespace std;

class Scanner{
public:
    Scanner(string source);
private:
    vector<Token> scanTokens();
    void scanToken();
    bool match(char expected);
    bool isAtEnd();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, string literal);

};