#include <iostream>
#include <queue>
#include <stack>
#include <map>
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

class Tree {
    node *root;

    public:
        Tree() {
            root = NULL;
        }

        void buildTreeLevelWise() {  
            int data;
            cin >> data;

            root = new node(data);
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
        }

        void bottomView() {
            if(root == NULL)
                return;
            
            map<int, int> m; // {distance, node->data}
            queue<pair<node*, int>> q; // {node, horizontal distance from root node}

            q.push(make_pair(root, 0));

            while(!q.empty()) {
                node *front = q.front().first;
                int distance = q.front().second;
                q.pop();

                m[distance] = front->data;
                if(front->left)
                    q.push(make_pair(front->left, distance - 1));
                
                if(front->right)
                    q.push(make_pair(front->right, distance + 1));
            }

            for(auto p : m) 
                cout << p.second << " ";
        }

        void inorder_rec(node *root) {
            if(root == NULL)
                return;
            
            inorder_rec(root->left);
            cout << root->data << " ";
            inorder_rec(root->right);
        }

        void inorder_rec() {
            inorder_rec(root);
        }

        void inorder_iter(node *root) {
            stack<node*> s;
            node *curr = root;

            while(curr != NULL or !s.empty()) {
                // reach the left most node
                while(curr != NULL) {
                    s.push(curr);
                    curr = curr->left;
                }

                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                curr = curr->right;
            }
        }

        void inorder_iter() {
            inorder_iter(root);
        }
};



int main() {

    Tree t;
    t.buildTreeLevelWise();
    t.bottomView();
    cout << endl;
    t.inorder_rec();
    cout << endl;
    t.inorder_iter();



    return 0;
}