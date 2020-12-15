#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()

int main() {
    vector<int> v{1, 4, 5, 6, 7, 7, 3, 2, 2, 4, 5, 10};
    set<int> s(all(v));
    vector<int> v1(all(s));
    for(int i : v1) {
        cout << i << " ";
    }
    return 0;
}
