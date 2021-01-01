/*
    C++ is a backward compatible language which implies that it supports most of the syntax of C language.

    C --> scanf and printf
    C++ --> cin, cout, scanf and printf

    We need to turn off the synchronization between C++ and C standard streams.
        ios_base::sync_with_stdio(false);

    In addition to this, there is a synchronization between cin and cout.
    to use cin, flush cout and vice-versa.
        cin.tie(NULL); // unties input and output stream.

*/
#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fastIO();
    int n;
    cin >> n;

    cout << n << endl;
    return 0;
}