#include <iostream>
#include <vector>
using namespace std;

int main() {
	
    vector<string> s {"gfg", "ide", "practise"};
    
    vector<string> :: iterator it;
    
    cout<< s.size() << endl;
    
    for(auto it = s.begin(); it != s.end(); ) {
        cout << *it << " ";
        it = s.erase(it);
    }
  
    cout<< endl << s.size() << endl;
    return 0;
}