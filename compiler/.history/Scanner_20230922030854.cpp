#include <string>
#include <vector>
#include "TokenType.h"
#include "Token.h"
#include "Incipia.h"

using namespace std;

class Scanner{
public:
    Scanner(std::string source) : source(source){ 
    }

private:
    const string source;
    vector<Token> tokens;
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

    void scanToken(){
        char c = advance();
        switch (c) {
            case '(': addToken(LEFT_PAREN); break;
            case ')': addToken(RIGHT_PAREN); break;
            case '{': addToken(LEFT_BRACE); break;
            case '}': addToken(RIGHT_BRACE); break;
            case ',': addToken(COMMA); break;
            case '.': addToken(DOT); break;
            case '-': addToken(MINUS); break;
            case '+': addToken(PLUS); break;
            case ';': addToken(SEMICOLON); break;
            case '*': addToken(STAR); break; 
            case '!':
                addToken(match('=') ? BANG_EQUAL : BANG);
                break;
            case '=':
                addToken(match('=') ? EQUAL_EQUAL : EQUAL);
                break;
            case '<':
                addToken(match('=') ? LESS_EQUAL : LESS);
                break;
            case '>':
                addToken(match('=') ? GREATER_EQUAL : GREATER);
                break;
            case '/':
                if (match('/')) {
                // A comment goes until the end of the line.
                while (peek() != '\n' && !isAtEnd()) advance();
                } else {
                addToken(SLASH);
                }
                break;
            default:
                Incipia::error(line, "Unexpected character.");
                break;
        }
    }

    bool match(char expected){
        if(isAtEnd()) return false;
        if(source[current] != expected) return false;
        current++;
        return true;
    }

    bool isAtEnd(){
        return current >= source.length();
    }

    char advance() {
        return source[current++];
    }

    void addToken(TokenType type) {
        addToken(type, "");
    }

    void addToken(TokenType type, string literal) {
        string text = source.substr(start, current);
        tokens.push_back(Token(type, text, literal, line));
    }
};