#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    // init
    list<int> l1{1, 2, 3, 10, 8, 5};
    list<string> l2{"apple", "guava", "mango", "banana"};

    l2.push_back("pineapple");
    l2.sort();

    //iterate over the list
    for(string s : l2) {
        cout << s << " --> ";
    }
    cout << endl;
    //l2.reverse(); // reverse the order of the list.

    // peeking at the first element.
    cout << l2.front() << endl;

    // pop the front element
    l2.pop_front();

    // add to the front of the list.
    l2.push_front("kiwi");

    // inserting element at a particular position
    list<string>::iterator it = l2.begin();
    advance(it, 1); // move the pointer to index 1 ie the second position.
    l2.insert(it, "watermelon");
    l2.insert(it, "orange"); // will insert at index 2
    
    it = l2.begin();
    advance(it, 2);
    l2.insert(it, "fuck");
    
    l2.insert(it, "off");

    for(string s : l2) {
        cout << s << " --> ";
    }

    cout << endl << l2.size();


    return 0;
}