#include <iostream>
#include <string>

using namespace std;

class Test{
public:
    void main(){
        string inputstr;
        cout << "Enter a string: ";
        cin >> inputstr;
        inputstr = nullptr;
        cout << "You entered: " << inputstr << endl;
    }
};

int main(){
    Test test;
    test.main();
}