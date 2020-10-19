#include <iostream>
#include <climits>
using namespace std;

typedef pair<int, pair<int, int>> pp;

// this time we will return the subarray too along with the max sum.

// utility function to find max of 3 numbers
pp max(pp p1, pp p2, pp p3) {
    if(p1.first > p2. first and p1.first > p3.first) {
        return p1;
    }
    else if(p2.first > p1.first and p2.first > p3.first) {
        return p2;
    }
    else {
        return p3;
    }
}
// crossing sum through mid.
pp crossingsum(int arr[], int start, int mid, int end) {
    // elements to the left of mid, start the sum from mid towards the left.
    pp p;
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = mid; i >= start; i--) {
        sum += arr[i];
        if(sum > left_sum) {
            left_sum = sum;
            p.second.first = i;
        } 
    }

    // elements to the right of mid, start the sum from mid + 1 towards the right.
    sum = 0;
    int right_sum = INT_MIN;
    for(int i = mid + 1; i <= end; i++) {
        sum += arr[i];
        if(sum > right_sum) {
            right_sum = sum;
            p.second.second = i;
        }
    }
    p.first = left_sum + right_sum;
    return p;
     
}
pp subarraysumDivandConquer(int arr[], int start, int end) {
    // base case, only 1 element is there.
    if(start == end) {
        pp base;
        base.first = arr[start];
        base.second.first = start;
        base.second.second = end;
        return base;
    }
    
    pp p1, p2, p3;
    // p1.first --> sum
    // p1.second.first --> left index of the required subarray
    // p1.second.second --> right index of the required subarray
    int mid = (start + end) / 2;
    p1 = subarraysumDivandConquer(arr, start, mid);
    p2 = subarraysumDivandConquer(arr, mid + 1, end);
    p3 = crossingsum(arr, start, mid, end);

    return(max(p1, p2, p3)); 
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

    pp p = subarraysumDivandConquer(arr, 0, n - 1);
    cout << "Max sum : " << p.first << endl;
    cout << "Subarray : ";
    for(int i = p.second.first; i <= p.second.second; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}