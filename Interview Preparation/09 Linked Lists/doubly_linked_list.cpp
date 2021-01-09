#include <iostream>
using namespace std;

template <class T>
class node {
    public:
        T data;
        node *next;
        node *prev;

        node(T data) {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

int main() {

    node<int> *head = new node<int>(1);
    
    cout << head->data << endl;

    return 0;
}