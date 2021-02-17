/*
    Given a string and a pattern. Find out whether the pattern occurs as a
    substring (contiguous) in the given string.

    First insert all the suffixes of the string in the trie
    for example:
    input: abaac
    suffix-1: abaac
    suffix-2: baac
    suffix-3: aac 
    suffix-4: ac
    suffix-5: c
*/
#include <iostream>
using namespace std;

class node {
    public:
        node *next[26];
        //bool terminal;

        node() {
            for(int i = 0; i < 26; i++) 
                next[i] = NULL;
            //terminal = false;
        }
};

class Trie {
    public:
        node *root;
    
        Trie() {
            root = new node();
        }

        void insert(string s) {
            node *curr = root;
            for(int i = 0; s[i]; i++) {
                if(curr->next[s[i] - 'a'] == NULL)
                    curr->next[s[i] - 'a'] = new node();
                curr = curr->next[s[i] - 'a'];
            }
        }

        bool find(string s) {
            node *curr = root;
            for(int i = 0; s[i]; i++) {
                if(curr->next[s[i] - 'a'] == NULL)
                    return false;
                curr = curr->next[s[i] - 'a'];
            }
            return true;
        }
};

int main() {

    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    Trie t;
    // constructing the trie by inserting all the suffixes in the tree
    for(int i = 0; i < text.size(); i++)
        t.insert(text.substr(i));

    if(t.find(pattern))
        cout << "FOUND" << '\n';
    else    
        cout << "NOT FOUND" << '\n';

    return 0;
}