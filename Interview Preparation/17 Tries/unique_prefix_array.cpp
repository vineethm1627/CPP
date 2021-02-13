/*
    Given a list of words, output the smallest unique prefix for every word.

    example: ["cobra", "dog", "dove", "duck"]
    output: ["c", "dog", "dov", "du"]

    Efficient solution is to use Trie (Prefix Tree).
    1.  Maintain a frequency count variable in every node.
        Here frequency is the number of times node is visited during insertion.
        T(n) = O(n) where n is the total number of characters in the word.

    2.  Now for every word, we find the character nearest to the root node with freq = 1.
        The prefix of the word is path from root to this character.
        T(n) = O(n)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class node {
    public:
        char data;
        int freq;
        unordered_map<char, node*> children;

        node(char data) {
            this->data = data;
            freq = 1;
        }
};

class Trie {
        node *root;
    public:
        Trie() {
            root = new node('\0');
        }

        void insert(string word) {
            node *curr = root;

            for(int i = 0; i < word.size(); i++) {
                char ch = word[i];

                if(curr->children.find(ch) != curr->children.end()) {
                    curr = curr->children[ch];
                    curr->freq++;
                }
                else {
                    node *n = new node(ch);
                    curr->children[ch] = n;
                    curr = n;
                }
            }
        }

        string prefix(string word) {
            node *temp = root;
            string ans;
            for(int i = 0; i < word.size(); i++) {
                char ch = word[i];
                if(temp->children.find(ch) != temp->children.end()) {
                    ans += ch;
                    temp = temp->children[ch];
                    if(temp->freq == 1)
                        break;  
                }
            }
            return ans;
        }

        vector<string> findPrefixWords(string *str, int n) {
            vector<string> result;
            // insert all the strings in the trie
            for(int i = 0; i < n; i++)
                insert(str[i]);
            for(int i = 0; i < n; i++) 
                result.push_back(prefix(str[i]));
            return result;
        }
};
 
 
int main() {

    Trie t;
    int n;
    cin >> n;

    string str[n];
    for(int i = 0; i < n; i++) 
        cin >> str[i];
    
    vector<string> result = t.findPrefixWords(str, n);
    for(string s : result)
        cout << s << " ";
 
    return 0;
}