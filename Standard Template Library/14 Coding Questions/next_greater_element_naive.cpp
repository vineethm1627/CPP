/*
    We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.

    Input Format
    First line contains the length of the array n. Second line contains the n space separated integers.

    Constraints
    1 <= n <= 10^6
    -10^8 <= Ai <= 10^8 , 0<= i< n

    Output Format
    Print n space separated integers each representing the next greater element.

    Sample Input
    3
    1 2 3
    Sample Output
    2 3 -1
    Explanation
    Next greater element for 1 is 2,
    for 2 is 3 but not present for 3 therefore -1

Code Editor
*/
#include <iostream>
using namespace std;

void preintNGE(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		int next = -1;
		for(int j = i + 1; j < n + i; j++) {
			if(arr[j % n] > arr[i]) {
				next = 1;
				cout << arr[j%n] << " ";
				break;
			}
		}
		if(next == -1)
			cout << -1 << " ";
	}
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	preintNGE(arr, n);

	return 0;
}