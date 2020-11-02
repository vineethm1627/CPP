#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void printList(Node *head) {
    if(head == NULL) return;
    Node *curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *reverseList(Node *head) {
    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL) {
        Node *n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head = reverseList(head);
    printList(head);
    return 0;
}
