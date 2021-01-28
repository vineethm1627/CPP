/*
    print tree level by level
    1st level prints out the root node.

    height of the tree = max depth
    number of levels = height of the tree
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

int height(node *root) {
    if(root == NULL)
        return 0;
    
    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height, right_height) + 1;
}

void printKthLevel(node *root, int k) {
    if(root == NULL)
        return;
    //you are on the correct level
    if(k == 1) {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}

void levelorder_print(node *root) {
    int H = height(root);
    for(int level = 1; level <= H; level++) {
        printKthLevel(root, level);
        cout << endl;
    }
}

int main() {

    node *root = buildTree();
    cout << "level order print: " << endl;
    levelorder_print(root); 

    return 0;
}