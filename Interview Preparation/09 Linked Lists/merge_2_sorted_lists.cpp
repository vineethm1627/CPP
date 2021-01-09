/*
    midpoint of the linked list, ie the middle node in a single iteration
    1 2 3 4, node 2 will be the middle node
    1 2 3 4 5, node 3 is the middle node

    fast and slow pointer,
    fast will take 2 steps and slow will take 1 step.

    fast = 2x slow
*/
/*
    overload << and >>.

    cin >> head; // insert at the tail of the linked list
    cout << head; // print entire linked list
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

// length of the linked list
// head pointer passed by value
int lengthOfList(node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// for interview purpose, we will define separate functions ie. procedural programming
// head pointer is passed by reference, updating head will reflect in the actual changes.
void insertAtHead(node *&head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp; 
}

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

// insert at index 'pos' in the linked list
void insertInMiddle(node *&head, int data, int pos) {
    // if position = 0, insert at head, if p > length of list, insert at the index.
    // corner cases
    if(head == NULL or pos == 0) 
        insertAtHead(head, data);
    else if(pos > lengthOfList(head)) 
        insertAtTail(head, data);
    else {
        // take p - 1 jumps from the head node.
        node *ptr = head;
        for(int i = 1; i <= pos - 1; i++)
            ptr = ptr->next;
        
        node *temp = new node(data);
        temp->next = ptr->next;
        ptr->next = temp;
    }
}


// head pointer passed by value, changes won't be reflected outside the function
void printList(node *head) {
    while(head != NULL) {
        cout << head-> data << " ";
        head = head->next;
    }
}

// linear search is the only option
bool searchList(node *head, int key) {
    while(head != NULL) {
        if(head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

// take user input from input text file.
node* inputFile() {
    int data;
    node *head = NULL;

    while(cin >> data) {
        insertAtTail(head, data);
    }
    return head;
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

node *merge(node *a, node *b) {
    // base case
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    // take a head pointer
    node *c;
    if(a->data < b->data) {
        c = a;
        // c->next will point to the sorted linked list
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main() {
   
    node *head1, *head2;
    cin >> head1 >> head2;

    cout << head1 << head2;
    head1 = merge(head1, head2);

    cout << head1;

    return 0;
}

