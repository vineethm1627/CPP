/*
    Calculate the power of a number using recursion where base and the exponent is given.
*/
#include <iostream>
using namespace std;
 
// a ^ n
long long int power(int a, int n) {
    // base case
    if(n == 0)
        return 1;
    
    // recursive calls
    return a * power(a, n - 1);
} 
 
int main() {
    
    int a, n;
    cin >> a >> n;

    cout << power(a, n) << '\n';
 
    return 0;
}