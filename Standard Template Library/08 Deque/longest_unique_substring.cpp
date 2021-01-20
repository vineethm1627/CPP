/*
    Length of the longest unique(non-repeating characters) substring.
    concept used: sliding window

    input: ababc
    output: abc len = 3

    we need to store the max length of such substring.
    we also need to take into account, the index of the last occurrence of the character.

    whenever new character is there, we either expand the window or contract the window if hte character occurs in the current window.
*/
#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int unique_substr(string str) {
    int cur_len = 1, max_len = 1;

    int visited[256]; // map of char --> last index of occurrence  
    memset(visited, -1, sizeof(visited));

    visited[str[0]] = 0;
    for(int i = 1; str[i]; i++) {
        int last_occur = visited[str[i]];

        // expansion
        // element seen for the first time or element not present in the current window.
        if(last_occur == -1 or last_occur < (i - cur_len)) {
            cur_len++;
        }
        // expansion + contraction
        else {
            max_len = max(cur_len, max_len);
            cur_len = i - last_occur;
        }
        visited[str[i]] = i;
    }
    max_len = max(cur_len, max_len);
    return max_len;
}

int main() {

    string s;
    getline(cin, s);

    cout << unique_substr(s) << endl;

    return 0;
}
