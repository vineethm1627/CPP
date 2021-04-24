#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct segment_tree {
    // array representation of the segment tree to avoid pointer manipulation
    vector<int> st;
    int n;

    // initialize segment tree with 0 values
    void build(int n) {
        // if n is not a power of 2, then multiple it by 2 to get next nearest power of 2
        this->n = n;
        st.resize(4 * n, 0);
    }

    int query_helper(int start, int end, int left, int right, int node) {
        // case-1: no overlap: return from there
        if(start > right || end < left)
            return 0;
        // case-2: complete overlap: return the node value
        if(start >= left && end <= right)
            return st[node];
        // case-3: partial overlap: visit the children to find complete overlap
        int mid = start + (end - start) / 2;
        int q_left = query_helper(start, mid, left, right, 2 * node + 1);
        int q_right = query_helper(mid + 1, end, left, right, 2 * node + 2);

        // return the operation
        return q_left + q_right;
    }

    // sum query from arr[left to right]
    int query(int left, int right) {
        // we always start from the root node
        return query_helper(0, n - 1, left, right, 0);
    }

    // reach the leaf node and make the required updation
    void update_helper(int start, int end, int index, int value, int node) {
        // base case: required leaf node is reached
        if(start == end) {
            st[node] = value;
            return;
        }
        // recursive calls
        int mid = start + (end - start) / 2;
        // index present int the left subtree
        if(index <= mid)
            update_helper(start, mid, index, value, 2 * node + 1);
        else
            update_helper(mid + 1, end, index, value, 2 * node + 2);
        
        // update the parent node while going from leaf node up towards the root
        // perform the operation
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    // update value at index in the array: leaf nodes will be changed to reflect the changes in the array
    void update(int index, int value) {
        update_helper(0, n - 1, index, value, 0);
    }

};

int main() {
    cout << "Enter the size of the array: ";
    int n, q;
    cin >> n;
    cout << "Enter the array elements: ";
    int arr[n];
    pair<int, int> c[n]; // element, index
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        c[i] = make_pair(arr[i], i);
    }
    sort(c, c + n);
    int inversion_count = 0;
    cout << "Building the Segment Tree ......\n";
    segment_tree tree;
    tree.build(n);

    for(int i = 0; i < n; i++) {
        int value = c[i].first;
        int index = c[i].second;

        inversion_count += tree.query(index + 1, n - 1);
        tree.update(index, 1);
    }
    cout << "Inversion count: " << inversion_count << endl;

    return 0;    
}