/*
    given a huge paragraph, output the presence / absence of a query word.
    instead of hashMap, we could make use of Trie data structure.

    Trie --> Prefix Tree
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
        char data;
        unordered_map<char, Node*> children;
        bool terminal;
    
        Node(char data) {
            this->data = data;
            terminal = false;
        }       
};

class Trie {
    Node *root;
    int count;

    public:
        Trie() {
            root = new Node('\0');
            count = 0;
        }

        void insert(char *word) {
            Node *temp = root;
            for(int i = 0; word[i] != '\0'; i++) {
                char ch = word[i];
                if(temp->children.count(ch)) {
                    // the character is present.
                    temp = temp->children[ch];
                }
                else {
                    Node *n = new Node(ch);
                    temp->children[ch] = n;
                    temp = n;
                }
            }
            // once the entire word is stored, mark thenlast node as the terminal node.
            temp->terminal = true;
        }

        bool find(char *word) {
            Node *temp = root;
            for(int i = 0; word[i] != '\0'; i++) {
                char ch = word[i];
                if(temp->children.count(ch) == 0) {
                    return false;
                }
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

    for(int i = 0; i < 5; i++) {
        t.insert(words[i]);
    }

    char w[10];
    cin >> w;

    if(t.find(w))
        cout << "present";
    else 
        cout << "absent";

    return 0;
}