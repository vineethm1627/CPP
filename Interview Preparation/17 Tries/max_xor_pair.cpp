/*
    Given an array of n integers, find the max bitwise xor from all possible pairs in the array.

    input: 25 10 2 8 5 3
    output: 28
    explanation: 5^25 = 28

    input: 1 2 3 4 5 6 7
    output: 7
    explanation: 1^6 = 7
*/
#include <iostream>
#include <cmath>
using namespace std;

// structure of Trie node
class node {
    public:
        node *left; // bit = 0
        node *right; // bit = 1
};
 
void insert(node *root, int data) {
    node *curr = root;
    for(int i = 31; i >= 0; i--) {
        // find the ith bit
        int bit = (data >> i) & 1;
        if(bit == 0) {
            if(!curr->left) 
                curr->left = new node();
            curr = curr->left;
        } 
        else {
            if(!curr->right)
                curr->right = new node();
            curr = curr->right;
        }
    }
} 
 
int findMaxXor(node *root, int *arr, int n) {
    int max_xor = 0;
    for(int i = 0; i < n; i++) {
        int value = arr[i];
        node *curr = root; 
        int curr_xor = 0;
        for(int j = 31; j >= 0; j--) {
            int bit = (value >> j) & 1;
            if(bit == 0) {
                // move towards 1 ie right
                if(curr->right) {
                    curr = curr->right;
                    curr_xor += pow(2, j);
                }
                else 
                    curr = curr->left;
            }
            else {
                // move towards 0 ie left
                if(curr->left) {
                    curr = curr->left;
                    curr_xor += pow(2, j);
                }
                else 
                    curr = curr->right;
            }
        }
        max_xor = max(max_xor, curr_xor);
    }
    return max_xor;
}

node* buildTrie(int *arr, int n) {
    node *root = new node();
    for(int i = 0; i < n; i++)
        insert(root, arr[i]);
    
    return root;
}

int main() {
    
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    node *root = buildTrie(arr, n);

    cout << "max xor pair: " << findMaxXor(root, arr, n) << endl;
 
    return 0;
}