#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
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
    string path = outputDir + "/" + baseName + ".cpp";
    ofstream file(path);
    file << "#ifndef " << baseName << "_CPP" << endl;
    file << "#define " << baseName << "_CPP" << endl;
    file << endl;
    file << "#include <string>" << endl;
    file << "#include <vector>" << endl;
    file << "#include \"Token.h\"" << endl;
    
    file << endl;
    file << "using namespace std;" << endl;
    file << endl;
    file << "class " << baseName << "{" << endl;
    file << "public:" << endl;
    file << "\tvirtual ~" << baseName << "() {}" << endl;
    //file << "private:" << endl;
    file << "};" << endl;
    file << endl;
    // The AST classes.
    for (string type : types) {
        string className = type.substr(0, type.find(":"));
        className = className.substr(className.find_first_not_of(" "), className.find_last_not_of(" ") - className.find_first_not_of(" ") + 1);
        //cout << "'" + className + "'" << endl;
        string fields = type.substr(type.find(":"), fields.length());
        fields = fields.substr(fields.find_first_not_of(": "), fields.find_last_not_of(" ") - fields.find_first_not_of(" ") + 1);
        //cout << "'" + fields + "'" << endl;
        defineType(file, baseName, className, fields);
    }
    file << "#endif" << endl;
    file.close();
}

void GenerateAst::defineType(ofstream& file, string baseName, string className, string fieldList){
    file << "class " + className + " : " + baseName + " {" << endl;
    file << "public:" << endl;

    // Create list containing fields
    int pos;
    string field;
    string field_type;
    string field_name;
    string temp = fieldList;
    unordered_map<string, string> field_map = {};
    while((pos = temp.find(", ")) != -1){
        field = temp.substr(0, pos);
        field_type = field.substr(0, field.find(" "));
        field_name = field.substr(field.find(" ") + 1);
        field_map.insert({field_type, field_name});
        temp = temp.substr(pos + 2);
    }

    // Member variables
    for (auto const& x : field_map){
        file << "\t" + addPointer(x.first) + " " + x.second + ";" << endl;
    }

    // Constructor.
    file << "\t" + className + "(" + fieldList + ") : ";
    for (auto const& x : field_map){
        file << "\t" + addPointer(x.first) + " " + x.second + ";" << endl;
    }
    file << "{" << endl;
    file << "};" << endl;
}

string addPointer(string s){
    if (s == "Expr") return "Expr*";
    return s
}

int main(int argc, char* argv[]){
    GenerateAst generateAst;
    generateAst.main(argc, argv);
}