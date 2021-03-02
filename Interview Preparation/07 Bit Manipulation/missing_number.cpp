/*
    Find the Missing Number
    You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.
    Example: 

    Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
    Output: 5
    Explanation: The missing number from 1 to 8 is 5

    Input: arr[] = {1, 2, 3, 5}
    Output: 4
    Explanation: The missing number from 1 to 5 is 4
*/
#include <iostream>
using namespace std;

int getMissingNo(int *arr, int n) {
    int ans = 0;
    for(int i = 1; i <= n + 1; i++)
        ans ^= i;
    
    for(int i = 0; i < n; i++)
        ans ^= arr[i];
    return ans;
}

int main() {
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int miss = getMissingNo(arr, n);

    cout << miss;
}