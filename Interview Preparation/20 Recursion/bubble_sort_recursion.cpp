#include <iostream>
using namespace std;

// in each iteration, the largest element settles at the right position
void bubbleSort(int *arr, int n) {
    // base case
    if(n == 1) 
        return;
    
    // recursive calls
    for(int j = 0; j < n - 1; j++) {
        if(arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
    }
    bubbleSort(arr, n - 1);
} 

// j controls the inner loop,n controls the outer loop
void bubbleSort_rec(int *arr, int j, int n) {
    // base case
    if(n == 1)
        return;
    // corner case for j ie. one entire iteration/ pass is over.
    if(j == n - 1)
        return bubbleSort_rec(arr, 0, n - 1);

    // recursive calls
    if(arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    
    bubbleSort_rec(arr, j + 1, n);
}

int main() {
    
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    bubbleSort_rec(arr, 0, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}