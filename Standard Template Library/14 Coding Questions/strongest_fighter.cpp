/*
    There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.

    Input Format
    First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k

    Constraints
    1<=N<=10^7
    1<=k<=N
    1 <= Ai <= 100000

    Output Format
    Space separated integers in a single line denoting strength of strongest fighters in the groups.

    Sample Input
    5
    1 3 1 4 5
    3
    Sample Output
    3 4 5
    Explanation
    First sub-group: 1 3 1 --> Max strength is 3
    Second sub-group: 3 1 4 --> Max strength is 4
    Third sub-group: 1 4 5 --> Max strength is 5
*/
#include <iostream>
#include <deque>
using namespace std;

int main() {

	int n, k;
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	cin >> k;

	deque<int> Q(k); // store the index of the elements
	// process the first k elements
	for(int i = 0; i < k; i++) {
		// remove the useless elements.
		while(!Q.empty() and arr[i] > arr[Q.back()]) {
			Q.pop_back();
		}
		Q.push_back(i);
	}

	// process the remaining solutions
	for(int i = k; i < n; i++) {
		// print the max of the previous window
		cout << arr[Q.front()] << " ";
		// remove the elements going out of the current window
		while(!Q.empty() and Q.front() <= i - k) {
			Q.pop_front();
		}
		// remove the useless elements
		while(!Q.empty() and arr[i] >= arr[Q.back()]) {
			Q.pop_back();
		}
		// add the element
		Q.push_back(i);
	}
	// print the max element of the last window
	cout << arr[Q.front()];

	return 0;
}