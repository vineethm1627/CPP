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
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue< int, vector<int> > maxHeap;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(maxHeap.size() < k)
                    maxHeap.push(matrix[i][j]);
                else {
                    if(matrix[i][j] < maxHeap.top()) {
                        maxHeap.pop();
                        maxHeap.push(matrix[i][j]);
                    }
                }
            }
        }
        return maxHeap.top();
    }
};