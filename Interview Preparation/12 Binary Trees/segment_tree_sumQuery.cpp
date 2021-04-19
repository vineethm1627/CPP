#include <iostream>
#include <vector>
using namespace std;

struct segment_tree {
    // array representation of the segment tree to avoid pointer manipulation
    vector<int> st;
    int n;

    // build segment tree vector "st" from the array
    void build_helper(int *arr, int start, int end, int node) {
        // base case: we reach the leaf node
        if(start == end) {
            st[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        /*
            Note: array indexing starts from 0.
            root node -> 0
            left child -> 2 * 0 + 1 = 1
            right child -> 2 * 0 + 2 = 2
        */
        // recursive calls: postorder: LRN
        // left build
        build_helper(arr, start, mid, 2 * node + 1);
        // right build
        build_helper(arr, mid + 1, end, 2 * node + 2);

        // update the value in the parent node
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(int *arr, int n) {
        // if n is not a power of 2, then multiple it by 2 to get next nearest power of 2
        st.resize(4 * n, 0);
        this->n = n;
        // range [0 to n - 1] and place the value at index 0 in vector "st"
        build_helper(arr, 0, n - 1, 0);
    }

    int query_helper(int start, int end, int left, int right, int node) {
        // case-1: no overlap: return from there
        if(start > right || end < left)
            return 0;
        // case-2: complete overlap: return the node value
        if(start >= left && end <= right)
            return st[node];
        // case-3: partial overlap: visit the left and right child to find complete overlap
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
        // base case: req. leaf node is reached
        if(start == end) {
            // make the update
            st[node] = value;
            return;
        }
        // recursive calls: postorder traversal LRN
        int mid = start + (end - start) / 2;
        // index present in the left subtree
        if(index <= mid) 
            update_helper(start, mid, index, value, 2 * node + 1);
        else
            update_helper(mid + 1, end, index, value, 2 * node + 2);

        // update the parent node while going from leaf node up towards the root
        // perform the operation
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    // update value at index in the array: leaf nodes will be changed to reflect changes in the array
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
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Building the Segment Tree ......\n";
    segment_tree tree;
    tree.build(arr, n);

    cout << "Enter the number of queries: ";
    cin >> q;
    pair<int, pair<int, int>> p;
    cout << "Enter the queries:(0: range, 1: update)" << endl;
    for(int i = 0; i < q; i++) {
        cin >> p.first;
        cin >> p.second.first >> p.second.second;
        
        if(!p.first)
            cout << tree.query(p.second.first, p.second.second) << endl;
        else
            tree.update(p.second.first, p.second.second);
    }

    return 0;    
}
