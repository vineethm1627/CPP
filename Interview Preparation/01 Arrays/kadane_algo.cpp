#include <iostream>
using namespace std;

void kadane(int arr[], int n) {
    int cur_sum = 0, max_sum = 0;
    for(int i = 0; i < n; i++) {
        cur_sum += arr[i];
        if(cur_sum < 0) {
            cur_sum = 0;
        }
        max_sum = max(cur_sum, max_sum);
    }

    cout << "Max subarray sum : " << max_sum << endl;
}


int main() {
    // used to solve the max subarray problem in O(n) ie. linear time.
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    kadane(arr, n);

    return 0;
}