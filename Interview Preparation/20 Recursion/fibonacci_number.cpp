/*
    Find the nth fibonacci number.
    input: n = 5
    output: 5 

    input: n = 6
    output: 8
*/
#include <iostream>
using namespace std;
 
int fib(int n) {
    // base case
    if(n == 0 or n == 1)
        return n;
    
    // recursive call
    return fib(n - 1) + fib(n - 2);
}
 
int main() {
    
    int n;
    cin >> n;

    cout << fib(n) << '\n';
 
    return 0;
}