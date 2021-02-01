/*
    building a BST.
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

    inorder(root); // will receive the sorted output
    cout << endl;
    cout << root;

    return 0;
}