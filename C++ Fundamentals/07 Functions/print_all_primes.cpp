/*
    given a number n, print all the prime numbers from 1 to n.
*/
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimes(int n) {
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }
}

int main() {

    int n;
    cin >> n;

    printPrimes(n);

    return 0;
}