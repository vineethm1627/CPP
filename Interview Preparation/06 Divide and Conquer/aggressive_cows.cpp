/*
    SPOK Aggressive Cows : https://www.spoj.com/problems/AGGRCOW/

    Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

    His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
    Input
    t – the number of test cases, then t test cases follows.
    * Line 1: Two space-separated integers: N and C
    * Lines 2..N+1: Line i+1 contains an integer stall location, xi
    Output
    For each test case output one integer: the largest minimum distance.

    Input:
    1
    5 3
    1
    2
    8
    4
    9
    Output:
    3

    Output details:

    FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
    resulting in a minimum distance of 3.

    Approach:

    the logic is based on creating a monotonic search space of min distances.
    the range of the search space will be from 0 to max_difference between the stalls [left_least - right_max]
    sort the array and find the difference between the last and the first value.
    this will be the max limit on the search space.
    
    calculate the mid value and check whether 'c' cows can be placed with a minimum separation >= mid.
    if we get success then we will not look for values less than mid as obviously they will be true too.
    our main motive is to find the maximum separation.
    upon getting success we will try to go towards the increasing separation value ie,. right side direction in our monotonic search space.

*/
#include <iostream>
#include <algorithm>
using namespace std;

bool canPlaceCows(int arr[], int n, int c, int min_sep) {
	int last_cow = arr[0], count = 1;
	
	for(int i = 1; i < n; i++) {
		if(arr[i] - last_cow >= min_sep) {
			count++;
			last_cow = arr[i];
			
			if(count == c) 
				return true;
		}
	}
	return false;
}

int find(int arr[], int n, int c) {
	int start = 0, end = arr[n - 1] - arr[0], ans = 0;
	
	while(start <= end) {
		int mid = start + (end - start) / 2;
		
		bool success = canPlaceCows(arr, n, c, mid);
		if(success) {
			ans = mid;
			start = mid + 1;
		}
		else 
			end = mid - 1;
	}
	return ans;
}

int main() {
	int T, n, c;
	cin >> T;
	
	while(T--) {
		cin >> n >> c;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];
			
		sort(arr, arr + n);
		cout << find(arr, n, c) << endl;
	}
	return 0;
}