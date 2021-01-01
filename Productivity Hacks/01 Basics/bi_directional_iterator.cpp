/*
    Combination of forward and backward iterator but random access iterator.
    Works in containers:
        set
        multiset
        map
        multimap
        vector
        deque
        list[doubly linked list]


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	set<int> s{1, 2, 3};
	
	for(auto x : s)
	    cout<< x << " ";
	    
	cout<<endl;
	
	set<int>::reverse_iterator rit;
	
	for(rit = s.rbegin(); rit != s.rend(); rit++)
	    cout<< *rit <<" ";
	
	
	return 0;
}