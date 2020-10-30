#include <iostream>
#include <vector>
using namespace std;

void allSubArrays(vector<int> arr, int start, int end) {
    if(end == arr.size()) {
        return;
    }
    else if(start > end) {
        allSubArrays(arr, 0, end + 1);
    }
    else {
        for(int i = start; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        allSubArrays(arr, start + 1, end);
    }
    return;
}

int main() {
    // generate all possible subarrays of the given array using recursion. O(n^2)
    // the traditional method of nested loops takes O(n^3)
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    allSubArrays(arr, 0, 0);

    return 0;
}