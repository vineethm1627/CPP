/*
    Given an array, find the first occurrence of the key in the array using recursive linear search.
    Return the index of the first occurrence.
*/
#include <iostream>
using namespace std;

int firstOccur(int *arr, int n, int key) {
    // base case
    if(n == 0) 
        return -1;
    // recursive calls
    if(arr[0] == key)
        return 0;

    int index = firstOccur(arr + 1, n - 1, key);
    if(index == -1)
        return -1;
    else    
        return index + 1;
}

// different style of writing the same function
// i is the index of the current element
int linearSearch(int *arr, int i, int n, int key) {
    // base case
    if(i == n)
        return -1;
    
    // recursive calls
    if(arr[i] == key)
        return i;
    
    return linearSearch(arr, i + 1, n, key);
}
  
int main() {
    
    int n, key;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter key: ";
    cin >> key;

    cout << firstOccur(arr, n, key) << endl;
    cout << linearSearch(arr, 0, n, key);
 
    return 0;
}