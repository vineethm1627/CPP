/*
    flatten a BST into a sorted linked list (linear data structure)
    reuse the same nodes with creating a new linked list.
    ie. change the tree pointers

    every node will return the head and the tail pointers of the linked list constructed through that subtree(node included)

    there are 4 cases:
        root node could become the part of linked list
        root node could become the head if left subtree doesn't exist
        root node could become the tail if right subtree doesn't exist
        root node could become both head and tail if it is the leaf node.

    we do a postorder traversal, LRN
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

// print tree, level by level
void BFS(node *root) {
    if(root == NULL)
        return;
    
    queue<node*> q;
    q.push(root);
    // for newline
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
            // push the children of front if they exist
            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);
        }
    }
}

// accepts the old root node and returns the new root node
node* insert(node *root, int data) {
    // base case
    if(root == NULL)
        return new node(data);
    
    // recursive calls
    if(data <= root->data) 
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

node* build() {
    // read a list of numbers till -1 and insert them into BST
    int data;
    cin >> data;

    node *root = NULL;
    while(data != -1) {
        root = insert(root, data);
        cin >> data;
    }
    return root;
}

class LinkedList {
    public:
        node *head;
        node *tail;
};

LinkedList flatten(node *root) {
    LinkedList ll;

    // base case
    if(root == NULL) {
        ll.head = ll.tail = NULL;
        return ll;
    }

    // case-1: leaf node
    if(root->left == NULL and root->right == NULL) {
        ll.head = ll.tail = root;
        return ll;
    }

    // case-2: left is not null and right is null
    if(root->left != NULL and root->right == NULL) {
        // convert left subtree into linked list
        LinkedList left = flatten(root->left);
        // connect tail of the subtree with the root node
        left.tail->right = root;
        // update the tail to be the root node
        ll.tail = root;
        // update the head which will be the head of the left subtree
        ll.head = left.head;

        return ll;
    }
    // case-3: right is not null and left is not null
    else if(root->left == NULL and root->right != NULL) {
        // convert the right subtree into linked list
        LinkedList right = flatten(root->right);
        // make root point to the head of the right linked list
        root->right = right.head;
        // update the head to be the root node
        ll.head = root;
        // update the tail to be the tail node of the right subtree
        ll.tail = right.tail;
        
        return ll;
    }
    // case-4: both sides are not null
    else {
        // do a postorder traversal: LRN
        // convert left subtree into linked list
        LinkedList left =  flatten(root->left);
        // convert right subtree into linked list
        LinkedList right = flatten(root->right);

        // make tail of left linked list point to root
        left.tail->right = root;

        // make root point to the head of the right linked list
        root->right = right.head;

        // update the head to be the head of the left linked list
        ll.head = left.head;
        // update the tail to be the tail of the right linked list
        ll.tail = right.tail;

        return ll;
    }

}

istream& operator>>(istream& cin, node *&root) {
    root = build();
    return cin;
}

ostream& operator<<(ostream& cout, node *root) {
    BFS(root);
    return cout;
}

int main() {

    node *root = NULL;
    cin >> root;
    cout << "original tree: " << endl;
    cout << root << endl;
    LinkedList ll = flatten(root);

    node *temp = ll.head;
    cout << "sorted linked list: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    return 0;
}