#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    list<string> l2{"apple", "guava", "mango","guava", "banana"};

    l2.push_back("pineapple");
    l2.sort();
    l2.push_front("grapes");

    //iterate over the list
    for(auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // removes all the occurences of the word.
    l2.remove("guava");
    cout << l2.size() << endl;
    for(auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // erase some element at a particular index.
    auto it = l2.begin();
    it++;
    it++;
    // indexing is not allowed in linked list. 
    // same as l2.begin() = 2 ie 3rd position or index = 2.
    l2.erase(it); // removes the element a index = 2
    for(auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // insert after the first element ie at index = 1
    it = l2.begin();
    it++; // advance(it, 1);
    l2.insert(it, "pomegranate");

    for(string s : l2) {
        cout << s << " ";
    }
    cout << endl;


    return 0;
}