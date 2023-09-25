#include <string>
#include <vector>

using namespace std;

class GenerateAst{
public:
    int main(int argc, char* argv[]);
private:
    static string addPointer(string type);
    static void defineAst(string outputDir, string baseName, vector<string> types);
    static void defineType(ofstream& file, string baseName, string className, string fieldList);
    static void generateVisitor(ofstream& file, vector<string> types);
    static string toLower(string s);
};