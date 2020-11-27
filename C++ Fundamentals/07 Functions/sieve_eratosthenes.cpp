/*
    most efficient way to print all the prime numbers upto n.
*/
#include <iostream>
#include <cstring>
using namespace std;

void sieveOfEratosthenes(int n) {
    // initially we will mark all the numbers as true indicating they are prime.
    bool prime[n];
    memset(prime, true, sizeof(prime));
    
    for(int p = 2; p * p <= n; p++) {
        if(prime[p] == true) {
            // update all the mulitples of p >= p^2
            for(int i = p * p; i <= n; i += p) {
                prime[i] = false;
            } 
        }
    }
    // now print all the unmarked ones.
    for(int i = 2; i <= n; i++) {
        if(prime[i]) {
            cout << i << " ";
        }
    }
}

int main() {

    int n;
    cin >> n;

    sieveOfEratosthenes(n);

    return 0;
}