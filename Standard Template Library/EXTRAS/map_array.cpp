/*
    array of map.
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    map<char, int> mci[2];
    string s = "hello";
    for(char c : s) {
        mci[0][c]++;
    }

    s = "bye";
    for(char c : s) {
        mci[1][c]++;
    }

    for(auto it = mci[0].begin(); it != mci[0].end(); it++) {
        cout << it -> first << " " << it -> second << endl; 
    }
    cout << "----------------------------\n";
    for(auto it = mci[1].begin(); it != mci[1].end(); it++) {
        cout << it -> first << " " << it -> second << endl; 
    }

}
