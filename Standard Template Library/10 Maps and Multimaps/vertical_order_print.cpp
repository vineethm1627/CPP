// vertical order print of a binary tree.
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
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

// passing map container by reference
void vertical_order(node *root, int d, map< int, vector<int> > &m) {
    // base case
    if(root == NULL)
        return;
    m[d].push_back(root->data);
    vertical_order(root->left, d - 1, m);
    vertical_order(root->right, d + 1, m);
    return;
}

int main() {

    /*
                            1
                          /   \
                         2     3
                        / \   / \
                       4   5 6   7
                            \     \
                             8     9
    */

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->left->right->right = new node(8);
    root->right->right->right = new node(9);

    // vertical_distance from root node line -> tree node values
    map< int, vector<int> > m;
    int d = 0;
    vertical_order(root, d, m);

    // maps are ordered so the keys are already sorted
    for(auto p : m) {
        cout << p.first << " => ";
        sort(p.second.begin(), p.second.end());
        for(int x : p.second)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
