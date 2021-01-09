// last node of the linked list points to the head of the linked list
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

void insertAtHead(node *&head, int data) {
    node *n = new node(data);
    node *temp = head;
    n->next = head;
    if(temp != NULL) {
        while(temp->next != head)
            temp = temp->next;
        
        temp->next = n; // last node now points to the first node
    }
    else {
        n->next = n; // self loop, insertion of the first node.
    }
    head = n; // update head to point to the new first node
}

// head pointer passed by value, changes won't be reflected outside the function
void printList(node *head) {
    node *temp = head;
    while(temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
}

// take user input from the console
node* inputList() {
    int data;
    cin >> data;
    node*head = NULL;
    
    while(data != -1) {
        insertAtHead(head, data);
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

int main() {
   
    node *head;
    cin >> head;

    cout << head;
    
    return 0;
}

