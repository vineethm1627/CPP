/*
    inorder --> LNR
    postorder --> LRN
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

// preorder build of a tree
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

// NLR
void preorder_print(node *root) {
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorder_print(root->left);
    preorder_print(root->right);
}

// LNR
void inorder_print(node *root) {
    if(root == NULL)
        return;

    inorder_print(root->left);
    cout << root->data << " ";
    inorder_print(root->right);
}

// LRN
void postorder_print(node *root) {
    if(root == NULL)
        return;
    
    postorder_print(root->left);
    postorder_print(root->right);
    cout << root->data << " ";
}

int main() {

    node *root = buildTree();
    cout << "preorder print: " << endl;
    preorder_print(root); 
    cout << endl;
    cout << "inorder print: " << endl;
    inorder_print(root);
    cout << endl;
    cout << "postorder print: " << endl;
    postorder_print(root);

    return 0;
}