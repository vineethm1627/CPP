/*
    shortest distance between 2 nodes.
    The path always roots at the Lowest Common Ancestor

    approach-1:
        find path of node a
        find path of node b
        find path of LCA of (a,b)
        ans = len(path_a) + len(path_b) - 2*common_path
        ans = len(path_a) + len(path_b) - 2*len(path_LCA)

        Path of LCA is the common path for both the nodes a and b.
    
    approach-2:
        find LCA
        find path from LCA to node a
        find path from LCA to node b
        add the 2 path lengths

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

node* LCA(node *root, int a, int b) {
    // base case
    if(root == NULL)
        return NULL;
    
    if(root->data == a or root->data == b)
        return root;
    
    // recursive calls
    node *left = LCA(root->left, a, b);
    node *right = LCA(root->right, a, b);

    // root is the LCA
    if(left != NULL and right != NULL) 
        return root;
    
    if(left != NULL)
        return left;
    
    return right;
}

// search for a given node and return its level
// finding the level of a given node from the root node/ any given node.
int search(node *root, int key, int level) {    
    // base case
    if(root == NULL)
        return -1; // indicates the node is not found
    
    if(root->data == key)
        return level;
    
    // recursive calls
    int left = search(root->left, key, level + 1);
    if(left != -1) {
        // the key node is found
        return left;
    }
    
    return search(root->right, key, level + 1);
}

// function to find shortest distance between 2 nodes
int findDistance(node *root, int a, int b) {
    node *LCA_node = LCA(root, a, b);

    int l1 = search(LCA_node, a, 0);
    int l2 = search(LCA_node, b, 0);

    return l1 + l2;
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

    cout << "min distance btw a and b: " << findDistance(root, a, b) << endl;

    return 0;
}

