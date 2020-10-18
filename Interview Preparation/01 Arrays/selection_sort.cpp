#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> arr) {
    int n = arr.size();
    // when we run the loop n - 1 times, the last element is by default at its correct position.
    for(int i = 0; i < n - 1; i++) {
        // find out the index of the smallest element in the unsorted part.
        int min_index = i;
        for(int j = i; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
    return arr;
}

int main() {
    /* at each standing find the smallest element ahead
    and swap it at the current position.

    has two parts :
     - left part : sorted
     - right part : unsorted wherein we find the smallest element.
    */
    int x, n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> arr;
    cout << endl << "Enter the elements of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    arr = selectionSort(arr);
    cout << "Sorted array : ";
    for(int i : arr) {
        cout << i << " ";
    }

    return 0;
}