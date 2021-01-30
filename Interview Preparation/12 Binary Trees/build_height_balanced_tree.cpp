/*
    given an array, build a height balanced binary tree.
    make the mid element of the array as the root node.
    recursively repeat the same for the left and right part of the array.
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
            
            // add the children of front if they exist
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
    }

}

node *buildTree(int *arr, int start, int end) {
    // base case
    if(start > end)
        return NULL;
    
    // recursive calls
    int mid = start + (end - start) / 2;
    // make mid element as the root node.
    node *root = new node(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);

    return root;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    node *root = buildTree(arr, 0, n - 1);
    BFS(root);

    return 0;
}