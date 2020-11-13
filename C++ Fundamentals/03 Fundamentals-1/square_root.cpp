/*
    naive approach : Bruteforce
    given a number n, find its square root
    if n = 10, square root = 3.162
    3 --> integer part
    .162 --> precision part
    
    finding integer is easy such that square of n is less than equal to n.
    do +1
    finding precision's first digit
    do +0.1
    3.0, 3.1, 3.2 ..... 3.9 keep checking the square is less than equal to n.
    once you get > go one step back.

    finding precision's second digit
    do +0.01
*/

#include <iostream>
using namespace std;

int main() {

    float ans = 0, increment = 1;
    int n, p; 
    cin >> n >> p;
    // our task is to find out square root of n upto precision 'p'
    // finding out the integer part
    for(int i = 0; i <= p; i++) {
        while(ans * ans <= n) {
            ans += increment;
        }
        // take one step back
        ans -= increment;
        increment /= 10;
    }
    
    cout << "Square root of " << n << " : " << ans << endl;

    return 0;
}