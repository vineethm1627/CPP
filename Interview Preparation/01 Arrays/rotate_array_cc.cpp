/*
    Given an array, rotate it in counter-clockwise direction ie. towards the left by k positions.

    input:
    arr = {1, 2, 3, 4, 5} and k = 2

    output:
    arr = {3, 4, 5, 1, 2};

    approach used is reverse the array in two parts and reverse the entire array.
*/
#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int *arr, int n, int k) {
    int temp, j, d;
    int sets = __gcd(n, k);

    for(int i = 0; i < sets; i++) {
        temp = arr[i];
        j = i;
        
        while(true) {
            d = (j + k) % n;
            if(d == i) 
                break;
            arr[j] = arr[d];
            j = d;
        }
        arr[j] = temp;
    }

}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // rotate the array by 2 positions to the left.

    rotate(arr, n, k);
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}