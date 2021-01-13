// reverse a stack using 1 stack only.
#include <iostream>
#include <stack>
using namespace std;

// stack container passed by value, changes won't be reflected.
void print(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void insertAtBottom(stack<int> &s, int x) {
    // base case
    if(s.empty()) {
        s.push(x);
        return;
    }

    // recursive case
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

// passed by reference, changes will be reflected.
void reverseStack_recursive(stack<int> &s) {
   // base case
    if(s.empty())
        return;

    // pop the top element and insert it at the bottom of the reversed smaller stack.
    int x = s.top();
    s.pop();

    // recursively reverse the smaller stack
    reverseStack_recursive(s);
    insertAtBottom(s, x);
}

int main() {

    stack<int> s;
    for(int i = 1; i <= 5; i++)
        s.push(i);

    cout << "original stack: ";
    print(s);
    cout << "\nreversed stack: ";
    reverseStack_recursive(s);
    print(s);

    return 0;
}