#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less< pair<int, int> >, rb_tree_tag,
tree_order_statistics_node_update> new_set;

int main() {

    new_set st;
    // for repeating the first element, make the second value unique.
    st.insert({1, 1});
    st.insert({1, 2}); // no effect as duplicates are not allowed in sets
    // by above 2 line '1' will be inserted 2 times.
    st.insert({10, 1});
    st.insert({4, 1});
    st.insert({3, 1});
    st.insert({15, 1});
    st.insert({15, 2});

    // kth largest element till now (0 1 2 .. kth)
    // O(logn)
    for(int i = 0; i < st.size(); i++) {
        // index --> value
        cout << st.find_by_order(i)->first << " " << st.find_by_order(i)->second << endl;
    }
    

    return 0;
}