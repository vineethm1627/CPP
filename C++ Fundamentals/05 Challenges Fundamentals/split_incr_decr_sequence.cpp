/*
    Split the array elements into strictly increasing and decreasing sequence
    Given an array of N elements. The task is to split the elements into two arrays say a1[] and a2[] such that one contains strictly increasing elements and the other contains strictly decreasing elements and a1.size() + a2.size() = a.size(). If it is not possible to do so, print -1 or else print both the arrays.

    Note: There can be multiple answers and the order of elements needs not to be the same in the child arrays.

    Examples:

    Input: a[] = {7, 2, 7, 3, 3, 1, 4}
    Output: a1[] = {1, 2, 3, 4, 7} , a2[] = {7, 3}

    Input: a[] = {1, 2, 2, 1, 1}
    Output: -1
    It is not possile

    Approach: The following steps are followed to solve the above problem:

    Initialize two vectors v1 and v2 which stores increasing and decreasing numbers.
    Use hashing to know the occurrence of the number in the array.
    If the number appears to come for the first time, then store it in v1.
    If the number appears to come for the second time, then store it in v2.
    If the number appears for more than 2 times, then it is not possible to store to create a strictly increasing and strictly decreasing array.
    At last, sort the first vector in increasing order and the second vector in decreasing order and print them.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void splitArray(int arr[], int n) {
    vector<int> v1, v2;
    unordered_map<int, int> mii;

    for(int i = 0; i < n; i++) {
        // store the count of occurence.
        mii[arr[i]]++;
        
        // first occurence push it to v1.
        if(mii[arr[i]] == 1) {
            v1.push_back(arr[i]);
        }
        // second occurence push it to v2.
        else if(mii[arr[i]] == 2) {
            v2.push_back(arr[i]);
        }
        // more than 2 times occurence, would break strictly increasing/ decreasing condition.
        else {
            cout << "Not possible" << endl;
            return;
        }
    }
    // sort v1 in increasing order.
    sort(v1.begin(), v1.end());
    // sort v2 in descending order.
    sort(v2.begin(), v2.end(), greater<int>());

    // print the increasing sequence.
    for(int i : v1) {
        cout << i << " ";
    }
    cout << endl;
    // print the decreasing sequence.
    for(int i : v2) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {7, 2, 7, 3, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    splitArray(arr, n);

    return 0;
}