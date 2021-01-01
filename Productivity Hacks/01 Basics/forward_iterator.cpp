/*
    used in all containers especially where random access is not allowed.
    Here, only forward direction traversal is allowed.

    Used in containers: 
        forward_list[singly linked list] 
        unordered_map 
        unordered_set
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	forward_list<int> flist {1, 2, 3, 4};
	
	for( auto x : flist)
	cout << x <<" ";
	
	return 0;
}