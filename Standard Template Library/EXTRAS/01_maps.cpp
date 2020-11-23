#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {

    // The time complexity for searching elements in std::map is O(log n). Even in the worst case, it will be O(log n) because elements are stored internally as Balanced Binary Search tree (BST)
    map<int, int> mii;
    mii[1] = 100;
    mii[2] = -1;
    mii[3] = 200;
    mii[50] = 1;

    cout << mii[50] << endl;
    map<char, int> mci;
    string str = "c++STL";
    for(char c : str) {
        mci[c]++;
    }
    
    for(auto it = mci.begin(); it != mci.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    for(auto it = mii.find(3); it != mii.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    // finding a key in O(logn)
    auto f = mii.find(3);
    cout << f->first << " : " << f->second << endl;
    cout << mii.size() << endl;

    // erasing a key in O(logn)
    mii.erase(3);
    cout << mii.size() << endl;
    return 0;
}