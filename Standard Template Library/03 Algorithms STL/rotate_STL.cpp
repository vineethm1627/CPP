#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    vector<int> v{1, 2, 3, 4, 5};

    // start, middle, end
    // rotate about the middle.
    // ie. middle elements onwards bring it forward.
    rotate(v.begin(), v.begin() + 3, v.end());

    cout << "After rotation : ";
    // output : 4 5 1 2 3
    for(int i : v) {
        cout << i << " ";
    }

    cout << endl << "After next_permutation : ";
    // next permutation lexographically.
    next_permutation(v.begin(), v.end());

    for(int i : v) {
        cout << i << " ";
    }

    return 0;
}