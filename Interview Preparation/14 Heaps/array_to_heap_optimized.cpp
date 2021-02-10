/*
    convert array/ vector to maxHeap in-place.
    O(n) --> efficient approach.
    uses approach of heapsort.

    go from bottom to top.
    for the leaf nodes you dont need as they are a heap in themselves

    first non-leaf node = n / 2
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

void heapify(vector<int> &v, int index) {
    int left = 2 * index;
    int right = left + 1;
    int last = v.size() - 1;
    int min_index = index;

    if(left <= last and compare(v[left], v[index])) 
        min_index = left;
    if(right <= last and compare(v[right], v[min_index]))
        min_index = right;
    
    if(min_index != index) {
        swap(v[min_index], v[index]);
        heapify(v, min_index);
    }
}

void buildHeap(vector<int> &v) {
    // n / 2 is the first non-leaf node
    for(int i = (v.size()-1) / 2; i > 0; i--)
        heapify(v, i);
    
}

void print(vector<int> v) {
    for(int i = 1; i < v.size(); i++)
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