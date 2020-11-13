/*
    Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.

    Input Format
    Constraints
    0 < N <= 1000000000

    Output Format
    Sample Input
    63
    Sample Output
    77
    Explanation
    Both input and output are integers
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void print_elem(int elem) {
	cout << elem;
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	while(n) {
		v.push_back(n % 8);
		n = n / 8;
	}
	for_each(v.rbegin(),v.rend(),print_elem);

	return 0;
}