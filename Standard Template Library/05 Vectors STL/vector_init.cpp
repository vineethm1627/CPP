#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> a;
    vector<int> b(4, 10); // 5 integers with value 10
    //vector<int> a(n, 0); init a vector of n elements each with a value = 0
    vector<int> c(b.begin(), b.end()); // init with elements of another vector.
    vector<int> d {1, 2, 3, 4, 5};

    // iterate over the vector
    cout << "c" << endl;
    for(int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    b.push_back(5); // adds an element to the end of the vector. also expands the memory if needed
    // using iterator
    cout << "b" << endl;
    for(auto it = b.begin(); it != b.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // enhanced for loop
    cout << "d" << endl;
    for(int i : d) { 
        cout << i << " ";
    } 
    cout << endl;
    // understand at memory level, the difference between b and d.
    cout << "for b " << endl;
    cout << b.size() << endl; // no. of elements the vector contains
    cout << b.capacity() << endl; // 8(because push_back, size got doubled) size of the underlying array
    cout << b.max_size() << endl; // max. no. of elements vector can hold in the worst case acc. to available memory in the system
    
    cout << "for d " << endl;
    cout << d.size() << endl;
    cout << d.capacity() << endl; // 5
    cout << d.max_size() << endl;

    return 0;
}