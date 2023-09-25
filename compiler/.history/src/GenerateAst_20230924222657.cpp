#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "GenerateAst.h"

using namespace std;

string GenerateAst::addPointer(string s){
    if (s == "Expr") return "Expr*";
    return s;
}

int GenerateAst::main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Usage: generate_ast <output directory>" << endl;
        return 1;
    }
    string outputDir = argv[1];
    defineAst(outputDir, "Expr", {
      "Binary   : Expr left, Token op, Expr right",
      "Grouping : Expr expression",
      "Literal  : string value",
      "Unary    : Token op, Expr right",
    });
    return 0;
}

void GenerateAst::defineAst(string outputDir, string baseName, vector<string> types){

    unordered_map<string, string> class_fieldsmap = {};
    for (string type : types) {
        string className = type.substr(0, type.find(":"));
        className = className.substr(className.find_first_not_of(" "), className.find_last_not_of(" ") - className.find_first_not_of(" ") + 1);
        string fields = type.substr(type.find(":"));
        fields = fields.substr(fields.find_first_not_of(": "), fields.find_last_not_of(" ") - fields.find_first_not_of(" ") + 1);
        class_fieldsmap.insert({className, fields});
    }

    // Expr base class
    file << "class " << baseName << "{" << endl;
    file << "public:" << endl;
    file << "\tvirtual ~" << baseName << "() {}" << endl;
    // Abstract accept method
    file << "\tvirtual void accept(Visitor *visitor) const = 0;" << endl;
    file << "};" << endl;
    file << endl;

    // Visitor abstract class
    generateVisitor(file, class_fieldsmap);
}

void GenerateAst::generateCpp(string outputDir, string baseName, unordered_map<string, string> class_fieldsmap){
    string path = outputDir + "/" + baseName + ".cpp";
    ofstream file(path);
    file << "#ifndef " << baseName << "_CPP" << endl;
    file << "#define " << baseName << "_CPP" << endl;
    file << endl;
    file << "#include <string>" << endl;
    file << "#include <vector>" << endl;
    file << "#include \"../Token.h\"" << endl;
    
    file << endl;
    file << "using namespace std;" << endl;
    file << endl;

    // The AST classes.
    for (auto const& kp : class_fieldsmap) {
        defineTypeCpp(file, baseName, kp.first, kp.second);
    }
    file << "#endif" << endl;
    file.close();
}

void GenerateAst::defineTypeCpp(ofstream& file, string baseName, string className, string fieldList){
    // Create map with key = field name, value = field type
    int pos;
    string field;
    string field_type;
    string field_name;
    string temp = fieldList;
    unordered_map<string, string> field_map = {};
    int num_fields = std::count(fieldList.begin(), fieldList.end(), ',') + 1;
    while((pos = temp.find(",")) != -1){
        field = temp.substr(0, pos);
        field_type = field.substr(0, field.find(" "));
        field_name = field.substr(field.find(" ") + 1);
        field_map.insert({field_name, field_type});
        temp = temp.substr(pos + 2);
    }
    field_type = temp.substr(0, temp.find(" "));
    field_name = temp.substr(temp.find(" ") + 1);
    field_map.insert({field_name, field_type});

    // Constructor
    file << className + "::" + className + "(";
    int counter = 0;
    for (auto const& x : field_map){
        file << addPointer(x.second) + " " + x.first + (counter < num_fields - 1 ? ", " : "");
        counter++;
    }
    file << ") : ";
    counter = 0;
    for (auto const& x : field_map){
        file << x.first + "(" + x.first + ")" + (count < num_fields - 1 ? ", " : "");
        counter++;
    }
    file << " {}" << endl;
    
    // visitor pattern override
    file << "\tvoid " + className + "::accept(Visitor *visitor) const {" << endl;
    file << "\t\tvisitor->visit" + className + "(*this);" << endl;
    file << "\t}" << endl;
    file << "};" << endl; 
}

void GenerateAst::generateVisitor(ofstream& file, unordered_map<string, string> class_fieldmap){
    file << "class Visitor{" << endl;
    file << "public:" << endl;
    for (auto const& kp : class_fieldmap){
        string className = kp.first;
        file << "\tvirtual void visit" + className + "(" + className + " " + toLower(className) + ") const = 0;" << endl;
    }
    file << "};" << endl;
}

void GenerateAst::generateH(string outputDir, string baseName, unordered_map<string, string> class_fieldsmap){
    string path = outputDir + "/" + baseName + ".h";
    ofstream file(path);
    file << "#ifndef " << baseName << "_H" << endl;
    file << "#define " << baseName << "_H" << endl;
    file << endl;
    file << "#include <string>" << endl;
    file << "#include <vector>" << endl;
    file << "#include \"../Token.h\"" << endl;
    
    file << endl;
    file << "using namespace std;" << endl;
    file << endl;

    // Expr class
    file << "class Expr{ " << endl;
    file << "public:" << endl;
    file << "\tvirtual ~Expr() {}" << endl;
    file << "\tvirtual void accept(Visitor *visitor) const = 0;" << endl;
    file << "};" << endl;
    file << endl;

    // The AST classes.
    for (auto const& kp : class_fieldsmap) {
        defineTypeH(file, baseName, kp.first, kp.second);
    }
    file << "#endif" << endl;
    file.close();
}

void GenerateAst::defineTypeH(ofstream& file, string baseName, string className, string fieldList){
    // Create map with key = field name, value = field type
    int pos;
    string field;
    string field_type;
    string field_name;
    string temp = fieldList;
    unordered_map<string, string> field_map = {};
    int num_fields = std::count(fieldList.begin(), fieldList.end(), ',') + 1;
    while((pos = temp.find(",")) != -1){
        field = temp.substr(0, pos);
        field_type = field.substr(0, field.find(" "));
        field_name = field.substr(field.find(" ") + 1);
        field_map.insert({field_name, field_type});
        temp = temp.substr(pos + 2);
    }
    field_type = temp.substr(0, temp.find(" "));
    field_name = temp.substr(temp.find(" ") + 1);
    field_map.insert({field_name, field_type});

    // Create class with constructor and accept method
    int counter = 0;
    file << "class " + className + " : public " + baseName + " {" << endl;
    file << "public:" << endl;
    for (auto const& x : field_map){
        file << "\t" + addPointer(x.second) + " " + x.first + ";" << endl;
    }
    file << "\t" + className + "(";
    for (auto const& x : field_map){
        file << addPointer(x.second) + " " + x.first + (counter < num_fields - 1 ? ", " : "");
        counter++;
    }
    file << ");" << endl;
    file << "\tvoid accept(Visitor *visitor) const override;" << endl;
    file << "};"
}

string GenerateAst::toLower(string s){
    string result = "";
    for (char c : s){
        result += tolower(c);
    }
    return result;
}


int main(int argc, char* argv[]){
    GenerateAst generateAst;
    generateAst.main(argc, argv);
}