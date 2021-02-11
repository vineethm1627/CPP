/*
    Given K sorted arrays each with N elements merge them and output the sorted array

    Input Format
    First line contains 2 space separated integers K and N.
    Next lines contain K*N space separated integers

    Constraints
    Elements of array <= |10^15|
    N <= 10^5
    K <= 10

    Output Format
    Single line consisting of space separated numbers

    Sample Input
    3 4
    1 3 5 7 2 4 6 8 0 9 10 11
    Sample Output
    0 1 2 3 4 5 6 7 8 9 10 11
*/
#include <iostream>
#include <queue>
using namespace std;

#define ppi pair<int, pair<int, int>>

void mergeKSortedArrays(int **arr, int k, int n) {
	priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;

	// push the first ie. the smallest element of all the k arrays
	for(int i = 0; i < k; i++)
		minHeap.push({arr[i][0], {i, 0}});
	
	while(!minHeap.empty()) {
		// pop the smallest element and insert next element of that array if it exists
		ppi temp = minHeap.top();
		minHeap.pop();

		cout << temp.first << " ";
		int r = temp.second.first;
		int c = temp.second.second;

		if(c < n - 1)
			minHeap.push({arr[r][c + 1], {r, c + 1}});
	}
}

int main() {

	int k, n;
	cin >> k >> n;

	int **arr = new int*[k];
	for(int i = 0; i < k; i++)
		arr[i] = new int[n];
	
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	mergeKSortedArrays(arr, k, n);

	return 0;
}