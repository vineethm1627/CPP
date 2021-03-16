/*
    number to english spelling.
    2048 --> two zero four eight
*/
#include <iostream>
using namespace std;

char words[][10] = {"zero", "one", "two", "three", "four", "five",
                    "six", "seven", "eight", "nine"};
 
void printSpelling(int n) {
    // base case
    if(n == 0)
        return;
    
    // recursive calls
    printSpelling(n / 10);
    // extract the last digit
    int digit = n % 10;
    cout << words[digit] << " ";
}
 
int main() {
    
    int n;
    cin >> n;

    printSpelling(n);
 
    return 0;
}