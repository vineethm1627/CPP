/*
    PS : read a stream of integers until you get a multiple of 7
    
    break : used to terminate a loop based on a certain condition
    continue : skips a particular iteration of a loop
*/
#include <iostream>
using namespace std;

int main() {

    int n;
    // infinite loop
    while(true) {
        cin >> n;
        if(n % 7 == 0) {
            break; // breaks the while loop
        }
        else if(n % 4 == 0) {
            continue;
        }
        else {
            cout << n << endl;
        }
    }
    
    return 0;
}