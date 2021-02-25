/*
    Recursion is a method where solution to a problem depends
    on solutions to smaller instances of the same problem.

    Easiest way to approach a recursive problem.
        1. Figure out the base case
        2. Assume sub-problems can be solved by recursion(automatically)
        3. using the sub-problems write the answer for the current problem.
*/
#include <iostream>
using namespace std;
 
long long int factorial(int n) {
    // base case
    if(n == 0)
        return 1;

    // recursive call
    return n * factorial(n - 1);
}
 
int main() {
    
    int n;
    cin >> n;

    cout << factorial(n) << '\n';
 
    return 0;
}