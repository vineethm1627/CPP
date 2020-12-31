/*
Algorithm
Make a priority_queue [minHeap] where each node stores three values - the element itself , its row no. and its col no.
Push the first elements of all the rows into this minHeap with their corresponding row and column info.
One by one , take nodes out of this priority queue and insert their values into the final sorted array.
Also push the next element of the same row and next column using the other information into the minHeap.
Repeat this process until the minHeap becomes empty.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// pair to store element, row_num, col_num
#define ppi pair<int, pair<int, int>> 

vector<int> mergeKSortedArrays(vector<vector<int>> &arr) {
    int k = arr.size();
    int n = arr[0].size();
    vector<int> merged;

    // create a minHeap
    priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;

    // push the first ie. smallest element of all the k arrays
    for(int i = 0; i < k; i++) 
        minHeap.push({arr[i][0], {i, 0}});
    
    while(!minHeap.empty()) {
        // pop the smallest element and insert row, col + 1 of that element if col + 1 < n or col < n - 1
        ppi temp = minHeap.top();
        minHeap.pop();
        merged.push_back(temp.first);
        int r = temp.second.first;
        int c = temp.second.second;
        if(c + 1 < n) 
            minHeap.push({arr[r][c + 1], {r, c + 1}});
    }
    return merged;
}

int main() {

    int k, n;
    cin >> k >> n;

    // int arr[n][k];
    vector< vector<int> > arr(k, vector<int>(n));
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) 
            cin >> arr[i][j];
    }

    vector<int> merged = mergeKSortedArrays(arr);

    // print the merged array
    for(int x : merged) 
        cout << x << " ";

    return 0;
}