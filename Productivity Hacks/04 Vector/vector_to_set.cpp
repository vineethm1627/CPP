#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	
    vector<int> v {7, 8, 9, 1, 1, 2, 2, 3};
    set<int> s(v.begin(), v.end());
    cout << "vector size: " << v.size() << endl;
    cout << "set size: " << s.size() << endl;
    cout << "unique elements in ascending order: \n";
    for(auto x : s){
        cout<< x << " ";
    }
        
        return 0;
}