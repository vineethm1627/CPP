#include <iostream>
#include <list>
using namespace std;

// custom comparator class
bool comparator(int a, int b) {
    return a < b;
}

// list::merge() merges two sorted lists into one.
int main() {

    list<int> l1 = {10, 20, 40};
    list<int> l2 = {30, 40, 50};

    // merge sort uses two pointers to merge two lists into one.
    l2.merge(l1, comparator);
    for(auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << " ";
    }
    
    return 0;
}