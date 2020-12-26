/*
    We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. 
    Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

    Input Format
    First line contains the number n. Second line contains n space separated number.

    Constraints
    n < 10^5

    Output Format
    Output a single line containing the unique numbers separated by space

    Sample Input
    4
    3 1 2 1
    Sample Output
    2 3
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	int result = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		result = result ^ arr[i]; 
	}
	// result = num1 ^ num2;
	int temp = result;
	int pos = 0;
	while((temp & 1) == 0){
		temp = temp >> 1;
		pos++;
	}
	// now the first set bit in xor result is at position 'pos'
	int mask = (1 << pos);
	// find numbers which contain set bit at position at pos
	int num1 = 0;
	for(int i = 0; i < n; i++) {
		if((arr[i] & mask) > 0)
			num1 = num1 ^ arr[i];
	}
	int num2 = result ^ num1;
	cout << min(num1, num2) << " " << max(num1, num2) << endl;

	return 0;
}