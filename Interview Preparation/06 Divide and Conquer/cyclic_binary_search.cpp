/*
    Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array. Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

    Hint - Think Binary Search!

    Input Format
    The first line contains N - the size of the array. the next N lines contain the numbers of the array.The next line contains the item to be searched.

    Constraints
    Output Format
    Output the index of number in the array to be searched. Output -1 if the number is not found.

    Sample Input
    5
    4
    5
    1
    2
    3
    2
    Sample Output
    3
    Explanation
    The given rotated array is [4, 5, 1, 2, 3]. The element to be searched is 2 whose index is 3.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int find(int *arr, int n, int key) {
	int start = 0, end = n - 1;

	while(start <= end) {
		int mid = start + (end - start) / 2;
		if(arr[mid] == key) 
			return mid;
		else if(arr[mid] >= arr[start]) {
			// part-1 of the array
			// here we have 2 cases --> left / right of the mid.
			if(key >= arr[start] and key < arr[mid])
				end = mid - 1;
			else 
				start = mid + 1;
		}
		else {
			// part-2 of the array
			if(key > arr[mid] and key <= arr[end])
				start = mid + 1;
			else	
				end = mid - 1;
		}
	}
	return -1; // element not found
}

int main() {
	int n, key;
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> key;

	cout << find(arr, n, key);

	return 0;
}