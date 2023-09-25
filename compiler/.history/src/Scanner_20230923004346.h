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
    int start = 1;
    int current = 1;
    int line = 1;

    void makeHashMap();
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