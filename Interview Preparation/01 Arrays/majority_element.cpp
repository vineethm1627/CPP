/*
    Write a function to find if a given integer x appears more than n/2 times in a sorted array of n integers. 

    Examples: 

    Input: arr[] = {1, 2, 3, 3, 3, 3, 10}
    Output: True (3 appears more than n/2 times in the given array)

    Input: arr[] = {1, 1, 1, 2, 2}
    Output: True (1 appears more than n/2 times in the given array)
*/
#include <iostream>
#include <algorithm>
using namespace std;

void isMajority(int arr[], int n) {
    int e = arr[n / 2];
    auto lb = lower_bound(arr, arr + n, e);
    auto ub = upper_bound(arr, arr + n, e);
    if(ub - lb > n / 2) {
        cout << arr[n / 2] << " occurs " << (ub - lb) << " times" << endl;
    }
    else {
        cout << arr[n / 2] << " doesn't occur max number of times" << endl;
    }

}
 
int main() {

    int arr[] = {1, 3, 3 ,3, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    isMajority(arr, n);
    return 0;
}