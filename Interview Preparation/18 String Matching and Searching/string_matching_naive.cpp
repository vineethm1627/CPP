/*
    Given a string and a pattern. Find out whether the pattern occurs as a
    substring (contiguous) in the given string.

    using substring in a window
    T(n) = O(n*m)
*/
#include <iostream>
using namespace std;
 
int find(string text, string pattern) {
    int n = text.size(), m = pattern.size();

    for(int i = 0; i + m <= n; i++) {
        if(text.substr(i, m) == pattern) 
            return i;
    }
    return -1;
}
 
int main() {
    
    string text = "abaacadbacad";
    string pattern = "aaca";

    int result = find(text, pattern);
    if(result != -1)
        cout << "Found at index: " << result << '\n';
    else
        cout << "Not found" << '\n';
 
    return 0;
}