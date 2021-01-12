/*
    Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

    Example 1:

    Input:
    LinkedList1: 9->6->4->2->3->8
    LinkedList2: 1->2->8->6
    Output: 6 2 8
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

void push(Node *&head, int data) {
    if(head == NULL) {
        Node *n = new Node(data);
        head = n;
        return;
    }
    
    Node *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = new Node(data);
}

Node* findIntersection(Node* head1, Node* head2) {
    unordered_set<int> s;
    while(head2 != NULL) {
        s.insert(head2->data);
        head2 = head2->next;
    }
    
    Node *start = NULL;
    Node *end = NULL;
    
    while(head1 != NULL) {
        if(s.find(head1->data) != s.end()) {
            if(start == NULL)
                start = end = head1;
            else {
                end->next = head1;
                end = head1;
            }
        }
        head1 = head1->next;
    }
    if(start != NULL)
        end->next = NULL;
    
    return start;
}