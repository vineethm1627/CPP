/*
    Babylonian method for square root
    This method can be derived from Newton Raphson Method.

    Algorithm:
    1 Start with an arbitrary positive start value x (the closer to the 
      root, the better).
    2 Initialize y = 1.
    3. Do following until desired approximation is achieved.
        a) Get the next approximation for root using average of x and y
        b) Set y = n/x
*/
#include <iostream>
#include <iomanip>
using namespace std;

float squareRoot(float n) {
    float x = n, y = 1, epsilon = 0.00001;
    while(x - y > epsilon) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

int main() {

    int n;
    cin >> n;
    cout << setprecision(4) << squareRoot(n);

    return 0;
}
