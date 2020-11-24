/*
    fibonacci series : 0 1 1 2 3 5 8 .......
    find the nth fibonacci number.
*/
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    int n1 = 0, n2 = 1, n3;
    for(int i = 3; i <= n; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    return n3;
}
int main() {

    int n;
    cin >> n;

    cout << n << "th fibonacci number : " << fibonacci(n);

    return 0;
}
