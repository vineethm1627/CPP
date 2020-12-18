/* 
    Maximum sum sub-mtrix in a row and column wise sorted matrix.

    input : 
    -5 -4 -1
    -3  2  4
     2  5  8

    Construct a suffix sum matrix.
    it is constructed from bottom right to top left.
    The max value in this suffix matrix will be the max submatrix sum.

    Approach : 
        The element at the bottom right is the max element in the array.
        It will always be included in the max sum.
        By constructing suffix sum we can find all the subarrays
        enclosing the bottom right value.
*/
#include <iostream>
#include <climits>
using namespace std;

int maxSumSorted(int *arr[], int r, int c) {
    // col wise addition
    for(int i = r - 1; i >= 0; i--) {
        for(int j = c - 2; j >= 0; j--)
            arr[i][j] += arr[i][j + 1];
    }

    // row wise addition
    for(int i = c - 1; i >= 0; i--) {
        for(int j = r - 2; j >= 0; j--)
            arr[j][i] += arr[j + 1][i];
    }

    int result = INT_MIN;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            result = max(result, arr[i][j]);
    }
    return result;
}

int main() {

    int r, c;
    cin >> r >> c;

    int *arr[r];
    for(int i = 0; i < r; i++) 
        arr[i] = new int[c];
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            cin >> arr[i][j];
    }

    cout << maxSumSorted(arr, r, c) << endl;

    return 0;
}

    