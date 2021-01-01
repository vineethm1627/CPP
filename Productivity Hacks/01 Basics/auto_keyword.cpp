#include <bits/stdc++.h>
using namespace std;

int main() {
	
    auto x = 10;
    cout<< typeid(x).name() << endl;
    
    auto *px  = &x;
    cout<< typeid(px).name() << endl;
    
    map<int, int> mp;
    cout<< typeid(mp).name() << endl;
	
	vector<int> vec = {1};
	for(auto elem :  vec){
	    cout<< typeid(elem).name() << endl;
	}
	
	auto y = 2.23;
	cout<< typeid(y).name() << endl;
	
	auto *py = new auto(y);
	cout<< typeid(py).name() << endl;
	
	return 0;
}