#include <iostream>
using namespace std;

// the indexing starts from 0 and from right side.
// 123 --> 3 is index 0. 

bool isOdd(int n) {
    return (n & 1);
}

int getBit(int n, int i) {
    int mask = (1 << i);
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;
}

int setBit(int n, int i) {
    int mask = (1 << i);
    int result = n | mask;
    return result;
}

int clearBit(int n, int i) {
    int mask = (1 << i);
    int result = n & ~mask;
    return result;
}

int updateBit(int n, int i, int value) {
    int mask = (value << i);
    int cleared_n = clearBit(n, i);
    int result =  cleared_n | (value << i);
    return result;
}

int main() {
    int n;
    cin >> n;

    cout << "is Odd : " << isOdd(n) << endl; 
    cout << "get 2nd bit : " << getBit(n, 2) << endl;
    cout << "set 1st bit : " << setBit(n ,1) << endl;
    cout << "update 1st bit with value 1 : " << updateBit(n, 1, 1) << endl;
    return 0;
}