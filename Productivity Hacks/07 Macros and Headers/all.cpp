#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

void print(vector<int> &v) {
    for(int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    vector<int> v {3, 2, 1, 4, 5};
    print(v);

    reverse(all(v));
    print(v);

    sort(v.begin(), v.end());
    cout << "present: " << binary_search(all(v), 1) << endl;
    cout << "lb: " << lower_bound(all(v), 1) - v.begin()<< endl;
    cout << "ub: " << upper_bound(all(v), 1) - v.begin() << endl;

    return 0;
}