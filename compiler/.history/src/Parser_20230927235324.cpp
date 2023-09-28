#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"

Parser::Parser(vector<Token> tokens) : tokens(tokens){
}

bool Parser::expression(){
    return equality();
}



using namespace std;