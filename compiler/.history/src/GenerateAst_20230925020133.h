#include <string>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

class GenerateAst{
public:
    int main(int argc, char* argv[]);
private:
    static string addPointer(string type);
    static void defineAst(string outputDir, string baseName, vector<string> types);
    static void generateCpp(string outputDir, string baseName, vector<array<string, 2>> class_fieldsmap);
    static void generateH(string outputDir, string baseName, vector<array<string, 2>> class_fieldsmap);
    static void defineTypeCpp(ofstream& file, string baseName, string className, string fieldList);
    static void defineTypeH(ofstream& file, string baseName, string className, string fieldList);
    static void generateVisitor(ofstream& file, unordered_map<string, string> types);
    static string toLower(string s);
};