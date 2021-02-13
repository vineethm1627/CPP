/*
    Like merge sort it is Divide and Conquer algorithm.
    T(n) = O(nlogn)
    In worst case it is O(n^2) which can be avoided by using randomized quicksort.

    The key processs is partition() whose main role is, given an array and an element x of the array as pivot
    put x at its correct position in the sorted array and put all the smaller elements on its left and all the greater elements 
    on its right.
*/
#include <iostream>
using namespace std;

// O(n) time complexity
int partition(int *arr, int start, int end) {
    int i = start - 1;
    int j = start;
    int pivot = arr[end];
    for(; j < end; j++) {
        if(arr[j] <= pivot) {
            // merge the smaller element in region 1
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}
 
void quicksort(int *arr, int start, int end) {
    // base case
    if(start >= end)
        return;
    
    // recursive calls
    int p = partition(arr, start, end);
    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
}
 
int main() {
    
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    quicksort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
