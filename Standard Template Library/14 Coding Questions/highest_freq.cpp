/*
    Given an array find the number which comes with maximum frequency. It must work in O(n) time complexity.

    Input Format
    Enter the size of the array N and add N more numbers and store in an array

    Constraints
    1 <= N <= 10^7
    -109 <= A[i] <= 109

    Output Format
    Display the number with the maximum frequency.

    Sample Input
    5
    1 2 2 2 3
    Sample Output
    2
    Explanation
    2 has the highest frequency in the array i.e. 3.
*/
#include<iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;

	int *arr = new int[n];
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]]++;
	}
	int e = 0, max = m[arr[0]];
	for(int i = 1; i < n; i++) {
		if(m[arr[i]] > max) {
			max = m[arr[i]];
			e = arr[i];
		}
	}
	delete [] arr;
	cout << e << endl;
	return 0;
}