/*
    similar to binary search.
    only change is that once the element is found.
        1) we store the index of the element
        2) for first occurrence we search the left part of the array
        3) for last occurrence we search the right part of the array
*/
#include <iostream>
using namespace std;

int lower_bound(int *arr, int n, int key) {
    int left = 0, right = n - 1, index = -1;

    // update in the direction where index value gets lower
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == key) {
            index = mid;
            right = mid - 1;
        }
        else if(key < arr[mid]) 
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return index; // first occurrence of the key value.
}

int last_occur(int *arr, int n, int key) {
    int left = 0, right = n - 1, index = -1;

    // update in the direction where index value gets higher
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == key) {
            index = mid;
            left = mid + 1;
        }
        else if(key < arr[mid])
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return index;
}


int main() {

    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10 ,12, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cin >> key;

    cout << "lower_bound : " << lower_bound(arr, n, key) << endl;
    cout << "last occurrence : " << last_occur(arr, n, key) << endl;
    return 0;
}