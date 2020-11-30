/*
    reverse the words in a sentence.

    Input : cool is vineeth
    Output : vineeth is cool
*/
#include <iostream>
#include <sstream>

using namespace std;

string mirror(string str) {
    string word, res = "";
    stringstream ss(str);

    while(ss >> word) {
        res.insert(0, word);
        res.insert(0, " ");
    }
    return res;
}

int main() {
    
    string str;
    getline(cin, str);

    string r = mirror(str);
    cout << r;
}
