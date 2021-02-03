/*
    find count of BSTs that can be formed using n nodes numbered 1, 2, 3 .... n.
    for n = 3 there are 5 possible BSTs.
    any ith element could become the root node.

    in the left subtree we can have f(i - 1) nodes. 
    in the right subtree we can have f(n - i) nodes.

    in order to create a complete tree, we need:
        left .. root .. right
    
    for ith node the root is fixed
        xC1 ways to pick one tree from left subtree
        yC1 ways to pick one tree from right subtree

       total_trees =  summation of (f(i - 1) * f(n - i)) from i = 1 to n

    We can use DP since there are overlapping problems.

    f(0) = 1 // null tree
    f(1) = 1 // tree with only one root
    f(2) ==> n = 2
    f(0).f(1) + f(1).f(0) = 2
    so f(2) = 2

    f(3) ==> n = 3
    i = 1, 2, 3
    ans = f(0).f(2) + f(1).f(1) + f(2).f(0) = 5
    so f(3) = 5

    we can clearly observe that there are a lot of overlapping sub-problems

    catalan series formula: 2nCn / (n + 1)
*/
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long int

ll countBST(ll n) {
    ll dp[n + 1] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

ll factorial(ll n) {
    ll result = n;
    while(n > 1) {
        n--;
        result *= n;
    }
    return result;
}

ll pnc(ll n) {
    return (factorial(2*n) / (pow(factorial(n), 2))) / (n + 1);
}

int main() {
    ll n;
    cin >> n;

    cout << countBST(n) << endl;
    cout << pnc(n) << endl;

    return 0;
}
