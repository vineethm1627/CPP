#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> v = {11, 12, 3, 4};
    cout << v[0] << endl;

    // ascending order
    sort(v.begin(), v.end()); // O(nlogn)

    // binary search
    bool present = binary_search(v.begin(), v.end(), 3); // true
    cout << present << endl;
    present = binary_search(v.begin(), v.end(), 100); // false
    cout << present << endl;

    // insert element
    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(123);

    // current array : 3, 4, 11, 12, 100, 100, 100, 100, 123
    // first occurence of 100 using lower_bound
    vector<int>::iterator lb = lower_bound(v.begin(), v.end(), 100); // first element >= 100
    auto ub = upper_bound(v.begin(), v.end(), 100); // first element > 100
    // dereferncing to get the value present at that index.
    cout << *lb << " " << *ub << endl; // 100 123
    // freq of occurence of a val in sorted array = lb - ub of that element
    cout << ub - lb << endl; // 4 times 100 occurs

    // sort in descending order
    sort(v.begin(), v.end(), greater<int>());
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}