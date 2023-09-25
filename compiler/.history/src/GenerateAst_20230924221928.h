#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class GenerateAst{
public:
    int main(int argc, char* argv[]);
private:
    static string addPointer(string type);
    static void defineAst(string outputDir, string baseName, vector<string> types);
    static void generateCpp(string outputDir, string baseName, unordered_map<string, string> class_fieldsmap);
    static void generateH(string outputDir, string baseName, unordered_map<string, string> class_fieldsmap);
    static void defineTypeCpp(ofstream& file, string baseName, string className, string fieldList);
    static void generateVisitor(ofstream& file, unordered_map<string, string> types);
    static string toLower(string s);
};