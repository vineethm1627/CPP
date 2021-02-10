/*
    convert array/ vector to maxHeap in-place.
    O(nlogn) --> less efficient method.
*/

#include <iostream>
#include <vector>
using namespace std;
 
// global variable
int type; // true->minHeap, false->maxHeap

bool compare(int a, int b) {
    if(type)
        return a < b;
    else
        return a > b;    
}

void buildHeap(vector<int> &v) {
    for(int i = 2; i < v.size(); i++) {
        int index = i;
        int parent = i / 2;

        while(index > 1 and compare(v[index], v[parent])) {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }
}

void print(vector<int> v) {
    for(int i = 0; i < v.size() - 1; i++)
        cout << v[i] << " ";
    cout << endl;
}
 
int main() {
    
    vector<int> v {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    cout << "enter 0(maxHeap), 1(minHeap): ";
    cin >> type;
    buildHeap(v);
    print(v);

    return 0;
}