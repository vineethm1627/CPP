/*
    Given an array of integers. Find a peak element in it. An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour. 

    Example:
    Input: array[]= {5, 10, 20, 15}
    Output: 20
    The element 20 has neighbours 10 and 15,
    both of them are less than 20.

    Input: array[] = {10, 20, 15, 2, 23, 90, 67}
    Output: 20 or 90
    The element 20 has neighbours 10 and 15, 
    both of them are less than 20, similarly 90 has neighbous 23 and 67.
    Following corner cases give better idea about the problem. 

    If input array is sorted in strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
    If the input array is sorted in strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
    If all elements of input array are same, every element is a peak element.
*/
#include <iostream>
using namespace std;

int peak(int arr[], int n) {
    int start = 0, end = n - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        // compare middle element with its neighbors if they exist.
        if((mid == 0 or arr[mid] >= arr[mid - 1]) and (mid == n - 1 or arr[mid] >= arr[mid + 1])) 
            return mid;
        // if middle element is not peak and its left neighbour is greater than it
        // left half must have a peak element
        else if(mid > 0 and arr[mid - 1] > arr[mid])
            end = mid - 1;
        else 
            start = mid + 1;
    }
    return n - 1; // not really needed
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    cout << peak(arr, n) << endl;

    return 0;
}