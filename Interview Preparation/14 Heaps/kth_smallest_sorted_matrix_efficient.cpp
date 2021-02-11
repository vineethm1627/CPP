/*
    Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
    Note that it is the kth smallest element in the sorted order, not the kth distinct element.
    Example:
    matrix = [
    [ 1,  5,  9],
    [10, 11, 13],
    [12, 13, 15]
    ],
    k = 8,
    return 13.
*/
#include <iostream>
#include <vector>
using namespace std;
 
int kthSmallestEfficient(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    // create a monotonic search space
    int low = matrix[0][0], high = matrix[n - 1][n - 1];

    while(low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        // use staircase search to find the count of elements <= mid
        int row = 0, col = n - 1;
        while(row < n and col >= 0) {
            if(matrix[row][col] <= mid) {
                count += col + 1;
                row++;
            }
            else 
                col--;
        }

        if(count < k)
            low = mid + 1;
        else
            high = mid; // not mid - 1 as duplicates are allowed.
    }
    return low;
}
 
int main() {
    
    cout << "enter the value of n and k: ";
    int n, k;
    cin >> n >> k;
    cout << "enter the matrix elements: " << endl; 

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++)
            cin >> matrix[i][j];
    }

    cout << kthSmallestEfficient(matrix, k);
 
    return 0;
}