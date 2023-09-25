#include <iostream>
#include <stdexcept>
#include <string>
#include <filesystem>

using namespace std;

class Disipul{
public:
    static bool hadError;
    void _main(int argc, char* argv[]){
        if(argc > 2){
            std::cout << "Usage: Disipul [script]" << std::endl;
            exit(64);
        } else if (argc == 2){
            runFile(argv[1]);
        } else {
            try {
                cout << "Welcome to Disipul!" << endl;
                runPrompt();
            } catch (const std::exception& e){
                std::cerr << e.what() << std::endl;
            }   
        }
    }

private:
    static void runFile(string path){
        filesystem::path filepath(path);
        run(filepath.u8string());
    }

    static void runPrompt(){
        string line;
        for (;;) { 
            cout << "> ";
            getline(cin, line);
            if (line.empty()) break;
            run(line);
            if (hadError) exit(65);
        }
    }

    static void run(string source){
        cout << source << endl;
    }

    static void error(int line, string message){
        report(line, "", message);
    }

    static void report(int line, string where, string message){
        cout << "[line " << line << "] Error" << where << ": " << message << endl;
    }

};

int main(int argc, char* argv[]){
    cout << argc << " argument(s), " << endl;
    Disipul disipul;
    bool Disipul::hadError = false;
    disipul._main(argc, argv);
}