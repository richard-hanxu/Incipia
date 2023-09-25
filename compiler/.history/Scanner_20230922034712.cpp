#include <string>
#include <vector>
#include <unordered_map>
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
    static unordered_map<string, TokenType> keywords;
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
                if (match('/')) { // Comments
                // A comment goes until the end of the line.
                while (peek() != '\n' && !isAtEnd()) advance();
                } else {
                addToken(SLASH);
                }
                break;
            case ' ':
            case '\r':
            case '\t':
                // Ignore whitespace.
                break;
            case '\n':
                line++;
                break;
            case '"': _string(); break;
            default:
                if (isDigit(c)) {
                    number();
                }else if(isAlpha(c)){
                    identifier();
                }else {
                    Incipia::error(line, "Unexpected character.");
                }
                break;
        }
    }

    void identifier() {
        while (isAlphaNumeric(peek())) advance();
        addToken(IDENTIFIER);
    }

    void number(){
        while (isDigit(peek())) advance();

        // Look for a fractional part.
        if (peek() == '.' && isDigit(peekNext())) {
            // Consume the "."
            advance();

            while (isDigit(peek())) advance();
        }

        addToken(NUMBER, source.substr(start, current));
    }

    void _string(){
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') line++;
            advance();
        }

        if (isAtEnd()) {
            Incipia::error(line, "Unterminated string.");
            return;
        }

        // The closing ".
        advance();

        // Trim the surrounding quotes.
        string value = source.substr(start + 1, current - 1);
        addToken(STRING, value);
    }

    bool match(char expected){
        if(isAtEnd()) return false;
        if(source[current] != expected) return false;
        current++;
        return true;
    }

    char peek(){
        if (isAtEnd()) return '\0';
            return source[current];
    }

    char peekNext() {
        if (current + 1 >= source.length()) return '\0';
        return source[current + 1];
    } 

    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
    }

    bool isAlphaNumeric(char c) {
        return isAlpha(c) || isDigit(c);
    }

    bool isDigit(char c){
        return c >= '0' && c <= '9';
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