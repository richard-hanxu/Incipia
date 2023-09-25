#include <iostream>
#include <stdexcept>
#include <string>
#include <filesystem>
#include "Incipia.h"

using namespace std;

bool hadError = false;

void Incipia::_main(int argc, char* argv[]){
    if(argc > 2){
        std::cout << "Usage: Incipia [script]" << std::endl;
        exit(64);
    } else if (argc == 2){
        runFile(argv[1]);
    } else {
        try {
            cout << "Welcome to Incipia!" << endl;
            runPrompt();
        } catch (const std::exception& e){
            std::cerr << e.what() << std::endl;
        }   
    }
}

void Incipia::runFile(string path){
    filesystem::path filepath(path);
    run(filepath.u8string());
}

void Incipia::runPrompt(){
    string line;
    for (;;) { 
        cout << "> ";
        getline(cin, line);
        if (line.empty()) break;
        run(line);
        if (hadError) exit(65);
    }
}

void Incipia::run(string source){
    cout << source << endl;
}

void Incipia::error(int line, string message){
    report(line, "", message);
}

void Incipia::report(int line, string where, string message){
    cout << "[line " << line << "] Error" << where << ": " << message << endl;
}


int main(int argc, char* argv[]){
    cout << argc << " argument(s), " << endl;
    Incipia incipia;
    incipia._main(argc, argv);
}