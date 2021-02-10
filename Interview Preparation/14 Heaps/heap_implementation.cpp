#include <iostream>
#include <vector>
using namespace std;
 
/*
    visualize the operations on a Binary Tree but the actual implementation will be on arrays.
    root index is 1.
    for a node with index i:
        left child: 2i
        right child: 2i + 1
    
    insert the element at the last index.
    in case of minHeap, if it is greater than its parent floor(i).
    swap this value with the parent node value.
    Repeat the above steps till the time minHeap property is not violated.

    insertion: O(logN)
*/ 

class Heap {
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b) {
        if(minHeap)
            return a < b;
        else
            return a > b;
    }

    public:
        Heap(int default_size = 10, bool type = true) {
            v.reserve(default_size); // no expansion takes place till 10 elements are added
            v.push_back(-1); // block 0th index as tree indexing starts from 1.
            minHeap = type;
        }

        void push(int data) {
            // insert the element at the end
            v.push_back(data);
            // compare with its parent
            int i = v.size() - 1;
            int parent_i = i / 2;

            // keep pushing to the top till you reach root node
            // or stop midway if current element is greater than the parent
            while(i > 1 and compare(v[i], v[parent_i])) {
                swap(v[i], v[parent_i]);
                i = parent_i;
                parent_i = parent_i / 2;
            }
        }

        int top() {
            return v[1];
        }

        bool empty() {
            return v.size() == 1;
        }

        // bring the smallest/ largest element on the top.
        void heapify(int index) {
            int left = 2 * index;
            int right = left + 1;

            int last = v.size() - 1;
            int min_index = index;

            // only compare if the child node exists.
            if(left <= last and compare(v[left], v[index])) 
                min_index = left;
            if(right <= last and compare(v[right], v[min_index]))
                min_index = right;
            
            // recursive call
            if(min_index != index) {
                swap(v[index], v[min_index]);
                heapify(min_index);
            }
        }

        // remove the root element
        void pop() {
            swap(v[1], v[v.size() - 1]);
            v.pop_back();

            heapify(1);
        }
};

int main() {

    // take user input for minHeap and maxHeap
    // Heap minHeap(10, false); for maxHeap
    Heap minHeap;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        minHeap.push(data);
    }

    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}