#include <bits/stdc++.h>
using namespace std;

int main() {

    // set uses self-balancing BST to store the values.
    // hence we obtain sorted values in ascending order.
    set<int> s{2, 3, 1, 5, 4};
    
    // unordered_set uses hashing to store the values
    unordered_set<int> us(s.begin(), s.end());

    // sorted order
    for(int x : s) {
        cout << x << " ";
    }
    cout << endl;
    // random order
    for(int x : us) {
        cout << x << " ";
    }
    return 0;
}