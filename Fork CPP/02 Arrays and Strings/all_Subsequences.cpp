/*
    for an array of size = n
    Total number of subarrays/substrings = n(n+1)/2
    Total number of subsequences = 2^n - 1 

    Note: 
        Every subarray is a subsequence.
        Subsequences is a generalization of subarrays.
*/
// given an array generate all the subsequences.
#include <iostream>
#include <cmath>
using namespace std;

void allSubsequences(int arr[], int n) {
    int size = pow(2, n); // total number of subsets ie. no. of elements in the powerset.
    // run i from 00000...1 to 11111....1
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < n; j++) {
            // if the jth bit from right is set then print the jth element.
            if(i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "All non-empty subsequences" << endl;
    allSubsequences(arr, n);

    return 0;
}