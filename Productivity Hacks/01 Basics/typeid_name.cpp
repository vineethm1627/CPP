/*
    typeid can be used to resolve the data type of the variable or an object.
*/
#include <bits/stdc++.h>
using namespace std;

#define print(x) cout<< (#x) << " : " << x << "\n"

int main() {
	
    print(typeid(int).name());
    print(typeid(float).name());
    print(typeid(char).name());
    print(typeid(string).name());
    print(typeid(int*).name());
    print(typeid(double).name());
    print(typeid(char*).name());
    print(typeid(float*).name());
	print(typeid(double*).name());
	print(typeid(set<int>()).name());
	print(typeid(map<int,int>()).name());
	print(typeid(set<int>::iterator).name());
	print(typeid(vector<int>()).name());
	print(typeid(size_t).name());
	print(typeid(unsigned int).name());
	print(typeid(long long).name());
	print(typeid(int []).name());
	print(typeid(pair<int,int>).name());
	print(typeid(tuple<int,int, float>).name());
	print(typeid(int&).name());
	print(typeid(int**).name());
	
	return 0;
}