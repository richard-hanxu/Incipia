#include <iostream>
#include <string>

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

#include <iostream>
#include <vector>
#include <string>

enum Denum{
    A, B, C
};

class Dummy {
public:
    Dummy(int value, Denum denum, string s) : data(value), denum(denum), s(s) {}
    int getData() const { return denum; }

private:
    int data;
    Denum denum;
    string s;
};


int main(){
    /*
    Test test;
    test.main();
    */

    std::vector<Dummy> myVector;

    // Create an anonymous instance and insert it into the vector
    myVector.push_back(Dummy(42, A, "asdfjkl;"));

    // Access the data from the vector
    for (const Dummy& obj : myVector) {
        std::cout << "Data: " << obj.getData() << std::endl;
    }

    return 0;
}