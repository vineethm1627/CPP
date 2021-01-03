#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    cout << "initial size: " << v.size() << endl;
    cout << "initial capacity: " << v.capacity() << endl;
    for(int i = 0; i < 10; i++) {
        v.push_back(10 * i);
        cout << v.size() << endl;
        cout << v.capacity() << endl;
        cout << "-------------------\n";
    }
}