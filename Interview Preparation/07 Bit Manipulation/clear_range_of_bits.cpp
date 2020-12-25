#include <iostream>
using namespace std;

int clearLastIBits(int n, int i) {
    // -1 = ~0 = 11111111...111
    int mask = (-1 << i);
    return n & mask;
}

int clearRangeItoJ(int n, int i, int j) {
    // -1 = ~0 = 11111111...111
    int a = (-1 << (j + 1));
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int main() {
    int n, i, j;
    cin >> n >> i >> j;
    // i = 2 means indices 0,1,2 from RHS ie clear last 2 bits [position i+1 to 0]
    cout << clearLastIBits(n, i) << endl;
    cout << clearRangeItoJ(n, i, j);
    return 0;
}