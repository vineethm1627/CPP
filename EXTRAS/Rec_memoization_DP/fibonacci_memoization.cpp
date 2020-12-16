/*
    nth fibonacci number using memoization.
*/
#include <iostream>
#include <cstring>
using namespace std;

int fibonacci(int n, int *memo) {
    int ans1, ans2, final_ans;
    if(n <= 1) 
        return n;
    if(memo[n - 1] == -1) { // this value is not yet stored.
        ans1 = fibonacci(n - 1, memo);
        memo[n - 1] = ans1;
    } 
    else {
        // the value is already computed earlier, so directly use the value without re-computation.
        ans1 = memo[n - 1];
    }

    if(memo[n - 2] == -1) {
        ans2 = fibonacci(n - 2, memo);
        memo[n - 2] = ans2;
    }
    else {
        ans2 = memo[n - 2];
    }

    final_ans = ans1 + ans2;
    return final_ans;
}

int main() {

    int n;
    cin >> n;

    int memo[n + 1];
    memset(memo, -1, sizeof(memo));

    cout << fibonacci(n, memo);
    return 0;
}