#include <iostream>
using namespace std;

void allSubarrays(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    // given an array, generate all the subarrays.
    // subarrays are continuos ie. no skipping is allowed.
    int n, res = 0;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "All subarrays of the given array are : " << endl;
    allSubarrays(arr, n);
    
    return 0;
}