/*
    Convert a binary representation number in to base 10 representation.
    
    Input: 
    13

    Output:
    1101
*/
#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary(int n) {
    int ans = 0, p = 1;
    while(n) {
        int digit = (n & 1);
        ans += p * digit;
        p = p * 10;
        n = n >> 1;
    }
    return ans;
}

int main() {

    int n;
    cin >> n;
    cout << decimalToBinary(n) << endl;
    return 0;
}