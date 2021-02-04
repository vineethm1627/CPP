/*
    Given an unsorted linked list of integers. The task is to sort the list in a wave like form.
    list[0] >= list1 <= list[2] ...

    input: 3 6 5 10 7 20
    output: 6 3 10 5 20 7
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

void printList(node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int lengthOfList(node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

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
    while(tail->next != NULL) 
        tail = tail->next;
    
    tail->next = new node(data);
}

void insertAtMiddle(node *&head, int data, int pos) {
    if(head == NULL or pos == 0)
        insertAtHead(head, data);
    else if(pos > lengthOfList(head))
        insertAtTail(head, data);
    else {
        // take p - 1 jumps from the head node
        node *ptr = head;
        for(int i = 1; i <= pos - 1; i++)
            ptr = ptr->next;
        
        node *temp = new node(data);
        temp->next = ptr->next;
        ptr->next = temp;
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

ostream& operator<<(ostream &cout, node *head) {
    printList(head);
    return cout;
}

istream& operator>>(istream &cin, node *&head) {
    head = inputList();
    return cin;
} 

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void waveSort(node *head) {
    node *prev = NULL;
    node *curr = head;

    int pos = 0;
    int n = lengthOfList(head);
    while(pos < n) {
        if(pos % 2 == 0) {
            if(pos > 0 && (curr->data < prev->data))
                swap(&(curr->data), &(prev->data));
            
            if(pos < n - 1 && (curr->data < curr->next->data)) 
                swap(&(curr->data), &(curr->next->data));
        }
        pos++;
        prev = curr;
        curr = curr->next;
    }
}

int main() {

    node *head = NULL;
    cin >> head;

    waveSort(head);
    cout << head;

    return 0;
}