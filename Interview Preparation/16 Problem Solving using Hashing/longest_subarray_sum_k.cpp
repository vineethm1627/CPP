/*
    Find the longest subarray with sum = K.
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int maxLenKSum(int *arr, int n, int k) {
    unordered_map<int, int> m; //{prefix_sum, first occurrence index}
    int prefix_sum = 0, max_len = 0;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(prefix_sum == k)
            max_len = max(max_len, i + 1);
        
        if(m.find(prefix_sum - k) != m.end())
            max_len = max(max_len, i - m[prefix_sum - k]);
        else 
            m[prefix_sum] = i;
    }
    return max_len;
}


int main() {

    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxLenKSum(arr, n, k) << endl;
 
    return 0;
}