#include <iostream>
#include <algorithm>
using namespace std;

// defining a comparator function
bool compare(int a, int b) {
    return a > b; // sorting the array in reverse order.
}

int main() {

    int n, key;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the elements of the array !";

    int arr[1000];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    // sort the container
    // sending a function as a parameter.
    // sorts the array in descending order.
    sort(arr, arr + n, compare);

    // sorts the array in ascending order (by default)
    // sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}