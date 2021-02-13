/*
    Find the subarray with max xor value.
    create a cumulative xor array and perform max xor pair on that cumulative array.


    example: 
    arr = {3, 10, 4, 25, 2, 8}
    cum_arr = {3, 3^10, 3^10^4, 3^10^4^25, 3^10^4^25^2, 3^10^4^25^2^8}

    subarray_xor{index = 1, 4} = cum_arr[4] ^ cum_arr[1]
    = 3^10 ^ 3^10^4^25^2 = 10^4^25^2

*/
#include <iostream>
using namespace std;

// structure of Trie node
class node {
    public:
        node *left; // bit = 0
        node *right; // bit = 1
};

class Trie {
    node *root;

    public:
        Trie() {
            root = new node();
        }

        void cumulative_xor(int *arr, int n) {
            int result = 0;
            for(int i = 0; i < n; i++) {
                result = result ^ arr[i];
                arr[i] = result;
            }
        }

        void insert(int data) {
            node *curr = root;
            for(int i = 31; i >= 0; i--) {
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

        // max_xor that can be made with the current value
        int max_xor_helper(int data) {
            int curr_xor = 0;   
            node *curr = root;
            for(int j = 31; j >= 0; j--) {
                int bit = (data >> j) & 1;
                if(bit == 0) {
                    // move towards 1 ie right
                    if(curr->right) {
                        curr = curr->right;
                        // (1 << j) = pow(2, j)
                        curr_xor += (1 << j);
                    }
                    else 
                        curr = curr->left;
                }
                else {
                    // move towards 0 ie left
                    if(curr->left) {
                        curr = curr->left;
                        curr_xor += (1 << j);
                    }
                    else    
                        curr = curr->right;
                }
            }
            return curr_xor;
        } 

        int findMaxXor(int *arr, int n) {
            int max_xor = 0;
            for(int i = 0; i < n; i++) {
                insert(arr[i]);
                int curr_xor = max_xor_helper(arr[i]);
                max_xor = max(max_xor, curr_xor);
            }
            return max_xor;
        }
};
 
 
int main() {
    
    int n;
    cin >> n;

    Trie t;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    t.cumulative_xor(arr, n);
    
    cout << t.findMaxXor(arr, n) << endl;
 
    return 0;
}