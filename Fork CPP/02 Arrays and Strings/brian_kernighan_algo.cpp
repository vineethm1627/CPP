/*
    Write an efficient program to count number of 1s in binary representation of an integer.

    Input : n = 6
    Output : 2
    Binary representation of 6 is 110 and has 2 set bits

    Note : 
        >> (righshift is divide)
        << (leftshift is multiply)

    Brian Kernighan's Algorithm : for counting the set bits
    Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit.
    for example :
        10 in binary is 00001010
        9 in binary is  00001001
        8 in binary is  00001000
        7 in binary is  00000111

    So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit. 
    If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
    The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer.
*/

#include <iostream>
using namespace std;

// here num is the decimal integer
unsigned int countSetBits(unsigned int num) {
    int count = 0;
    while(num) {
        num = num & (num - 1);
        count++;
    }
    return count;
}

int main() {
    cout << "No of set bits in 10(decimal) : " << countSetBits(10) << endl;
    cout << "No of set bits in 8(decimal) : " << countSetBits(8);
    return 0;
}