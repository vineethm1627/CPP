/*
    Breadth First Search (BFS) makes use of queue data structure.
    Takes O(n) time.

    insert the root in the queue.
    pop the first element and insert its children in the queue.

    keep repeating the above step.

    added newline

    input: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    output:
        BFS: 
        8    
        10 3
        1 6 14
        9 7 13
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
    // push NULL to indicate the need of newline
    // NULL implies all the children of the previous level are popped out.
    // It also implies all the nodes of the next level are currently in the queue.
    q.push(NULL);

    while(!q.empty()) {
        node *front = q.front();
        if(front == NULL) {
            cout << endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else {
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
}

int main() {
   
    node *root = buildTree();
    cout << "BFS: " << endl;
    BFS(root);

    return 0;
}