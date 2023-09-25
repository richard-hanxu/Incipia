#include <string>
#include <vector>

using namespace std;

class GenerateAst{
public:
    int main(int argc, char* argv[]);
private:
    static void defineAst(string outputDir, string baseName, vector<string> types);
    static void defineType(ofstream& file, string baseName, string className, string fieldList);
};