/*
    build a binary tree from inorder and pre order traversal.

    Note: 
        for a (preorder + inorder) and (postorder + inorder) there exists a unique Binary Tree.

        Steps:
            1) iteratively pick one element from preorder array and create a node
            2) search for the index of this element in inorder array
            3) make recursive call on left and right subtree
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

// static variable will traverse the pre-order array
node* createTreefromTraversal(int *in, int *pre, int start, int end) {
    static int i = 0; // static variables are initialized only once
    // base case
    if(start > end)
        return NULL;

    // recursive calls
    node *root = new node(pre[i]);

    // search for the index in the in-order array
    int index = -1;
    for(int j = start; j <= end; j++) {
        if(in[j] == pre[i]) {
            index = j;
            break;
        }
    }
    i++; // increment the pointer index in pre-order array
    root->left = createTreefromTraversal(in, pre, start, index - 1);
    root->right = createTreefromTraversal(in, pre, index + 1, end);

    return root;
}

// LNR
void inorder(node *root) {
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right); 
}

// NLR
void preorder(node *root) {
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {

    // NLR
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    // LNR
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int n = sizeof(in) / sizeof(int);

    node *root = createTreefromTraversal(in, pre, 0, n - 1);
    BFS(root);
    cout << endl;
    cout << "preorder: ";
    preorder(root);
    cout << endl;
    cout << "inorder: ";
    inorder(root);

    return 0;
}
