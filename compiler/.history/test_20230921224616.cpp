#include <iostream>
#include <string>

using namespace std;

class Test{
public:
    void main(){
        string inputstr;
        cout << "Enter a string: ";
        cin >> inputstr;
        cout << "You entered: " << inputstr << endl;
    }
};

int main(){
    Test test;
    test.main();
    return 0;
}