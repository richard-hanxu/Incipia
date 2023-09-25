#include <string>

using namespace std;

class GenerateAst{
public:
    int main(int argc, char* argv[]);
private:
    static void defineAst(string outputDir, string baseName, vector<string> types);
};