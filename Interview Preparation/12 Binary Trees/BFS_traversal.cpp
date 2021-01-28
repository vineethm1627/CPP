/*
    Breadth First Search (BFS) makes use of queue data structure.
    Takes O(n) time.

    insert the root in the queue.
    pop the first element and insert its children in the queue.

    keep repeating the above step.
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

void BFS(node *root) {
    queue<node*> q;
    // push the root in the queue
    q.push(root);

    while(!q.empty()) {
        node *front = q.front();
        q.pop();
        // display the data
        cout << front->data << " ";
        // push the children into the queue if they exist
        // push the left child
        if(front->left)
            q.push(front->left);
        // push the right child
        if(front->right)
            q.push(front->right);
    }
}

int main() {
   
    node *root = buildTree();
    cout << "BFS: " << endl;
    BFS(root);

    return 0;
}