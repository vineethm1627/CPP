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

// linear search is the only option
bool searchList(node *head, int key) {
    while(head != NULL) {
        if(head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

// recursive search function
bool searchRecursive(node *head, int key) {
    if(head == NULL)
        return false;
    if(head->data == key)
        return true;
    else
        return searchRecursive(head->next, key);
    
}

// take user input
node* inputList() {
    int data;
    node *head = NULL;
    while(cin >> data) {
        insertAtTail(head, data);
    }
    return head;
}

int main() {

    node *head = inputList();
    printList(head);

    return 0;
}