/*
    push_back() vs emplace_back() in vector:

    Although it looks like they function in the similar way, their backend implementation is different.

    In push_back():
        First, a string object will be implicitly created, initialized with provided char* value.
        Then push_back() will be called which will copy this string into the vector using the move constructor.
        The temporary object will then be destroyed.

    In emplace_back():
        It constructs the string in-place, so not temporary string will be created.
        So, in this case, we avoid constructing and destroying an unnecessary temporary string object.
    
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	
    vector<string> words;
    words.push_back("push_back");
    words.push_back("emplace_back");
    
    for(auto x : words){
        cout<< x << "\n";
    }
	return 0;
}