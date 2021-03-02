/*
    Dutch National Flag, 3 way partitioning.
    Sort an array of 0s, 1s and 2s.
    T(n) = O(n)
*/

#include <iostream>
using namespace std;

void dnf_sort(int *arr, int n) {
    // region of 0s{0, low}, region of 1s{low, mid}, region of 2s{high, n - 1}
    // uncertain region or unsorted region{mid, high}.
    // we need to shrink this region{mid, high}.
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high) {
        if(arr[mid] == 0) 
            swap(arr[mid++], arr[low++]);
        else if(arr[mid] == 1)
            mid++;
        else 
            swap(arr[mid], arr[high--]);
    }
}
 
 
int main() {
    
    int arr[] = {2, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    dnf_sort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
        
    return 0;
}