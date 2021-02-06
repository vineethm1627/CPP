/*
    Given an array of positive numbers, find maximum sum such that no 2 elements are adjacent to each other.
*/
#include <iostream>
using namespace std;

// Dynamic Programming problem
int adjMaxSum(int *arr, int n) {
    int incl = arr[0], excl = 0;
    // incl tells the max sum till that index including that index element
    // excl tells the max sum till that index excluding that index element

    for(int i = 1; i < n; i++) {
        int temp = incl;
        // max sum including the current element
        incl = max(incl, excl + arr[i]);
        // max sum excluding the current element
        excl = temp;
    }
    return incl;
}

int main() {

    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << adjMaxSum(arr, n) << endl;

    return 0;
}