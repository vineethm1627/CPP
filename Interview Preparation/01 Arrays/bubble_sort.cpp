#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    /* in each iteration push the larger elements towards the end of the array
       by pair-wise swapping.
       At the end of each iteration, the largest element gets settled at the last.
       Also the length of the next iteration decreases by 1.
       So at the end of the second iteration, the second largest element gets settled
       at the second last position.
       
       In simple words we are building a sorted array from the end.
    */
    int n, x;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the elements of the array : ";
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    cout << "Sorted array : ";
    for(int i : arr) {
        cout << i << " ";
    }
    
    return 0;
}