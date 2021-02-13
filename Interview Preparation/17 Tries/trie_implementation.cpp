/*
    given a huge paragraph, output the presence / absence of a query word.
    instead of hashMap, we could make use of Trie data structure.

    Trie --> Prefix Tree
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class node {
    public:
        char data;
        unordered_map<char, node*> children;
        bool terminal;

        node(char data) {
            this->data = data;
            terminal = false;
        }
};

class Trie {
    node *root;
    int count;

    public:
        Trie() {
            root = new node('\0');
            count = 0;
        }

        void insert(char *word) {
            node *temp = root;
            for(int i = 0; word[i]; i++) {
                char ch = word[i];
                // if the character is present then move to the next level
                if(temp->children.find(ch) != temp->children.end()) 
                    temp = temp->children[ch];
                else {
                    // update the node in the hash map
                    node *n = new node(ch);
                    temp->children[ch] = n;
                    temp = n;
                }
            }
            // once the entire word is stored, mark the last node as the terminal node
            temp->terminal = true;
        }

        bool find(char *word) {
            node *temp = root;
            for(int i = 0; word[i]; i++) {
                char ch = word[i];
                if(temp->children.find(ch) == temp->children.end())
                    return false;
                else    
                    temp = temp->children[ch];
            }
            if(temp->terminal)
                return true;
            else
                return false;
        }
};

int main() {

    Trie t;
    char words[][10] = {"a", "hello", "not", "news", "apple"};

    for(int i = 0; i < 5; i++) 
        t.insert(words[i]);
    
    char w[10];
    cin >> w;

    if(t.find(w)) 
        cout << "present" << endl;
    else 
        cout << "absent" << endl;

    return 0;
}