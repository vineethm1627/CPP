/*
    a pair is said to be inverted if a[i] > a[j] for i < j
*/
#include <iostream>
using namespace std;

int merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    int temp[10000];
    int count = 0;

    while(i <= mid and j <= end) {
        if(arr[i] <= arr[j]) 
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= end) 
        temp[k++] = arr[j++];
    // copy the elements back to the original array
    for(int i = start; i <= end; i++)
        arr[i] = temp[i];

    return count;
}
 
int inversionCount(int *arr, int start, int end) {
    // base case
    if(start >= end)
        return 0;
    
    // merge sort
    int mid = start + (end - start) / 2;
    int x = inversionCount(arr, start, mid);
    int y = inversionCount(arr, mid + 1, end);
    int z = merge(arr, start, mid, end); // cross-inversions
    
    return x + y + z;
} 
 
int main() {
    
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    cout << inversionCount(arr, 0, n - 1) << "\n";
 
    return 0;
}