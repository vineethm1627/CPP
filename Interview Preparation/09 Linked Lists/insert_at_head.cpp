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

// head pointer passed by value, changes won't be reflected outside the function
void printList(node *head) {
    while(head != NULL) {
        cout << head-> data << " ";
        head = head->next;
    }
}

int main() {

    node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
  
    printList(head);
    cout << endl;
    printList(head); // will result in the same output as head pointer was passed by reference.
    return 0;
}