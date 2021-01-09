/*
    count total set bits in all numbers from 1 to n efficiently.
*/
#include <iostream>
using namespace std;

int countSetBits(int n) {
    
    // ignore 0 as all the bits are unset.
    n++;

    int powerOf2 = 2;
    int count = n / 2;

    while(powerOf2 <= n) {
        // total count of pairs of 0s and 1s
        int totalPairs = n / powerOf2;
        // totalPairs/2 --> pairs with 1s only.
        // no. of 1s in each pair = powerOf2
        count += (totalPairs / 2) * powerOf2;

        // if the count of pairs was odd, then add remaining 1s 
        // which could not be grouped together.

        count += (totalPairs & 1) ? (n % powerOf2) : 0;

        // next power of 2
        powerOf2 = powerOf2 << 1;
    }
    return count;
}

int main() {

    int n;
    cin >> n;
    cout << countSetBits(n) << endl;

    return 0;
}