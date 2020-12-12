#include <iostream>
#include <algorithm>
using namespace std;

int kadane_dp(int *arr, int n) {
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        dp[i] = max(arr[i], arr[i] + dp[i + 1]);
    }

    return *max_element(dp, dp + n);
}

int main() {
    int arr[] = {10, 20, -30, 40, -50, 60, -10, 30};
    int n = 8;

    cout << kadane_dp(arr, n); // 80
    return 0;
}
