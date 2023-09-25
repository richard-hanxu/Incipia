#include <iostream>
#include <fstream>
#include "GenerateAst.h"

using namespace std;

int GenerateAst::main(int argc, char* argv[]){
    if (argc != 2){
        cout << "Usage: generate_ast <output directory>" << endl;
        return 1;
    }
    string outputDir = argv[1];
    defineAst(outputDir, "Expr", {
      "Binary   : Expr left, Token operator, Expr right",
      "Grouping : Expr expression",
      "Literal  : Object value",
      "Unary    : Token operator, Expr right"
    });
}

void GenerateAst::defineAst(string outputDir, string baseName, vector<string> types){
    string path = outputDir + "/" + baseName + ".h";
    ofstream file(path);
    file << "#ifndef " << baseName << "_H" << endl;
    file << "#define " << baseName << "_H" << endl;
    file << endl;
    file << "#include <string>" << endl;
    file << "#include <vector>" << endl;
    file << endl;
    file << "using namespace std;" << endl;
    file << endl;
    file << "class " << baseName << "{" << endl;
    file << "public:" << endl;
    file << "private:" << endl;
    file << "};" << endl;
    file << endl;
    // The AST classes.
    for (string type : types) {
        string className = type.substr(0, type.find(":"));
        className = className.substr(className.find_first_not_of(" "), className.find_last_not_of(" ") - className.find_first_not_of(" ") + 1);
        string fields = type.substr(type.find(":"), fields.length());
        fields = fields.substr(fields.find_first_not_of(" "), fields.find_last_not_of(" ") - fields.find_first_not_of(" ") + 1);
        defineType(file, baseName, className, fields);
    }
    file << "#endif" << endl;
    file.close();
}

void GenerateAst::defineType(ofstream& file, string baseName, string className, string fieldList){
    file << "  static class " + className + " extends " + baseName + " {";

    writer.println("package com.craftinginterpreters.lox;");
    writer.println();
    writer.println("import java.util.List;");
    writer.println();
    writer.println("abstract class " + baseName + " {");

    writer.println("}");
    writer.close();
}