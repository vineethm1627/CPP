/*
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Note: Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
1 <= W <= 1000
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/
#include<bits/stdc++.h>
using namespace std;

int knapSack(int val[], int w[], int n, int W) {
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i < n; i++) {
        for(int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], val[i] + dp[j - w[i]]);
        }
    }
    return dp[W];
}

int main(){
    int n, W;
    cin >> n;
    
    int w[n], val[n];
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cin >> W;
    
    cout << knapSack(val, w, n, W);
    
     
    return 0;
}