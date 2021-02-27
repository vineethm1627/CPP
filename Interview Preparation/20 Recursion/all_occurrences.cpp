/*
    Given an array, find all the occurrences of the key in the array using recursive linear search.
    Return the indices of all the occurrences.
*/
#include <iostream>
using namespace std;

// returns the size of the output array/ count of total occurrences / frequency of the key
int storeOccur(int *arr, int i, int n, int key, int *indices, int j) {
    // base case 
    if(i == n)
        return j;
    
    // recursive calls
    if(arr[i] == key) {
        indices[j] = i;
        // increment j to accomodate the current occurence.
        return storeOccur(arr, i + 1, n, key, indices, j + 1);
    }
    else 
        // j remains unchanged
        return storeOccur(arr, i + 1, n, key, indices, j);
}

void allOccur(int *arr, int i, int n, int key) {
    // base case
    if(i == n)
        return;
    
    if(arr[i] == key) 
        cout << i << " ";
    
    // recursive calls
    allOccur(arr, i + 1, n, key);
}
  
int main() {
    
    int n, key;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter key: ";
    cin >> key;

    allOccur(arr, 0, n, key);
    cout << endl;
    int indices[n];
    int size = storeOccur(arr, 0, n, key, indices, 0);
    
    for(int i = 0; i < size; i++) 
        cout << indices[i] << " ";

    return 0;
}