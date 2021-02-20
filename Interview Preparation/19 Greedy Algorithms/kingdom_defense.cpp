/*
    SPOJ Problem: https://www.spoj.com/problems/DEFKIN/
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    int w, h, n;
    cin >> t;

    int x[100000], y[100000];
    while(t--) {
        cin >> w >> h >> n;

        // when there are no towers
        if(n == 0) {
            cout << w*h << '\n';
            continue;
        }

        for(int i = 0; i < n; i++) 
            cin >> x[i] >> y[i];
        
        sort(x, x + n);
        sort(y, y + n);

        // grid start to the first tower
        int delta_x = x[0] - 1, delta_y = y[0] - 1;
        // difference between consecutive towers
        for(int i = 1; i < n; i++) {
            delta_x = max(delta_x, x[i] - x[i - 1] - 1);
            delta_y = max(delta_y, y[i] - y[i - 1] - 1);
        }
        // last tower to grid end
        delta_x = max(delta_x, w - x[n - 1]);
        delta_y = max(delta_y, h - y[n - 1]);

        cout << delta_x * delta_y << '\n';
    }
    return 0;
}
