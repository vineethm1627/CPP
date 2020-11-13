/*
    Take N (number in binary format). Write a function that converts it to decimal format and Print the value returned.

    Input Format
    Constraints
    0 < N <= 1000000000

    Output Format
    Sample Input
    101010
    Sample Output
    42
    Explanation
    For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int i = 0, res = 0;
	while(n) {
		res = res + pow(2, i) * (n % 10);
		i++;
		n /= 10;  
	}
	cout << res << endl;
	return 0;
}