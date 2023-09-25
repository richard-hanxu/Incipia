#ifndef CLASS_INC
#define CLASS_INC

#include <iostream>
#include <stdexcept>
#include <string>
#include <filesystem>

using namespace std;

class Incipia{
public:
    void _main(int argc, char* argv[]);
private:
    static void runFile(string path);
    static void runPrompt();
    static void run(string source);
    static void error(int line, string message);
    static void report(int line, string where, string message);
};

bool error;

#endif