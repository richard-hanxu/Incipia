#include <iostream>
#include "GenerateAst.h"

using namespace std;

int GenerateAst::main(int argc, char* argv[]){
    if (argc != 1){
        cout << "Usage: generate_ast <output directory>" << endl;
        return 1;
    }
    string outputDir = argv[0]
}