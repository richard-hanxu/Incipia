#include <iostream>
#include <string>
#include "Token.h"

using namespace std;

class Test{
public:
    void main(){
        string inputstr;
        cout << "Enter a string: ";
        cin >> inputstr;
        string test = nullptr; // Causes undefined behaviour
        cout << "You entered: " << inputstr << endl;
    }
};

#include <vector>

enum Denum{
    A, B, C
};

class Dummy {
public:
    Dummy(int value, TokenType denum) : data(value), denum(denum) {}
    int getData() const { return denum; }

private:
    int data;
    TokenType denum;
    string s = "hello";
};

// Node base class
class Node {
public:
    virtual ~Node() {} // Virtual destructor for polymorphism
};

// Binary expression node
class BinaryExpr : public Node {
public:
    BinaryExpr(Node* left, char op, Node* right)
        : left(left), op(op), right(right) {}

    Node* left;
    char op;
    Node* right;
};

// Literal node
class Literal : public Node {
public:
    Literal(int value) : value(value) {}

    int value;
};



int main(){
    /*
    Test test;
    test.main();
    */

    std::vector<Token> myVector;

    // Create an anonymous instance and insert it into the vector
    myVector.push_back(Token(LEFT_BRACE, "test1", "test2", -1));

    // Access the data from the vector
    for (Token obj : myVector) {
        std::cout << obj.toString() << std::endl;
    }

    return 0;
}