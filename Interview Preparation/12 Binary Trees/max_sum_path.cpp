/*
    find max sum from any node to any node in a given binary tree.

    there could be 3 cases:
        the path crosses through root
        the path lies in left subtree
        the path lies in right subtree
    
    to find the max sum there could be 4 options
        root->data
        root->data + left_sum
        root->data + right_sum
        root->data + left_sum + right_sum
    
    at every node return 2 things
        max path sum through that node as root which covers the above 4 cases
        branch sum through that node (used for extension) --> left_sum, right_sum

    this branch sum is used to build up the cumulative sum from bottom to top.
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

class Pair {
    public:
        int max_sum;
        int branch_sum;

        Pair() {
            max_sum = 0;
            branch_sum = 0;
        }
};

Pair maxSumPath(node *root) {
    Pair p;
    // base case
    if(root == NULL)
        return p;
    
    // recursive calls
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    // construct the 4 options for max sum through the root ie case1
    int option1 = root->data;
    int option2 = root->data + left.branch_sum;
    int option3 = root->data + right.branch_sum;
    int option4 = root->data + left.branch_sum + right.branch_sum;

    int max_sum_thru_root = max(option1, max(option2, max(option3, option4)));

    // branch sum, if the left and right branch sum are negative then drop them and consider root only
    p.branch_sum = max(0, max(left.branch_sum, right.branch_sum)) + root->data;

    /* 
    max sum has 3 options :
        through root which is computed above
        part of left subtree
        part of right subtree
    */
    p.max_sum = max(max_sum_thru_root, max(left.max_sum, right.max_sum));
    
    return p;
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

    Pair result = maxSumPath(root);
    cout << "max sum : " << result.max_sum << endl;
    return 0;
}