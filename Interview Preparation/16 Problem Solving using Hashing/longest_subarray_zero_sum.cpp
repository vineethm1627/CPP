/*
    Find the length of the longest subarray with zero sum.
*/
#include <iostream>
#include <unordered_map>
using namespace std;
 
int maxLenZeroSum(int *arr, int n) {
    unordered_map<int, int> m; // {prefix sum, first occurrence index}
    int prefix_sum = 0, max_len = 0;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        if(prefix_sum == 0)
            max_len = max(max_len, i + 1);
        if(m.find(prefix_sum) != m.end()) 
            max_len = max(max_len, i - m[prefix_sum]);
        else
            m[prefix_sum] = i;
    }
    return max_len;
}
 
int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxLenZeroSum(arr, n) << endl;
 
    return 0;
}