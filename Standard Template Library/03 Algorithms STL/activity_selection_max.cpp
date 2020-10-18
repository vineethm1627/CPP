/*
You are given n activities (from 0 to n-1) with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Input Format
The first line consists of an integer T, the number of test cases. For each test case, the first line consists of an integer N, the number of activities. Then the next N lines contain two integers m and n, the start and end time of each activity.

Constraints
1<=t<=50
1<=n<=10000
1<=A[i]<=100

Output Format
For each test case find the maximum number of activities that you can do.

Sample Input
1 
3
10 20
12 15
20 30

Sample Output
2

Sample Input
1 
5
3 4
1 2
5 6
3 8
2 3

Sample Output
4

*/

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return (p1.second < p2.second); // sort in ascending order wrt finishing time.
}

int main() {

	int t, n;
	cin >> t;

	while(t-- > 0) {
		int res = 1;
		cin >> n;
		pair<int, int> arr[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr, arr + n, compare);
		
		int st = arr[0].second; // finishing time of the shortest activity.
		for(int i = 0; i < n; i++) {
			if(arr[i].first >= st) {
				res++;
				st = arr[i].second;
			}
		}

		cout << res << endl;

	} 
	return 0;
}