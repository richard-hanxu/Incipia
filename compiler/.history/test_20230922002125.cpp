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

enum Denum{
    A, B, C
}

class Dummy {
public:
    Dummy(int value, Denum denum) : data(value) denum(denum) {}
    int getData() const { return data; }

private:
    int data;
    Denum denum;
};


int main(){
    /*
    Test test;
    test.main();
    */

    std::vector<Dummy> myVector;

    // Create an anonymous instance and insert it into the vector
    myVector.push_back(Dummy(42));

    // Access the data from the vector
    for (const Dummy& obj : myVector) {
        std::cout << "Data: " << obj.getData() << std::endl;
    }

    return 0;
}