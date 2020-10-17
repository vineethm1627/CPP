#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int arr[] = {1, 10, 11, 9, 100, 11};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout << "Enter the key value to be searched : ";
    int key;
    cin >> key;
    auto it = find(arr, arr + n, key);
    
    if(it == arr + n) {
        cout << "Element is not present" << endl;
    }
    else {
        //int index = it - arr;  address - base address
        cout << "Element : " << *it << " found at index : " << it - arr << endl;
    }
    
    return 0;
}