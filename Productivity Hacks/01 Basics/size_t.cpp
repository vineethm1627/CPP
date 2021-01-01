/*
    size_t is a datatype used in c and c++
    it cannt take any negative value
    it is adaptable depending upon the system
    it can take the largest value of the object in the program
    it is generally used to calculate the size of the object because it cannot take negative values.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	
    cout<< typeid(int).name() <<"\n"; // i --> integer
    cout<< typeid(size_t).name() << "\n"; // j --> unsigned integer
    
    size_t i = -1;
    
    cout<< i << endl; // 4294967295 2's complement of -1. 
    // 2^32 - 1 --> 111..111 32 times in binary form
	
	return 0;
}