#include <iostream>
#include <string>
#include <vector>
#include "Token.h"

using namespace std;

class Parser{
public:
    Parser(vector<Token> tokens);
private:
    int current = 0;
    const vector<Token> tokens; 
};
