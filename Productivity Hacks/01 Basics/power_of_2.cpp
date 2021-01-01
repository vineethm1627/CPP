/*
    given a number, print if it is a power of 2 or not.
*/
#include <iostream>
using namespace std;

bool powerTwo(int n) {
    // necessary to use brackets as '==' as higher precedence order than '&'
    if((n & (n - 1)) == 0)
        return true;
    return false;
}

int main() {

    int n;
    cin >> n;

    cout << powerTwo(n) << endl;

    return 0;
}