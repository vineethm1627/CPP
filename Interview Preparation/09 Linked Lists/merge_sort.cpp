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

void insertAtTail(node *&head, int data) {

    if(head == NULL) {
        head = new node(data);
        return;
    }
    node *tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new node(data);
}



// head pointer passed by value, changes won't be reflected outside the function
void printList(node *head) {
    while(head != NULL) {
        cout << head-> data << " ";
        head = head->next;
    }
}

// take user input from the console
node* inputList() {
    int data;
    cin >> data;
    node*head = NULL;
    
    while(data != -1) {
        insertAtTail(head, data);
        cin >> data;
    }
    return head;
}

// operator overloading to print the linked list.
// ostream --> cout
ostream& operator<<(ostream &cout, node *head) {
    printList(head);
    cout << endl;
    return cout;
}

// operator overloading to input a linked list
// istream --> cin
istream& operator>>(istream &cin, node *&head) {
    head = inputList();
    return cin;
}

// midpoint of the list
node* midpoint(node *head) {
    // base case
    if(head == NULL or head->next == NULL)
        return head;
    node *slow = head;
    node *fast = head->next;

    while(fast != NULL and fast->next != NULL) {
        fast = fast->next->next; // 2 steps
        slow = slow->next; // 1 step
    }
    return slow;
}

node* merge(node *a, node *b) {
    // base case
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    
    // head pointer
    node *c;
    if(a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

// divide the list into 2 parts
// recursive sort the 2 lists
// merge the 2 sorted lists
node* mergeSort(node *head) {
    // base case
    if(head == NULL or head->next == NULL)
        return head;
    
    // 1. divide the list into 2 parts
    node *mid = midpoint(head);

    node *a = head; // first/left part
    node *b = mid->next; // second/right part

    mid->next = NULL; // break the link between the 2 parts

    // 2. recursively sort the 2 parts
    a = mergeSort(a);
    b = mergeSort(b);

    // 3. merge the 2 sorted lists
    node *c = merge(a, b);

    return c; // return the merged sorted list
}

int main() {
   
    node *head;
    cin >> head;
    cout << "original list: " << head;
    head = mergeSort(head);
    cout << "sorted list: " << head;

    return 0;
}

