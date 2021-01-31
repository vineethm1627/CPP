/*
    find all the nodes at a distance k from the given target node.
    K distance can be in both the upward and downward and left and right sides.

    we need to find out the ancestors of the target node.
    nodes at a distance K - 2 - d(from the previous root node) in the other side of the tree

    input: 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
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

// print the children at a distance from the target node, downside.
void printAtLevelK(node *root, int k) {
    if(root == NULL)
        return;
    
    if(k == 0) {
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}

// main function to take into account ancestors
// from every node return the distance of the target node from that node
int printAtDistanceK(node *root, node *target, int k) {
    // base case
    if(root == NULL)
        return -1;
    
    // reach the target node
    if(root == target) {
        // print the children in the subtrees of this target node.
        printAtLevelK(target, k);
        return 0;
    }
    
    // traverse the ancestor nodes
    int dist_left = printAtDistanceK(root->left, target, k);
    // if target is present in the left subtree
    if(dist_left != -1) {
        /* now there are 2 cases:
            1. print the ancestor
            2. you need to go to the right subtree of the ancestor
        */
        if(dist_left + 1 == k) 
            cout << root->data << " ";
        else {
            printAtLevelK(root->right, k - 2 - dist_left);
        }
        return 1 + dist_left;
    }
    
    int dist_right = printAtDistanceK(root->right, target, k);
    // if target is present in the right subtree
    if(dist_right != -1) {
        if(dist_right + 1 == k)
            cout << root->data << " ";
        // go to the left subtree of the ancestor
        else {
            printAtLevelK(root->left, k - 2 - dist_right);
        }
        return 1 + dist_right;
    }
    // target node was not present in the left and right subtree of the given node.
    return -1; 
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
    
    node *target = root->left->left;

    cout << root << endl;

    int k;
    cin >> k;

    printAtDistanceK(root, target, k);

    return 0;
}