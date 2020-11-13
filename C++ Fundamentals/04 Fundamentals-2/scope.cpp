/*
    scope : defined for variable (accessible --> lifetime and visibility)
    
        1) local scope
        2) global scope
*/


#include <iostream>
using namespace std;

int x = 100; // global variable

int main() {

    int x = 10; // local scope has more preference than global scope
    cout << "Loop x : ";
    for(int x = 0; x < 5; x++) {
        cout << x << " ";
    }
    cout << endl;
    cout << "local x : " << x << endl; // local x
    // using scope resolution operator "::"
    cout << "global x : " << ::x << endl; // global x
    
    return 0;
}
