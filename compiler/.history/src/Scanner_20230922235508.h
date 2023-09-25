#ifndef SCANNER
#define SCANNER

#include <string>
#include "Token.h"
#include <vector>

using namespace std;

class Scanner{
public:
    Scanner(string source);
    vector<Token> scanTokens();
private:
    const string source;
    vector<Token> tokens;
    int start;
    int current;
    int line;

    static void makeHashMap();
    vector<Token> scanTokens();
    void scanToken();
    bool match(char expected);
    bool isAtEnd();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, string literal);
    char peek();
    void _string();

};

#endif