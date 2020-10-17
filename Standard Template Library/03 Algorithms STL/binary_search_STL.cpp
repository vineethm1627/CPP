#include <iostream>
#include <algorithm>
using namespace std;

// binary search algorithm is used when the array is already sorted.
// takes O(logn) time.
// frequency of a particular element could be found in O(logn) time.

int main() {

    int arr[] = {10, 20, 30, 39, 39, 39, 39, 100, 110, 150};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout << "Enter the key value to be searched : ";
    int key;
    cin >> key;
    
    bool present = binary_search(arr, arr + n, key);
    if(present) {
        cout << "Element is present" << endl;
    }
    else {
        cout << "Element is absent" << endl;
    }

    // two more things 
    // get the index of the element.
    // lower_bound(start, end, key) returns the address of the first element >= key.
     auto it1 = lower_bound(arr, arr + n, key);
     cout << "lower_bound index : " << it1 - arr << endl;

    // if(it1 == arr + n) {
    //     cout << "Element is not present";
    // }
    
    // upper_bound returns the address of the first element > key [= doesn't hold here]
     auto it2 = upper_bound(arr, arr + n, key);
     cout << "upper_bound index : " << it2 - arr << endl;

    cout << "Frequency of the Element : " << *it1 << " in the Sorted array : " << it2 - it1 << endl; 


    return 0;
}