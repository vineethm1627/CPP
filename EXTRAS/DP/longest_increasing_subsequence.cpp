/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
longest-increasing-subsequence

Examples:

Input: arr[] = {3, 10, 2, 1, 20}
Output: Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output: Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}
*/
#include <iostream>
#include <algorithm>
using namespace std;

int lis(int *arr, int n) {
    int dp[n]; // dp[i] is the max len of increasing subseq ending at arr[i].
    // memset(dp, 1, sizeof(dp)); this statement will set garbage values as setting to 1 is not possible.
    // memset works only for setting values to 0 and -1
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] and dp[i] < 1 + dp[j]) {
                dp[i] = 1 + dp[j];
            }
        }
    }
    return *max_element(dp, dp + n);
}

int main() {

    int arr[] = {5, 4, 11, 1, 16, 8};
    int n = 6;

    cout << lis(arr, n) << endl;

    return 0;
}