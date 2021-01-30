/*
    print right view of the binary tree.
    ie. if you view the tree from the right what nodes are visible.

    1) In BFS print the rightmost element at each level.
    else
    Logic: there is only one node to be printed at each level
    2) NRL traversal + maintain the deepest level traversed till now.
    
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

void BFS(node *root) {
    if(root == NULL)
        return;
    
    queue<node*> q;
    q.push(root);
    // newline
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

// max_level is passed by reference.
void rightView(node *root, int level, int &max_level) {
    if(root == NULL)
        return;
    
    if(level > max_level) {
        // we have discovered rightmost node in the next new level
        cout << root->data << " ";
        max_level = level;
    }
    // recursive calls
    // right 
    rightView(root->right, level + 1, max_level);
    // left
    rightView(root->left, level + 1, max_level);
}

// operator overloading cin
istream& operator>>(istream &cin, node *&root) {
    root = buildTree();
    return cin;
}

// operator overloading cout
ostream& operator<<(ostream &cout, node *root) {
    BFS(root);
    return cout;
}


int main() { 

    node *root = NULL;
    cin >> root;
    cout << root;
    // root = buildTree();

    // BFS(root);

    int max_level = -1;
    rightView(root, 0, max_level);


    return 0;
}