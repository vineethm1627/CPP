/*
    Merge sort is a divide and conquer algorithm.
    It divides the input array into 2 halves and then merges the 2 sorted halves.

    Time complexity = O(nlogn)
*/
#include <iostream>
using namespace std;
 
class node {
    public:
        int data;
        node *next;
 
        node(int data) {
            this->data = data;
            next = NULL;
        }
};

// head is passed by reference
void insertAtTail(node *&head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }

    node *tail = head;
    // reach the last node
    while(tail->next != NULL)
        tail = tail->next;
    
    tail->next = new node(data);
}
 
void printList(node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

node* inputList() {
    int data;
    cin >> data;

    node *head = NULL;
    while(data != -1) {
        insertAtTail(head, data);
        cin >> data;
    }
    return head;
} 

node* midpoint(node *head) {
    if(head == NULL or head->next == NULL)
        return head;
    
    node *slow = head;
    node *fast = head->next; // the larger midpoint

    while(fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node *left, node *right) {
    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    
    node *complete;
    if(left->data <= right->data) {
        complete = left;
        complete->next = merge(left->next, right);
    }
    else {
        complete = right;
        complete->next = merge(left, right->next);
    }
    return complete;
}

node* mergeSort(node *head) {
    if(head == NULL or head->next == NULL)
        return head;
    
    // divide the list into 2 parts
    node *mid = midpoint(head);

    node *left = head; // first part
    node *right = mid->next; // second part
    // break the link between these two
    mid->next = NULL;

    // recursively sort the parts
    left = mergeSort(left);
    right = mergeSort(right);

    // merge the 2 sorted parts
    node *complete = merge(left, right);
    
    return complete;
}

ostream& operator<<(ostream &cout, node *head) {
    printList(head);
    cout << endl;
    return cout;
}

istream& operator>>(istream &cin, node *&head) {
    head = inputList();
    return cin;
}

int main() {

    node *head;
    cin >> head;
    cout << "original list: " << head;
    head = mergeSort(head);
    cout << "sorted list: " << head;
 
    return 0;
}