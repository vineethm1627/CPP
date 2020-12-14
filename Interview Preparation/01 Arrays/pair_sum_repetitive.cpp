/*
    You have been given an integer array and a number 'num'. 
    Find and return the total number of pairs in the array/list which sum to 'num'.

    input 
    1
    5
    3 3 3 3 3
    6

    output 
    10

    input
    1
    4
    0 6 0 0 
    6

    output 
    3
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int countPairs(int *arr, int n, int sum) {
    int count = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++) 
        m[arr[i]]++;
    for(int i = 0; i < n; i++) {
        count += m[sum - arr[i]];
        if(sum - arr[i] == arr[i]) {
            // the pair(arr[i], arr[i]) is counted which should not be included
            count--;
        }
    }
    return count / 2;
}

int main() {

    int n, sum;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> sum;
    cout << countPairs(arr,n, sum) << endl;
    delete [] arr;
    return 0;
}