/*
    Implement binary search using recursion.
*/
#include <iostream>
using namespace std;
 
int binarySearch(int *arr, int start, int end, int key) {
    if(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid]) 
            return binarySearch(arr, start, mid - 1, key);
        else    
            return binarySearch(arr, mid + 1, end, key);
    }
    return -1; // key is not found
} 
 
int main() {
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << "Enter the key to be searched: ";
    int key;
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key);
    if(result == -1)
        cout << "Key not found \n";
    else    
        cout << "Key found at index: " << result << '\n';
 
    return 0;
}