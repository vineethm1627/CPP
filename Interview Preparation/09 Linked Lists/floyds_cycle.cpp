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

bool detectCycle(node *head) {
    node *slow = head;
    node *fast = head;

    while(fast != NULL and fast->next != NULL) {
        fast = fast->next->next; // 2 steps
        slow = slow->next; // 1 step

        // cycle detected
        if(fast == slow) {
            removeCycle(fast, head);
            return true;
        }
    }
    return false;
}

void removeLoop(node *fast, node *head) {
    node *slow = head;
    // if both fast and slow are at the head.
    // moving both of them will lead to error.
    // hence move the fast pointer only.
    if(slow == fast) {
        while(fast->next != slow)
            fast = fast->next;
    }
    else {
        while(slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    // fast->next is the beginning of the loop
    fast->next = NULL; // break the link leading to cycle.
}

int main() {
   
    node *head;
    cin >> head;
    cout << "original list: " << head;

    return 0;
}

