#include <iostream>
#include <string>

using namespace std;

class Test{
    int main_(){
        string inputstr;
        cout << "Enter a string: ";
        cin >> inputstr;
        cout << "You entered: " << inputstr << endl;
    }
};

int main(){
    Test test;
    test.main_();
    return 0;
}