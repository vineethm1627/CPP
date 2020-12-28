#include <iostream>
#include <climits>
#include <set>
using namespace std;

int main() {

    // pairs are going to be sorted according to their first value and then second value

    set< pair<int, int> > s;
    // insert elements
    s.insert({10, 1});
    s.insert({10, 5});
    s.insert({20, 1});
    s.insert({20, 100});
    s.insert({5, 1});
    s.insert({5, 3});
    s.insert({5, 2});

    // erase element
    if(s.find(make_pair(5, 3)) != s.end()) {
        s.erase(make_pair(5, 3));
        s.insert(make_pair(5, 5));
    }
    
     cout << "size of the set : " << s.size() << endl; 

    // print the set
    // for(auto it = s.begin(); it != s.end(); it++) 
    //     cout << it->first << " " << it->second << endl;
   
    for(pair<int, int> p : s) 
        cout << p.first << " " << p.second << endl;

    //auto ub = s.upper_bound({10, 1}); // {10,5}
    auto ub = s.upper_bound({10, INT_MAX}); // {20,5}
    if(ub != s.end()) 
        cout << ub -> first << " " << (*ub).second << endl;

    

    return 0;
}