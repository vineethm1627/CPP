#include <iostream>
#include <climits>
using namespace std;

// utility function to find max of 3 numbers
int max(int a, int b, int c) {
    return max(max(a, b), c);
}

// crossing sum through mid.
int crossingsum(int arr[], int start, int mid, int end) {
    // elements to the left of mid, start the sum from mid towards the left.
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = mid; i >= start; i--) {
        sum += arr[i];
        if(sum > left_sum) {
            left_sum = sum;
        } 
    }

    // elements to the right of mid, start the sum from mid + 1 towards the right.
    sum = 0;
    int right_sum = INT_MIN;
    for(int i = mid + 1; i <= end; i++) {
        sum += arr[i];
        if(sum > right_sum) {
            right_sum = sum;
        }
    }
    return max(left_sum + right_sum, left_sum, right_sum);
}

int subarraysumDivandConquer(int arr[], int start, int end) {
    // base case, only 1 element is there.
    if(start == end) {
        return arr[start];
    }

    // find the mid point.
    int mid = (start + end) / 2;

    return max(
        subarraysumDivandConquer(arr, start, mid),
        subarraysumDivandConquer(arr, mid + 1, end),
        crossingsum(arr, start, mid, end)
    );
}

int main() {
    // given an array, find a subarray which has the maximum sum.
    // note : The subarrays are continuous.
    // if all the elements are positive, then the subarray would be the entire array itself.
    // the problem gets interesting when some negative elements are there in between.
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "All subarrays of the given array : \n";
    int res = subarraysumDivandConquer(arr, 0, n - 1);
    cout << "Max sum : " << res << endl;
    return 0;
}