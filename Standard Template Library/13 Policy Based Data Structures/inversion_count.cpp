/*
    i < j : a[i] > a[j]
    2 1 --> no of inversions = 1

    find inversions in the array using PBDS.

    arr = {1, 5, 2, 3, 6, 4, 10}
           0, 0, 1, 1, 0, 2, 0

    So total number of inversions in the array = 1+1+2 = 4

    Here, we assume all the elements in the array are distinct.
    If the elements are repeated, then go for pair<int, int> instead of int.
    
*/
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> new_set;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    new_set st;
    int count = 0;
    for(int i = 0; i < n; i++) {
        // elements in the set strictly > the key
        count += st.size() - st.order_of_key(arr[i]);
        st.insert(arr[i]);
    }

    cout << count << endl;
    return 0;
}