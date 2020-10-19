#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// this function returns a pointer to the array.
vector<int> cumulativeSum(int arr[], int n) {
    vector<int> csum;
    csum.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        csum.push_back(csum[i - 1] + arr[i]);
    }
    return csum;
}

// O(n^2) cumulative sum approach
void allSubarrays(int arr[], int n) {
    pair<int, int> ind;
    vector<int> csum = cumulativeSum(arr, n);
    int max_sum = INT_MIN, cur_sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            //Elements of subarray(i, j)
            cur_sum = csum[j] - csum[i] + arr[i];
            
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