/*
Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

Input Format
Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.

Constraints
1 <= Nodes in tree <=1000
1<K<10

Output Format
A single line containing the sum at level K.

Sample Input
1 2
2 2
3 0
4 0
5 2
6 0
7 0
2

Sample Output
20

Explanation
Here the tree looks like

                     1                                 Level 0
                /          \
              2              5                         Level 1
           /      \       /     \
          3       4      6        7                    Level 2
Sum at Level 2 = 3 + 4 + 6 + 7 = 20

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

node *buildTree(node *root) {
	int data, children;
	cin >> data >> children;

	root = new node(data);
	if(children == 0)
		return root;
	else if(children == 1) {
		root->left = buildTree(root->left); 
		return root;
	}
	else {
		root->left = buildTree(root->left);
		root->right = buildTree(root->right);
		return root;
	}
}

int sumAtLevelK(node *root, int k) {
	if(root == NULL)
		return 0;
	
	int sum = 0;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	bool flag = false;

	while(!q.empty()) {
		node *front = q.front();
		q.pop();

		if(front == NULL) {
			k--;
			if(!q.empty())
				q.push(NULL);
			
			if(flag == true)
				break;
			
			if(k == 0)
				flag = true;
		}
		else {
			if(flag == true)
				sum += front->data;
			if(front->left)
				q.push(front->left);
			if(front->right)
				q.push(front->right);
		}
	}
	return sum;
}

int main() {

	node *root = NULL;
	root = buildTree(root);
	int k;
	cin >> k;
	cout << sumAtLevelK(root, k) << endl;

	return 0;
}