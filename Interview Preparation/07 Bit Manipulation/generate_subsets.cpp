/*
    given a string generate all possible Subsequences / Subsets.
    
    Example

    Input:
    abc

    Output:
    " ", a, ab, abc, ac, b, bc, c
*/
#include <iostream>
using namespace std;

void filterChars(string s, int n) {
    int j = 0;
    while(n) {
        int last_bit = (n & 1);
        if(last_bit) 
            cout << s[j];
        j++;
        n = n >> 1;
    }
    cout << endl;
}

void generate(string s) {
    int n = s.size();
    // 1 << n = 1 * pow(2, n);
    for(int i = 0; i < (1 << n); i++) {
        filterChars(s, i);
    }
}

int main() {

    string s;
    getline(cin ,s);

    generate(s);
    return 0;
}