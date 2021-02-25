/*
    Write a function to multiply 2 numbers using recursion.
*/
#include <iostream>
using namespace std;
 
long multiply(int a, int b) {
    if(b == 1)
        return a;
    
    return a + multiply(a, b - 1);
}
 
int main() {
    int a, b;
    cin >> a >> b;

    cout << multiply(max(a, b), min(a, b)) << '\n';
 
    return 0;
}