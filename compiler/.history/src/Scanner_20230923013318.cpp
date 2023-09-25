#include <string>
#include <vector>
#include <unordered_map>
#include "TokenType.h"
#include "Token.h"
#include "Incipia.h"

using namespace std;

Scanner::Scanner(std::string source) : source(source){ 
}

unordered_map<string, TokenType> Scanner::keywords = {};

void Scanner::makeHashMap(){
    keywords.insert({"and",    AND});
    keywords.insert({"class",  CLASS});
    keywords.insert({"else",   ELSE});
    keywords.insert({"false",  FALSE});
    keywords.insert({"for",    FOR});
    keywords.insert({"fun",    FUN});
    keywords.insert({"if",     IF});
    keywords.insert({"nil",    NIL});
    keywords.insert({"or",     OR});
    keywords.insert({"print",  PRINT});
    keywords.insert({"return", RETURN});
    keywords.insert({"super",  SUPER});
    keywords.insert({"this",   THIS});
    keywords.insert({"true",   TRUE});
    keywords.insert({"var",    VAR});
    keywords.insert({"while",  WHILE});
}

vector<Token> Scanner::scanTokens(){
    while (!isAtEnd()){
        // We are at the beginning of the next lexeme
        start = current;
        scanToken();
    }
    tokens.push_back(Token(eof, "", "", -1));
    return tokens;
}

void Scanner::scanToken(){
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

void Scanner::identifier(){
    while (isAlphanumeric(peek())) advance();
    string text = source.substr(start, current);
    if(keywords.find(text) != keywords.end()){
        TokenType type = keywords[text];
        addToken(type);
    }else{
        addToken(IDENTIFIER);
    }
}

void Scanner::number(){
    while (isDigit(peek())) advance();
    // Look for a fractional part.
    if (peek() == '.' && isDigit(peekNext())) {
        // Consume the "."
        advance();

        while (isDigit(peek())) advance();
    }

    addToken(NUMBER, source.substr(start, current));
}

void Scanner::_string(){
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

bool Scanner::match(char expected){
    if(isAtEnd()) return false;
    if(source[current] != expected) return false;
    current++;
    return true;
}

char Scanner::peek(){
    if (isAtEnd()) return '\0';
        return source[current];
}

char Scanner::peekNext(){
    if (current + 1 >= source.length()) return '\0';
    return source[current + 1];
}

bool Scanner::isAlpha(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

bool Scanner::isAlphanumeric(char c){
    return isAlpha(c) || isDigit(c);
}

bool Scanner::isDigit(char c){
    return c >= '0' && c <= '9';
}

bool Scanner::isAtEnd(){
    return current >= source.length();
}

char Scanner::advance(){
    return source[current++];
}

void Scanner::addToken(TokenType type){
    addToken(type, "");
}

void Scanner::addToken(TokenType type, string literal){
    string lexeme = source.substr(start, current);
    cout << start << " " << current << endl;
    tokens.push_back(Token(type, lexeme, literal, line));
}