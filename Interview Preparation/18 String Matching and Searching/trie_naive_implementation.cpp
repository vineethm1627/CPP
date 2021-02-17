/*
    Trie implementation for storing lower case characters.
*/
#include <iostream>
using namespace std;

class node {
    public:
        node *next[26];
        bool terminal;

        node() {
            for(int i = 0; i < 26; i++) 
                next[i] = NULL;
            terminal = false;
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
            // curr pointer will be on the ending node
            curr->terminal = true;
        }

        bool find(string s) {
            node *curr = root;
            for(int i = 0; s[i]; i++) {
                if(curr->next[s[i] - 'a'] == NULL)
                    return false;
                curr = curr->next[s[i] - 'a'];
            }
            return curr->terminal;
        }
};

int main() {

    Trie t;
    t.insert("apaar");
    t.insert("vishal");
    t.insert("kamal");
    t.insert("rahul");
    t.insert("kartik");
    t.insert("saurabh");

    string s;
    getline(cin, s);

    if(t.find(s))
        cout << "FOUND" << '\n';
    else    
        cout << "NOT FOUND" << '\n';

    return 0;
}