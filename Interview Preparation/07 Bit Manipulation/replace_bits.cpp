/*
    Replace bit in N by M.
    You are given 2, 32-bit numbers, N and M, and 2 bit positions i and j from the right.
    Write a method to set all the bits between i and j in N equal to the bits in M such that
    M becomes a substring of N located at i and starting from j.

    Example

    Input:
    N = 10000000000
    M = 10101, i = 2, j = 6
    
    Output:
    10001010100
*/
#include <iostream>
using namespace std;

int clearRange(int n, int i, int j) {
    int a = -1 << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int replaceBits(int n, int m, int i, int j) {
    int n_cleared = clearRange(n, i, j);
    return n_cleared | (m << i);
}

int main() {

    int n = 15, m = 2, i = 1, j = 3;
    cout << replaceBits(n, m, i, j);

    return 0;
}