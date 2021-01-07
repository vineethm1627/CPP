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

void deleteHead(node *&head) {
    if(head == NULL)
        return;
    node *temp = head;
    head = head->next; 
    delete temp;
}

void deleteTail(node *&head) {
    if(head == NULL)
        return;
    // loop to reach the second last node
    if(head->next == NULL) {
        head = NULL;
    }
    node *ptr = head;
    while(ptr->next->next != NULL)
        ptr = ptr->next;
    delete(ptr->next);
    ptr->next = NULL;
}

// delete element at the index 'pos' in the linked list
void deleteInMiddle(node *&head, int pos) {
    if(head == NULL or pos == 0) 
        deleteHead(head);
    else if(pos > lengthOfList(head))
        deleteTail(head);
    else {
        // take p-1 jumps to reach the previous node
        node *prev = head;
        for(int i = 1; i <= pos - 1; i++)
            prev = prev->next;

        node *temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
}

// head pointer passed by value, changes won't be reflected outside the function
void printList(node *head) {
    while(head != NULL) {
        cout << head-> data << " ";
        head = head->next;
    }
}

int main() {

    node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    // insertInMiddle(head, 0, 0);
    // insertInMiddle(head, 4, 3);
    // insertInMiddle(head, 3, 3);
    // insertInMiddle(head, 6, 6);
    // insertAtTail(head, 7);

    printList(head);
    cout << endl;
    // deleteHead(head);
    // deleteTail(head);
    // deleteTail(head);
    insertInMiddle(head, 100, 0);
    deleteInMiddle(head, 3);
    deleteInMiddle(head, 1);
    printList(head);
   
    return 0;
}