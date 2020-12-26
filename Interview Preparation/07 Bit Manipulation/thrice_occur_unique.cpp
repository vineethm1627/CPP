/*
    We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. 
    Find the unique number. Only use - bitwise operators, and no extra space.

    Input Format
    First line contains the number n. Second line contains n space separated number.

    Constraints
    N < 10^5

    Output Format
    Output a single line containing the unique number

    Sample Input
    7
    1 1 1 2 2 2 3
    Sample Output
    3
    Explanation
    3 is present only once
*/
#include <iostream>
using namespace std;

int main() {
	int count[64] = {0};
	int n, num;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> num;
		// update the count array by extracting bits
		int j = 0;
		while(num) {
			int last_bit = (num & 1);
			count[j] += last_bit;
			j++;
			num = num >> 1;
		}	
	}
	// iterate over the count array and take modulus 3.
	// form the answer by converting 0s and 1s into decimal number
	int p = 1, ans = 0;
	for(int i = 0; i < 64; i++) {
		count[i] %= 3;
		ans += p * count[i];
		p = p << 1; // p *= 2;
	}
	cout << ans << endl;
	return 0;
}