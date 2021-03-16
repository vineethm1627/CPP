/*
    Count binary strings of length n, which have no consecutive 1's.

    input: 2
    output: 3
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Solution{
public:
	// #define ll long long
	unsigned long long M = 1e9 + 7;
	ll countStrings(int n) {
	    ll a[n]; // strings of length n, ending with 0
	    ll b[n]; // string of length n, ending with 1
	    a[0] = b[0] = 1;
	    for(int i = 1; i < n; i++) {
	        a[i] = (a[i - 1] + b[i - 1]) % M;
	        b[i] = a[i - 1] % M;
	    }
	    return (a[n -1] + b[n - 1]) % M; 
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}