/*
    You will be given a Binary Tree. Your task is to print the binary tree in Vertical Fashion. The image below describes how we define a vertical traversal of a tree.
    Input Format
    You will be given an Integer N denoting the number of levels in the corresponding tree. On the next line you will be given (2^N)-1 integers denoting the level order input for the tree. If at any level any node is absent then that will denoted by -1 and every integer other than -1 shows the presence of a node at that level.
    Constraints
    1 <= N <= 10^5
    Output Format
    Print all nodes of a given column in the same line.
    Image
    Sample Input
    4 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
    Sample Output
    4
    2
    1 5 6
    3 8 
    7
    9
    Explanation
    We are to simply print the traversal of each vertical level from left to right.
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define mvi map<int, vector<int>>

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

node* buildTreeLevelWise() {
    int data;
    cin >> data;

    node *root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node *front = q.front();
        q.pop();

        int child1, child2;
        cin >> child1 >> child2;

        if(child1 != -1) {
            front->left = new node(child1);
            q.push(front->left);
        }

        if(child2 != -1) {
            front->right = new node(child2);
            q.push(front->right);
        }
    }
    return root;
}

// map {horizontal distance from root node}
// preorder traversal
void verticalPrint(node *root, mvi &m, int distance = 0) {
    if(root == NULL)
        return;
    
    m[distance].push_back(root->data);
    verticalPrint(root->left, m, distance - 1);
    verticalPrint(root->right, m, distance + 1);
}

int main() {
    node *root = buildTreeLevelWise();

    mvi m;

    verticalPrint(root, m);

    for(auto it : m) {
        for(auto x : it.second) 
            cout << x << " ";
        cout << endl;
    }
    return 0;
}