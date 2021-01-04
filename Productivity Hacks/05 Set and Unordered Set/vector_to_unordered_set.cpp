#include <bits/stdc++.h>
using namespace std;

int main() {
	
    vector<int> v{1, 2, 3, 7, 8, 9};
    
    unordered_set<int> s(v.begin(), v.end());
    
    for( auto x : s){
        cout<< x << " ";
    }
    
	return 0;
}