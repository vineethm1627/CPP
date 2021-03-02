/*
    Print characters and their frequencies in order of occurrence using Binary Tree
    Given a string str containing only lowercase characters. The problem is to print the characters along with their frequency in the order of their occurrence using Binary Tree
*/
#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
        char data;
        int count;
        node *left;
        node *right;

        node(char data) {
            this->data = data;
            count = 1;
            left = right = NULL;
        }
};

node *addLevelOrder(node *root, char data) {
    if(root == NULL)
        return new node(data);
    
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node *front = q.front();
        q.pop();

        if(front->data == data) {
            front->count++;
            break;
        }

        if(front->left == NULL) {
            front->left = new node(data);
            break;
        } 
        else {
            if(front->left->data == data) {
                front->left->count++;
                break;
            }
            q.push(front->left);
        }

        if(front->right == NULL) {
            front->right = new node(data);
            break;
        }
        else {
            if(front->right->data == data) {
                front->right->count++;
                break;
            }
            q.push(front->right);
        }
    }
    return root;
}

void printLevelOrder(node *root) {
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node *front = q.front();
        q.pop();

        cout << front->data << " : " << front->count << '\n';

        if(front->left)
            q.push(front->left);
        
        if(front->right)
            q.push(front->right);
    }
}

int main() {
    
    string s = "geeksforgeeks";
    node *root = NULL;

    for(int i = 0; s[i]; i++) 
        root = addLevelOrder(root, s[i]);

    printLevelOrder(root);

    return 0;
}