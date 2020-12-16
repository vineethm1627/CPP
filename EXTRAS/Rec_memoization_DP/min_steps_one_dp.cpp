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

int minStepsOne(int n) {
    int dp[n + 1];
    dp[1] = 0; // base condition

    for(int i = 2; i <= n; i++) {
        int res = dp[i - 1]; 
        if(i % 2 == 0) 
            res = min(res, dp[i / 2]);
        if(i % 3 == 0)
            res = min(res, dp[i / 3]);
        dp[i] = 1 + res;
    }
    return dp[n];
}

int main() {

    int n;
    cin >> n;

    cout << minStepsOne(n);
    return 0;
}