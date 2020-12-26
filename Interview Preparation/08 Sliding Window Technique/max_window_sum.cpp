/*
    Given an array of integers of size ‘n’.
    Our aim is to calculate the maximum sum of ‘k’ 
    consecutive elements in the array.

    Input  : arr[] = {100, 200, 300, 400}
            k = 2
    Output : 700

    Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
            k = 4 
    Output : 39
    We get maximum sum by adding subarray {4, 2, 10, 23}
    of size 4.

    Input  : arr[] = {2, 3}
            k = 3
    Output : Invalid
    There is no subarray of size 3 as size of whole
    array is 2.
*/
#include <iostream>
using namespace std;

int maxWindowSum(int *arr, int n, int k) {
    if(n < k)
        return -1;
    
    int max_sum = 0;
    for(int i = 0; i < k; i++) 
        max_sum += arr[i];
    
    int window_sum = max_sum;
    for(int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxWindowSum(arr, n, k);

    return 0;
}