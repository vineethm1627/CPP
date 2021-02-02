#include <iostream>
using namespace std;
#define ll long long int

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

ll LCM(int *arr, int n) {
    ll result = arr[0];

    for(int i = 1; i < n; i++) {
        result = (arr[i] * result) / gcd(arr[i], result);
    }
    return result;
}

ll LCM(int a, int b, int c) {
    ll result = (a * b) / gcd(a, b);
    result = (c * result) / gcd(c, result);

    return result; 
}

int main() {

    int a, b, c;
    cin >> a >> b >> c;
    cout << LCM(a, b, c) << endl;
    return 0;
}