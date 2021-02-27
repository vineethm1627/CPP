/*
    Calculate the power of a number using recursion where base and the exponent is given.
*/
#include <iostream>
using namespace std;
 
// find a ^ n
long long int power(int a, int n) {
    // base case
    if(n == 0)
        return 1;
    
    // recursive calls
    return a * power(a, n - 1);
} 

// O(logn)
long long int fastPower(int a, int n) {
    // base case
    if(n == 0)
        return 1;
    
    // recursive calls
    int result = fastPower(a, n / 2);
    // odd
    if(n & 1)
        return a * result * result;
    else    
        return result * result;
} 

long long int powerBitMask(int a, int n) {
    long long int result = 1;
    while(n) {
        int last_bit = n & 1;
        if(last_bit)
            result *= a;
        a *= a;
        n = n >> 1;
    }
    return result;
}


int main() {
    
    int a, n;
    cin >> a >> n;

    cout << power(a, n) << '\n';
    cout << fastPower(a, n) << '\n';
    cout << powerBitMask(a, n) << '\n';
 
    return 0;
}