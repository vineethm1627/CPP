/*
    Given an array, rotate it in clockwise direction ie. towards the right by k positions.

    input:
    arr = {1, 2, 3, 4, 5} and k = 2

    output:
    arr = {4, 5, 1, 2, 3};

    approach used is reverse the array in two parts and reverse the entire array.
*/
#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int *arr, int n, int k) {
    k = k % n;
    // reverse part 1 [0, n - k - 1]
    reverse(arr, arr + n - k);
    // reverse part 2 [n - k, n - 1]
    reverse(arr + n - k, arr + n);
    // reverse the entire array
    reverse(arr, arr + n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // rotate the array by 3 positions to the right.

    // temp[(i + k) % n] = arr[i]; --> uses extra space.
    rotate(arr, n, k);
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}