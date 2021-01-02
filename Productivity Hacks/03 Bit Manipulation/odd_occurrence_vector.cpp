#include <bits/stdc++.h>
using namespace std;


int main() {
	
   vector<int> v {1, 2, 2, 3, 3};
   
   int ans = 0;
   
   for(auto x : v){
       ans ^= x;
   }
   
   cout<< ans << endl;
	
	return 0;
}