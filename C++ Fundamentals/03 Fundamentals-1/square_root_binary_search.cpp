/*
    using binary Search
    given a number n, find its square root
    
    this method works well, but gives a close approximation to even perfectn squares
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    double start = 0, end = n, ans = 0;
    double epsilon = pow(10, -p);
    //cout << epsilon << endl;

    while(fabs(ans * ans - n) > epsilon) {
        ans = start + (end - start) / 2;
        if(ans * ans >= n) {
            end = ans;
        }
        else {
            start = ans;
        }
    }
    
    cout << ans;

    return 0;
}