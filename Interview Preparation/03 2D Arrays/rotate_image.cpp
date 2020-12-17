/*
    Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

    Input Format
    First line contains a single integer N. Next N lines contain N space separated integers.

    Constraints
    N < 1000

    Output Format
    Print N lines with N space separated integers of the rotated array.

    Sample Input
    4
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    Sample Output
    4 8 12 16 
    3 7 11 15 
    2 6 10 14 
    1 5 9 13 
    Explanation
    Rotate the array 90 degrees anticlockwise.
*/
#include <iostream>
#include <algorithm>
using namespace std;

void rotateImage(int *arr[], int n) {
	// reverse each row
	for(int i = 0; i < n; i++) {
		// int left = 0, right = n - 1;
		// while(left < right)
		// 	swap(arr[i][left++], arr[i][right--]);

		// use reverse STL
        // arr[i] is the row pointer pointing to the address of that row.
		reverse(arr[i], arr[i] + n);
	}

	// take transpose of the image
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			// swap for only lower triangular part.
			// else double swap will result the same as original image.
			if(i < j) {
				swap(arr[i][j], arr[j][i]);
			}
		}
			
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


}

int main() {
	// rotate 90 degrees in anti clockwise direction
	int n;
	cin >> n;

	int *arr[n];
	for(int i = 0; i < n; i++)
		arr[i] = new int[n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) 
			cin >> arr[i][j];
	}

	rotateImage(arr, n);
	return 0;
}