/*
    build a binary tree from user input using recursion.
    preorder print: NLR

    example:

        input: 3 4 -1 -1 5 -1 -1

        output:
             3
            / \
           4   5
*/
#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

        node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

node* buildTree() {
    int data;
    cin >> data;

    if(data == -1)
        return NULL;
    
    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    
    return root;
}

// preorder print: NLR
void preorder_print(node *root) {
    // base case
    if(root == NULL)
        return;
    
    // print root (N)
    cout << root->data << " ";
    // print(L)
    preorder_print(root->left);
    // print(R)
    preorder_print(root->right);
}

int main() {
    
    node *root = buildTree();
    preorder_print(root);

    return 0;
}