#include <iostream>
using namespace std;

// find a^n using exponentiation (bitmasking)
int power_optimized(int a, int n) {
    int ans = 1;
    while(n) {
        int last_bit = (n & 1);
        if(last_bit) 
            ans = ans * a;
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

int main() {

    int a, n;
    cin >> a >> n;

    cout << power_optimized(a, n);
    return 0;
}