/*
    consider a sorted array of distinct numbers in increasing order. The array has been rotated
    clockwise K times.

    Given the array, find the value of K.
*/
#include <iostream>
using namespace std;

int countRotated(int *arr, int n) {
    int start = 0, end = n - 1; 
    int index = 0;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] > arr[mid + 1] and mid < end)
             index = mid + 1;
        
        else if(arr[mid] < arr[mid - 1] and mid > start)
            index = mid;
        
        // narrow down the search space
        // go towards the right
        if(arr[mid] > arr[start])
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return index;
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << countRotated(arr, n) << endl;

    return 0;
}