#include <iostream>
#include <climits>
using namespace std;

// O(n^3) naive approach
void allSubarrays(int arr[], int n) {
    pair<int, int> ind;
    int max_sum = INT_MIN, cur_sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cur_sum = 0;
            //Elements of subarray(i, j)
            for(int k = i; k <= j; k++) {
                cur_sum += arr[k];
            }
            if(cur_sum > max_sum) {
                max_sum = cur_sum;
                ind = make_pair(i, j);
            }
        }
    }
    cout << "Max sum : " << max_sum << endl;
    cout << "Subarray : ";
    for(int i = ind.first; i <= ind.second; i++) {
        cout << arr[i] << " ";
    }
    
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
    allSubarrays(arr, n);
    
    return 0;
}