#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int key) {
    int start = 0, end = arr.size() - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] > key) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return arr.size(); // if the element is absent.
}

int main() {
    // used when the array is already sorted.
    int n, key, x;
    vector<int> arr;

    cout << "Enter the size of the array : ";
    cin >> n;

    cout << "Enter the elements of the array : \n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    cout << "Enter the key to be searched : ";
    cin >> key;

    int res = binarySearch(arr, key);
    if(res == arr.size()) {
        cout << "Element not found";
    }
    else {
        cout << "Element found at index : " << res << endl;
    }

    return 0;
}