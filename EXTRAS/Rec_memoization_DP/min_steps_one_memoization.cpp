/*
    given a number, you need to tell the minimum number of steps required to reduce the number to 1.

    The following 3 operations are allowed.
        1) subtract 1
        2) if divisible by 2 divide it by 2
        3) if divisible by 3 divide it by 3
*/
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int minStepsOne(int n, int *memo) {
    int res;
    if(n == 1) // base case
        return 0;
    
    if(memo[n] != -1) // the value has been computed earlier
        return memo[n];
    
    res = minStepsOne(n - 1, memo);
    if(n % 2 == 0)
        res = min(res, minStepsOne(n / 2, memo));
    if(n % 3 == 0)
        res = min(res, minStepsOne(n / 3, memo));
    
    // store the result in the array
    memo[n] = 1 + res;
    return memo[n];
}

int main() {

    int n;
    cin >> n;

    int memo[n + 1];
    memset(memo, -1, sizeof(memo));

    cout << minStepsOne(n, memo);
    return 0;
}