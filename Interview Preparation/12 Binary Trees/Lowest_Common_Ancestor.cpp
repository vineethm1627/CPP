
/*
    find the ancestor node that is common to both the nodes
    the node from which you can reach both the nodes in the shortest possible way.
    The node can itself be the ancestor/descendant of itself.


    one approach:
        find the path to reach both the nodes from the root node.
        print out the last common element, this would be the Least common ancestor.

    For the node to be LCA, one node should lie on the left subtree, other should lie in the right subtree
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

// preorder build of the tree
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
    if(root == NULL)
        return;
    
    queue<node*> q;
    q.push(root);
    // for the newline
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
            // insert the children of front in the queue if they exist
            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);
        }
    }
}

node *LCA(node *root, int a, int b) {
    // base case
    if(root == NULL)
        return NULL;
    
    // a node is its ancestor
    if(root->data == a or root->data == b) 
        return root;

    // search in the left and right subtrees
    node *left = LCA(root->left, a, b);
    node *right = LCA(root->right, a, b);

    // root is the LCA
    if(left != NULL and right != NULL)
        return root;
    
    if(left != NULL)
        return left;
    
    return right;
    
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

    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << LCA(root, a, b) << endl;

    return 0;
}

