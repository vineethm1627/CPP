#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        // place the current element at its correct position in the sorted part.
        int j = i - 1;
        while(j >= 0 and arr[j] > curr) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr; // curr is placed at its right position.
    }
}

int main() {
    // game of cards.
    // insert the current element at its right position.
    // divide array into 2 parts sorted and unsorted.
    // pick up a card from the unsorted part and insert it at its correct position in the left sorted part.
    // move the cards one place ahead and place the card at its correct position.
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, n);
    cout << "Sorted array : ";
    for(int i : arr) {
        cout << i << " ";
    }

    return 0;
}