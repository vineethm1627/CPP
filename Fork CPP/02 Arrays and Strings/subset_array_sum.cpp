/*
    Subset array sum by generating all the subsets
    Given an array of size N and a sum, the task is to check whether some array elements can be added to sum to N .
    Note: At least one element should be included to form the sum.(i.e. sum cant be zero)

    Input: array = {-1, 2, 4, 121}, sum = 5
    Output: YES
    Explanation : The array elements 2, 4, -1 can be added to sum to 5
    Approach: The idea is to generate all subsets using Generate all subsequences of array and correspondingly check if any subsequence has the sum equal to the given sum.

*/
#include <iostream>
#include <cmath>
using namespace std;

void findSubsetSum(int arr[], int n, int sum) {
    for(int i = 1; i < pow(2, n); i++) {
        int s = 0;
        for(int j = 0; j < n; j++) {
            // if the jth bit from right is 1(set) then add the jth element
            /*
                j = 0 --> 1 << 0 = 1 ie 1
                j = 1 --> 1 << 1 = 2 ie 10
                j = 2 --> 1 << 2 = 4 ie 100
                .... --> 10000....0

                with the help of this we could pick the jth bit from left
            */
            if(i & (1 << j)) {
                s += arr[j];
            }
        }

        if(sum == s) {
            cout << "YES" << endl;
            return;
        }

    }
    cout << "NO" << endl;
}

int main() {
    int sum = 5;
    int arr[] = {-1, 2, 4, 121, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSubsetSum(arr, n, sum);
    return 0;
}