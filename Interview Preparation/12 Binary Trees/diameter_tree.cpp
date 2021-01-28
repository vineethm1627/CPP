/*
    diameter of tree = longest distance between any 2 nodes of the tree

    diameter could be the number of nodes between node of left subtree and node of right subtree.
    inverted V shaped.

    we basically count the edges for the calculation of diameter.

    there are 3 cases:
        diameter passes through the root ==> height(left) + height(right)
        diameter lies in the left subtree ==> recursive function call
        diameter lies in the right subtree ==> recursive function call
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

int height(node *root) {
    if(root == NULL)
        return 0;
    
    int h_left = height(root->left);
    int h_right = height(root->right);

    return 1 + max(h_left, h_right);
}

int diameter(node *root) {
    if(root == NULL)
        return 0;
    
    int h_left = height(root->left);
    int h_right = height(root->right);

    // diameter passes through the root, count edges only
    int option1 = h_left + h_right;
    // diameter lies in the left subtree
    int option2 = diameter(root->left);
    // diameter lies in the right subtree
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}


int main() {

    node *root = buildTree();
    cout << "diameter of the tree: " << diameter(root) << endl;

    return 0;
}