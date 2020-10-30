/*
    Write an efficient program to count number of 1s in binary representation of an integer.

    Input : n = 6
    Output : 2
    Binary representation of 6 is 110 and has 2 set bits

    Note : 
        >> (righshift is divide)
        << (leftshift is multiply)
*/
#include <iostream>
using namespace std;

// here num is the decimal integer
unsigned int countSetBits(unsigned int num) {
    int count = 0;
    while(num) {
        count += num & 1;  // bitwise and with the last bit will be 1 if the last bit is 1 else 0.
        num = num >> 1; // rightshift divides the number by 2
    }
    return count;
}

int main() {
    cout << "No of set bits in 10(decimal) : " << countSetBits(10) << endl;
    cout << "No of set bits in 8(decimal) : " << countSetBits(8);
    return 0;
}