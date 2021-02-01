/*
    delete a node in BST
    sample input for tree: 5 3 7 1 6 8 -1

    There are 3 types of nodes:
        0 children : delete and return NULL
        1 child : delete and return the child of this node
        2 children : delete and find the potential replacement
    
    for finding the potential candidate for replacement:
        first find the inorder traversal (LNR)
        the root node should be replaced by the immediate predecessor or immediate successor.
    
    instead of finding the inorder traversal, you can replace it by the max element of the left subtree or the min element of the right subtree.
*/
#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

        node(int data) {
            this->data = data;
            left = right = NULL;
        }
};

// print tree, level by level
void BFS(node *root) {
    if(root == NULL)
        return;
    
    queue<node*> q;
    q.push(root);
    // for newline
    q.push(NULL);

    while(!q.empty()) {
        node *front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else {
            cout << front->data << " ";
            // push the children of front if they exist
            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);
        }
    }
}

// print tree inorder, LNR
void inorder(node *root) {
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// accepts the old root node and returns the new root node
node* insert(node *root, int data) {
    // base case
    if(root == NULL)
        return new node(data);
    
    // recursive calls
    if(data <= root->data) 
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

node* build() {
    // read a list of numbers till -1 and insert them into BST
    int data;
    cin >> data;

    node *root = NULL;
    while(data != -1) {
        root = insert(root, data);
        cin >> data;
    }
    return root;
}

bool search(node *root, int key) {
    // base case
    if(root == NULL)
        return false;
    
    if(root->data == key)
        return true;
    
    // recursive calls
    if(key <= root->data) 
        return search(root->left, key);
    else
        return search(root->right, key);
}

node* deleteNode(node *root, int key) {
    // base case
    if(root == NULL)
        return NULL;
    // recursive calls
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
        return root;
    }
    else {
        // we found the node to be deleted
        // case-1: node with 0 children ie. leaf node
        if(root->left == NULL and root->right == NULL) {
            delete root;
            return NULL; // return NULL to the parent node
        }
        // case-2: one child in the left subtree
        else if(root->left != NULL and root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp; //return children of this deleted node to the parent node
        }
        else if(root->left == NULL and root->right != NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
        // case-3: node with 2 children
        else {
            // find the inorder successor of the node to be deleted
            // inorder successor is the min value node in the right subtree
            node *replace = root->right;
            while(replace->left != NULL)
                replace = replace->left;
            
            // replace this with the root's data
            root->data = replace->data;
            // recursively delete the replace node in the right subtree
            root->right = deleteNode(root->right, replace->data);
            
            return root;
        }
    }
}

istream& operator>>(istream& cin, node *&root) {
    root = build();
    return cin;
}

ostream& operator<<(ostream& cout, node *root) {
    BFS(root);
    return cout;
}

int main() {

    node *root = NULL;
    cin >> root;
    cout << "original tree: ";
    inorder(root); // will receive the sorted output
    cout << endl;
    cout << root;
    int key;
    cout << "enter the data to be deleted: ";
    cin >> key;
    root = deleteNode(root, key);
    cout << "after deletion: ";
    inorder(root);
    cout << endl;
    cout << root;

    return 0;
}