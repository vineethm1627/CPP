/*
    Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".

    Input Format
    Constraints
    2 < N <= 1000000000

    Output Format
    Sample Input
    3
    Sample Output
    Prime
    Explanation
    The output is case specific
*/
#include <iostream>
#include <cmath>
using namespace std;

void isPrime(int n) {
	bool flag = true;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			flag = false;
			break;
		}
	}
	if(flag){
		cout << "Prime";
	}
	else { 
		cout << "Not Prime";
	}
}

int main() {
	int n;
	cin >> n; 
	isPrime(n);

	return 0;
}