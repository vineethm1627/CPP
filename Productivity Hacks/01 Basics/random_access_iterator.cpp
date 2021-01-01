/*
    supported in containers: vector and deque
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	vector<int> v {10, 20, 30};
	
	vector<int> :: iterator itr = v.begin();
	// forward access
	for(auto x : v)
	    cout << x << " ";
	
    // direct random access
    cout << endl << *(itr + 2) << endl; 
	
	vector<int> :: reverse_iterator rit;
	// backward access
	for(rit = v.rbegin(); rit != v.rend(); rit++)
	cout << *rit << " ";
	
	return 0;
}