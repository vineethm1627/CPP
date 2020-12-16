/*
    given a number, you need to tell the minimum number of steps required to reduce the number to 1.

    The following 3 operations are allowed.
        1) subtract 1
        2) if divisible by 2 divide it by 2
        3) if divisible by 3 divide it by 3
*/
#include <iostream>
#include <climits>
using namespace std;

int minStepsOne(int n) {
    if(n <= 1)
        return 0;
    
    int x = minStepsOne(n - 1);
    int y = INT_MAX;
    int z = INT_MAX;

    if(n % 2 == 0) 
        y = minStepsOne(n / 2);
    if(n % 3 == 0)
        z = minStepsOne(n / 3);
    
    return 1 + min(x, min(y, z));
}

int main() {

    int n;
    cin >> n;

    cout << minStepsOne(n);
    return 0;
}