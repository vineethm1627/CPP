/*
    given a row-wise sorted matric, we need to find the median of the matrix. Assume r*c is always odd.

    One approach would be to store all the values in an array and sort it.

    The element at index (n/2) is the median of the given matrix.

    Since the matrix is row-wise sorted, we can make use of binary search algorithm.
    For a number to be a median there should be exactly n/2 numbers which are less than it.

    For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, 
    we get the count of numbers less than that by using upper_bound() in each row of the matrix, if it is less than
    the required count, the median must be greater than the selected number, else the median must be less than or equal
    to the selected number. 
*/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int medianMatrix(int **arr, int r, int c) {
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < r; i++) {
        // finding the min element in the first column
        if(arr[i][0] < min) 
            min = arr[i][0];
        
        // finding the max element in the last column
        if(arr[i][c - 1] > max) 
            max = arr[i][c - 1];
    }

    int req_count = (r * c + 1) / 2;

    while(min < max) {
        int mid = min + (max - min) / 2;
        int count = 0;

        // count of elements smaller than int
        for(int i = 0; i < r; i++)
            count += upper_bound(arr[i], arr[i] + c, mid) - arr[i];

        if(count < req_count)
            min = mid + 1;
        else 
            max = mid;
    }
    return min;
}

int main() {

    int r, c;
    cin >> r >> c;

    int **arr = new int*[r];
    for(int i = 0; i < r; i++) 
        arr[i] = new int[c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            cin >> arr[i][j];
    }

    cout << medianMatrix(arr, r, c);

    return 0;
}