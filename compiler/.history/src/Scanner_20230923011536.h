#ifndef SCANNER
#define SCANNER

#include <string>
#include <unordered_map>
#include <vector>
#include "Token.h"

using namespace std;

class Scanner{
public:
    Scanner(string source);
    vector<Token> scanTokens();
private:
    const string source;
    vector<Token> tokens;
    static unordered_map<string, TokenType> keywords;
    int start = 0;
    int current = 0;
    int line = 1;

    void makeHashMap();
    void scanToken();
    void identifier();
    void number();
    void _string();
    bool match(char expected);
    char peek();
    char peekNext();
    bool isAlpha(char c);
    bool isAlphanumeric(char c);
    bool isDigit(char c);
    bool isAtEnd();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, string literal);
};

#endif