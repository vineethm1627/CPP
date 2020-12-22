// efficient way to search in sorted arrays.
#include <iostream>
using namespace std;

int binary_search(int *arr, int n, int key) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == key) 
            return mid;
        else if(key > arr[mid])
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}

int main() {

    int n, e;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    cin >> e;
    cout << binary_search(arr, n, e);

    return 0;
}