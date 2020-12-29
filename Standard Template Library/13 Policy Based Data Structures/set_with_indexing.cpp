#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> new_set;

int main() {

    new_set st;
    st.insert(1);
    st.insert(1); // no effect as duplicates are not allowed in sets
    st.insert(10);
    st.insert(4);
    st.insert(3);
    st.insert(15);

    // kth largest element till now (0 1 2 .. kth)
    // O(logn)
    for(int i = 0; i < st.size(); i++) {
        // index --> value
        cout << *st.find_by_order(i) << endl;
    }

    // set element at index = 3
    cout << "at index = 3 : " << *st.find_by_order(3) << endl;

    // number of elements stricttly less than key
    // O(logn)
    cout << "No. of elements less than 5 : " << st.order_of_key(5) << endl;

    return 0;
}