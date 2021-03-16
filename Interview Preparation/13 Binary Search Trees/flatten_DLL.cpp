/*
    Problem link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
//Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class LinkedList {
    public:
        Node *head;
        Node *tail;
};

class Solution {
    public:    
    
    // every node will return the head and tail pointers of the linked list constructed.
    LinkedList flatten(Node *root) {
        LinkedList dll;
        
        // base case
        if(!root) {
            dll.head = dll.tail = NULL;
            return dll;
        }
        
        // case 1: leaf node
        if(!root->left and !root->right) {
            dll.head = dll.tail = root;
            return dll;
        }
        // case 2: only left subtree exists
        else if(root->left and !root->right) {
            // convert left subtree into linked list
            LinkedList left = flatten(root->left);
            // connect the tail of the subtree with the root node
            left.tail->right = root;
            root->left = left.tail;
            // update the tail to be the root node
            dll.tail = root;
            // update the head which will be the head of the left subtree
            dll.head = left.head;
            return dll;
        }
        // case 3: only right subtree exists
        else if(!root->left and root->right) {
            // convert the right subtree into linked list
            LinkedList right = flatten(root->right);
            // make the root point to the head of the right linked list
            root->right = right.head;
            right.head->left = root;
            // update the head to be the root node
            dll.head = root;
            // update the tail to be the tail of the right subtree
            dll.tail = right.tail;
            return dll;
        }
        // case 4: both subtrees exist
        else {
            // do a post order traversal LRN
            // convert left subtree into linked list
            LinkedList left = flatten(root->left);
            // convert right subtree into linked list
            LinkedList right = flatten(root->right);
            // make tail of the left linked list point to root node
            left.tail->right = root;
            root->left = left.tail;
            // make the root point to the head of the right linked list
            root->right = right.head;
            right.head->left = root;
            // update the head to be the head of the left linked list
            dll.head = left.head;
            // update the tail to be the tail of the right linked list
            dll.tail = right.tail;
            return dll;
        }
    }
    
    Node * bToDLL(Node *root) {
        LinkedList dll = flatten(root);
        return dll.head;
    }
};

/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}

int main()
{
  int t;
  cin >> t;
  getchar();
  
  while (t--)
  {
     string inp;
     getline(cin, inp);
     Node *root = buildTree(inp);
     
     Solution ob; 
     Node *head = ob.bToDLL(root);
     printList(head);

  }
  return 0;
}