/*
    SPOJ Problem : https://www.spoj.com/problems/ARRAYSUB/

    Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

    Input
    the number n denoting number of elements in the array then after a new line we have the numbers of the array and then k in a new line

    n < 10^6
    k < 10^5
    1 <= k <= n

    and each element of the array is between 0 and 10^6

    Output
    print the output array

    Example
    Input:
    9
    1 2 3 1 4 5 2 3 6
    3

    Output:
    3 3 4 5 5 5 6
*/
#include <iostream>
#include <deque>
using namespace std;

int main() {
	
	int i, n, k;
	cin >> n;
	
	int arr[n];
	for(i = 0; i < n; i++) 
		cin >> arr[i];
	cin >> k;
	
	// we need to process the first k elements separately
	deque<int> Q(k); // constructor call to initialize deque with size = k
	// the deque will store the indices of the useful array elements.
	
	for(i = 0; i < k; i++) {
		while(!Q.empty() and arr[i] > arr[Q.back()]) {
			Q.pop_back();
		}
		Q.push_back(i);
	}
	// process the remaining elements
	for(i = k; i < n; i++) {
		cout << arr[Q.front()] << " ";
		
		// remove the elements which are not a part of the current window (contraction)
		while(!Q.empty() and Q.front() <= i - k) {
			Q.pop_front();
		}
		// remove useless elements in the window
		while(!Q.empty() and arr[i] >= arr[Q.back()]) {
			Q.pop_back();
		}
		// add the new elements at the end(expansion)
		Q.push_back(i);
	}
	cout << arr[Q.front()] << " ";
	return 0;
}