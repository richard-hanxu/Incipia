#ifndef CLASS_INC
#define CLASS_INC

#include <iostream>
#include <stdexcept>
#include <string>
#include <filesystem>
#include "Scanner.h"

using namespace std;

class Incipia{
public:
    void _main(int argc, char* argv[]);
    static void error(Token token, string message);
private:
    static void runFile(string path);
    static void runPrompt();
    static void run(string source);
    static void report(int line, string where, string message);
};

extern bool hasError;

#endif