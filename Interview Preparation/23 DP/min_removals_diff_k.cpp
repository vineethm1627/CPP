// Problem Link: https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1000][1000]; 

// recursive solution
int minRemoveCount(int *arr, int start, int end, int k) {
    // base case: all the elements are removed
    if(start >= end)
        return 0;
    // no more removals are required
    if(arr[end] - arr[start] <= k)
        return 0;
    // if the value is already present in the dp array
    if(dp[start][end] != -1)
        return dp[start][end];
    if(arr[end] - arr[start] > k) {
        int remove_min = minRemoveCount(arr, start + 1, end, k);
        int remove_max = minRemoveCount(arr, start, end - 1, k);
        // store the result in the dp array
        dp[start][end] = 1 + min(remove_min, remove_max);
    }
    return dp[start][end];
}
 
int main() {
    
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    memset(dp, -1, sizeof(dp));
    // sort the array
    sort(arr, arr + n);
    cout << "min removal required: ";
    if(n == 1)
        cout << 0 << endl;
    else    
        cout << minRemoveCount(arr, 0, n - 1, k) << endl;

 
    return 0;
}