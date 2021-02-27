/*
    Given an array, find the last occurrence of the key in the array using recursive linear search.
    Return the index of the last occurrence.
*/
#include <iostream>
using namespace std;

int lastOccur(int *arr, int n, int key) {
    // base case
    if(n == 0)
        return -1;
    
    // recursive calls
    // first make a call and then check
    int index = lastOccur(arr + 1, n - 1, key);
    if(index == -1) {
        if(arr[0] == key)
            return 0;
        else
            return -1;
    }
    else 
        return index + 1;
}
  
int main() {
    
    int n, key;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter key: ";
    cin >> key;

    cout << lastOccur(arr, n, key) << endl;
    return 0;
}