#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
    cin >> n;
	cout << "no. of set bits : " << __builtin_popcount(n);
    // __builtin_popcountl(n); // for long datatypes
    // __builtin_popcountll(n); // for long long datatypes

	return 0;
}