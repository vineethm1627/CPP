/*
    count the set bits in a number.
    count the number of 1's in the binary representation of the number.

    Example

    Input:
    13

    Output:
    3

    Explanation:
    13 = 1101
    number of set bits = 1+1+1 = 3
*/
#include <iostream>
using namespace std;

// First method
int countSetBits(int n) {
    int count = 0;
    while(n) {
        count += (n & 1);
        n = n >> 1;
    }
    return count;
}

// Second Method (efficient) : Brian Kernighans Algo
int countSetBitsFast(int n) {
    int count = 0;
    while(n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {

    int n;
    cin >> n;
    // first method O(K) : K = toal number of bits
    cout << countSetBits(n) << endl;
    // second method O(logn)
    cout << countSetBitsFast(n) << endl;
    // third method : inbuilt function in c++
    cout << __builtin_popcount(n) << endl;

    return 0;
}