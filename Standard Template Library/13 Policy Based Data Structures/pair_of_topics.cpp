/*
    Codeforces problem link : http://codeforces.com/problemset/problem/1324/D
    The next lecture in a high school requires two topics to be discussed. The i-th topic is interesting by ai units for the teacher and by bi units for the students.

    The pair of topics i and j (i<j) is called good if ai+aj>bi+bj (i.e. it is more interesting for the teacher).

    Your task is to find the number of good pairs of topics.

    Input
    The first line of the input contains one integer n (2≤n≤2⋅105) — the number of topics.

    The second line of the input contains n integers a1,a2,…,an (1≤ai≤109), where ai is the interestingness of the i-th topic for the teacher.

    The third line of the input contains n integers b1,b2,…,bn (1≤bi≤109), where bi is the interestingness of the i-th topic for the students.

    Output
    Print one integer — the number of good pairs of topic.

    Examples
    
    inputCopy
    5
    4 8 2 6 2
    4 5 4 1 3
    outputCopy
    7

    inputCopy
    4
    1 3 2 4
    1 3 2 4
    outputCopy
    0
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// elements are repeated, hence use pair instead of int
typedef tree<pair<int, int>, null_type, less< pair<int, int> >, rb_tree_tag,
tree_order_statistics_node_update> new_set;

int main() {
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    for(int i = 0; i < n; i++)
        c[i] = a[i] - b[i];
    
    new_set st;
    long long int ans = 0;

    for(int i = 0; i < n; i++) {
        // elements strictly greater than -c[i]
        // the second part will take care of <= values because of second param being INT_MAX
        // ie. if the first param is same, still the second param will always be less than INT_MAX and will be included in the answer.
        ans += st.size() - st.order_of_key({-c[i], INT_MAX});
        st.insert({c[i], i});
    }
    cout << ans << endl;
    
    return 0;
}