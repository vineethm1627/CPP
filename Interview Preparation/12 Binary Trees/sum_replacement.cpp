/*
    replace every node by the sum of its child(all descendants) nodes.
    leaf nodes stay as it is.
*/
/*
    O(n) solution for finding the diameter of the tree.
    bottom up traversal, postorder traversal
    we will store the height.
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

void BFS(node *root) {
    queue<node*> q;
    q.push(root);
    // for newline
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
            cout << front->data << " ";
            // add the child nodes if they exist
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
    }
}

int replaceSum(node *root) {
    if(root == NULL)
        return 0;
    
    // leaf node: no changes to be made
    if(root->left == NULL and root->right == NULL) 
        return root->data;
    
    // recursive post order traversal, for bottom-up filling
    int left_sum = replaceSum(root->left);
    int right_sum = replaceSum(root->right);

    // update the node with the sum of its child nodes
    int temp = root->data;
    root->data = left_sum + right_sum;
    // sum of the child nodes as well as the original value of the node
    return temp + root->data;
}

int main() {

    node *root = buildTree();

    BFS(root);
    cout << endl;
    replaceSum(root);
    BFS(root);

    return 0;
}