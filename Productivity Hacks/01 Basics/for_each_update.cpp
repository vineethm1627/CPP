#include <bits/stdc++.h>
using namespace std;

int main() {
	
	vector<int> v{1,2,3};
	
	for(auto x : v)
	    cout << x << " ";
	
    // variable as reference, the changes with will reflected in the original values
	for(auto &x : v)
	    x += 1;
	
	cout << endl;
	for(auto x : v)
	    cout << x <<" ";
	// 2 3 4
	
	return 0;
}