#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    // internally maintains ascending order
    set<int> s; 
    // insert operation takes O(logn) time making it very powerful
    s.insert(1); // O(logn)
    s.insert(2);
    s.insert(-1);
    s.insert(3);
    s.insert(0);

    for(int i : s) {
        cout << i << " ";
    }
    cout << endl;

    // -1 0 1 2 3
    // finding the index of an element
    auto it = s.find(3);
    if(it != s.end()) {
        cout << *it << " found" << endl;    
    }
    else {
        cout << "element not found" << endl;
    }

    auto lb = s.lower_bound(-1); // iterator to first element of the set >= -1
    auto ub = s.upper_bound(-1); // first element strictly > -1
    cout << *lb << " " << *ub << endl;

    ub = s.upper_bound(3);
    if(ub == s.end()) {
        cout << "upper bound doesn't exist in the array" << endl;
    }    

    s.insert(3); // doesnt matter
    s.insert(3); // repetition of elements is not allowed in sets
    for(int i : s) {
        cout << i << " ";
    }
    cout << endl;
    cout << s.size() << endl;
    
    // erasing an element in O(logn) time
    s.erase(3);
    cout << s.size() << endl;
    
    return 0;
}