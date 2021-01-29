/*
    O(n) solution for finding the diameter of the tree.
    bottom up traversal, postorder traversal
    we will store the height.
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

class Pair {
    public:
        int height;
        int diameter;
};

Pair diameter_optimized(node *root) {
    Pair p;
    if(root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }

    Pair left = diameter_optimized(root->left);
    Pair right = diameter_optimized(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}

// build tree in preorder
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


int main() {

    node *root = buildTree();

    Pair p = diameter_optimized(root);
    cout << "height of the tree: " << p.height << endl;
    cout << "diameter of the tree: " << p.diameter << endl;

    return 0;
}