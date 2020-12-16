/*
    nth fibonacci number using DP.
*/
#include <iostream>
#include <cstring>
using namespace std;

int fibonacci_var(int n) {
    int f1 = 0, f2 = 1, f3;
    if(n <= 1) 
        return n;
    for(int i = 2; i <= n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int fibonacci_arr(int n) {
    int *fib = new int[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {

    int n;
    cin >> n;

    cout << fibonacci_arr(n) << endl;
    cout << fibonacci_var(n) << endl;
    return 0;
}
