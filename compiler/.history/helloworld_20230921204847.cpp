#include <iostream>
#include <stdexcept>
#include <string>

class Disipul{
public:
    int main(int argc, char* argv[]){
        if(argc > 1){
            std::cout << "Usage: Disipul [script]" << std::endl;
            exit(64);
        } else if (argc == 1){
            runFile(argv[0]);
        } else {
            try {
                runPrompt();
            } catch (const std::exception& e){
                std::cerr << e.what() << std::endl;
            }   
        }
    }

private:
    static void runFile(string path){

    }

    
};