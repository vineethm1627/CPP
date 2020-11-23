/*
    n queries
        add interval [2, 3]
        add interval [10, 20]
        add interval [30, 400]
        add interval [401, 450]
    here no two intervals overlap for simplicity.
    now give the interval in which 13 lies ans = [10, 20]

*/
#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

void findInterval(set<pair<int, int>>& s, int point) {
    /* 
     find the upperbound of {31, ?}, take a step back and check
     {10, 0} --> iterator will point to [10, 20] and by taking one step back will fetch wrong results.
     ? should be big enough to cover up corner cases.
     {10, INT_MAX} --> iterator will point to interval having a strictly greater value than the first component.
    */ 
   
    auto it = s.upper_bound({point, INT_MAX});
    if(it == s.begin()) {
        cout << "given point doesn't lie in any interval" << endl;
        return;
    }
    it--;
    pair<int, int> cur_interval = *it;
    if(cur_interval.first <= point and point <= cur_interval.second) {
        cout << "Interval " << cur_interval.first << " : " << cur_interval.second << endl;
    }
    else {
        cout << "given point doesn't lie in any interval" << endl;
    }
}

int main() {

    set<pair<int, int>> s;
    s.insert({2, 3});
    s.insert({30, 400});
    s.insert({401, 500});
    s.insert({10, 20});
    
    // we know set is internally stored in sorted order.
    /*
       here it means, we have two pairs {a, b} and {c, d}
       return (a < b) or (a == b and c < d);

       in simple terms "sort on the first argument, if it is same then go for the next one"
    */

    // printing the set
    cout << "Given intervals " << endl;
    for(auto i : s) {
       cout << i.first << " : " << i.second << endl;
    }
    /*
    output 
    2 : 3
    10 : 20
    30 : 400
    401 : 500
    */

    int point;
    cout << "Enter the point to be searched : ";
    cin >> point;
    
    findInterval(s, point);


    return 0;
}