#include <iostream>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
}

int main() {
    
    fastIO();
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        // buffered output, later on printed at once.
        // cout << "n is -> " << n << '\n';
        // we want to flush the output straight away print on the screen.
        // cout << "n is -> "  << n << '\n';
        // cout << flush;
        // the combined version for above 2 lines
        cout << "n is -> " << n << endl;
        // endl works as cout << '\n << flush
    }

    return 0;
}