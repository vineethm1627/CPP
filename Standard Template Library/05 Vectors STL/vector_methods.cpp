#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> v{1, 2, 3, 4, 5};
    // push at the end of the vector O(1) except during size doubling
    v.push_back(6);
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // pop the last element O(1)
    v.pop_back();
    cout << v.size() << endl;

    // insert some elements in the middle of the vector.
    v.insert(v.begin() + 3, 10); // add 10 at the index = 3 (iterator, element)

    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // insert 4 elements each of value = 10, O(n) as shifting needs to be done
    v.insert(v.begin() + 1, 4, 10);

    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // erase element at index 3 in the middle
    v.erase(v.begin() + 3);

    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // erase range of elements
    v.erase(v.begin() + 1, v.begin() + 4); // akin to python last index is not included

    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
    cout << v.capacity() << endl;
    // we generally avoid shrink operation.
    v.resize(8);
    cout << v.capacity() << endl;

    // resizing to higher size will result in the increased capacity.
    v.resize(20);
    cout << v.capacity() << endl;

    // remove all the elements of the vector
    v.clear(); // doesn't delete the memory allocated by the array
    cout << v.capacity() << endl; // no change
    cout << v.size() << endl; // 0 since there are no elements

    // check if the vector is empty ie. size is 0
    if(v.empty()) {
        cout << "vector is empty" << endl;
    }
    else { 
        cout << "vector is not empty" << endl;
    }
    // inserting some elements in the array.
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // insert at the last index ie. 3.
    v.insert(v.begin() + 3, 40);
    cout << "size " << v.size() << endl;
    cout << "capacity : " << v.capacity() << endl;
    cout << "front element peek : " << v.front() << endl;
    cout << "last element peek : " << v.back() << endl;

    vector<int> v1;
    // we can observe the doubling of capacity.
    for(int i = 0; i < 5; i++) {
        v1.push_back(i);
        cout << "current size : " << v1.size() << endl; 
        cout << "current capacity : " << v1.capacity() << endl;
    }

    // reserve, use this to avoid doubling of memory allocation
    vector<int> v2;
    v2.reserve(100);
    // we will observe no change in capacity and the value of capacity will be 100
    for(int i = 0; i < 5; i++) {
        v2.push_back(i);
        cout << "current size : " << v2.size() << endl; 
        cout << "current capacity : " << v2.capacity() << endl;
    }
    return 0;
}