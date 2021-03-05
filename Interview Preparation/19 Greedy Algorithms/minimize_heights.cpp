/*
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
Note: Assume that height of the tower can be negative.

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between 
the largest and the smallest is 17-6 = 11. 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
       sort(arr, arr + n);
       // if you add k to all elements / subtract k from all the elements
       int result = arr[n - 1] - arr[0];
       int min_val = arr[0] + k, max_val = arr[n - 1] - k;
       for(int i = 1; i < n; i++) {
           min_val = min(arr[0] + k, arr[i] - k);
           max_val = max(arr[n - 1] - k, arr[i - 1] + k);
           result = min(result, max_val - min_val);
       }
       return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}