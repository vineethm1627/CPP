/*
    For a tree to be height balanced, at every node:
        absolute difference between the height of left and right subtrees should be <= 1.
        abs(height(left) - height(right)) <= 1

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

class Pair {
    public:
        int height;
        bool balanced;
};

Pair isHeightBalanced(node *root) {
    Pair p;
    if(root == NULL) {
        p.height = 0;
        p.balanced = true;
        return p;
    }

    // postorder, bottom-up traversal
    Pair left = isHeightBalanced(root->left);
    Pair right = isHeightBalanced(root->right);

    p.height = max(left.height, right.height) + 1;
    if(abs(left.height - right.height) <= 1 and left.balanced and right.balanced)
        p.balanced = true;
    else
        p.balanced = false;

    return p;
}

int main() {

    node *root = buildTree();

    Pair result = isHeightBalanced(root);
    if(result.balanced)
        cout << "height balanced tree" << endl;
    else
        cout << "not a height balanced tree" << endl;

    return 0;
}