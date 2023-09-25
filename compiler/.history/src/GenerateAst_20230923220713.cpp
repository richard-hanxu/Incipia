#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "GenerateAst.h"

using namespace std;

int GenerateAst::main(int argc, char* argv[]){
    if (argc != 2){
        cout << "Usage: generate_ast <output directory>" << endl;
        return 1;
    }
    string outputDir = argv[1];
    cout << "outputDir: " << outputDir << endl;
    defineAst(outputDir, "Expr", {
      "Binary   : Expr left, Token operator, Expr right",
      "Grouping : Expr expression",
      "Literal  : Object value",
      "Unary    : Token operator, Expr right"
    });
    return 0;
}

void GenerateAst::defineAst(string outputDir, string baseName, vector<string> types){
    string path = outputDir + "/" + baseName + ".h";
    ofstream file(path);
    file << "#ifndef " << baseName << "_CPP" << endl;
    file << "#define " << baseName << "_CPP" << endl;
    file << endl;
    file << "#include <string>" << endl;
    file << "#include <vector>" << endl;
    file << endl;
    file << "using namespace std;" << endl;
    file << endl;
    file << "class " << baseName << "{" << endl;
    file << "public:" << endl;
    file << "};" << endl;
    file << "#endif" << endl;
    file.close();
}

void GenerateAst::defineType(ofstream& file, string baseName, string className, string fieldList){
    file << "\tclass " + className + "{" << endl;
    file << "\t public:" << endl;
    // Constructor.
    file << "\t\t" + className + "(" + fieldList + ") ";
    int pos;
    while((pos = fieldList.find(", ")) != -1){
        string field = fieldList.substr(0, pos);
        string name = field.substr(field.find(" ") + 1);
        file << name + "(" + name + ")";
        fieldList = fieldList.substr(pos + 2);
        cout << name << endl;
        cout << fieldList << endl;
        if (fieldList.find(", ") != -1) file << ", ";
    }
    file << " {" << endl;
    file << "\t\t}" << endl;
    file << "\t};" << endl;
}

int main(int argc, char* argv[]){
    GenerateAst generateAst;
    generateAst.main(argc, argv);
}