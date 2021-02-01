/*
    check if a given tree is a BST or not.
    a given root node should be >= max node in the left subtree and <= min node in the right subtree
    also left and right subtrees should both be a BST

    bottom up approach where each node will return left_max, right_min values and bool value indicating it is a BST

    we can also solve this via top-down approach
    each node returns the min to max permissible value pair
    if the given node does not lie in the range (min, max) then the BST property gets violated.
*/
#include <iostream>
#include <climits>
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

bool isBST(node *root, int min_val = INT_MIN, int max_val = INT_MAX) {
    if(root == NULL) 
        return true;
    
    if(root->data >= min_val and root->data <= max_val and isBST(root->left, min_val, root->data) and isBST(root->right, root->data, max_val)) 
        return true;
    
    return false;
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
    cout << root << endl;

    if(isBST(root)) 
        cout << "is BST" << endl;
    else 
        cout << "is not BST" << endl;

    return 0;
}