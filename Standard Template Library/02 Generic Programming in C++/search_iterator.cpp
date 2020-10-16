#include <iostream>
#include <vector>
#include <list>
using namespace std;

// return type is ForwardIterator
template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key) {
    while(start != end) {
        // dereferencing.
        if(*start == key) {
            return start; //start is the index
        }
        start++;
    }
    // range is 0 to n - 1, so returning n means element not found.
    return end;
}

int main() {
    
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);
    
    // v.begin() is a ForwardIterator of type : "list<int>::iterator"
    auto it = search(v.begin(), v.end(), 5);
        // cout << it; will lead to error as iterators are defined not to hold any value.
        // cout << it - v.begin(); solves this purpose.
    if(it == v.end()) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element : " << *it << " found at index : " << it - v.begin() << endl;
    }

    return 0;
}