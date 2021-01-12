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

void transfer(stack<int> &s1, stack<int> &s2, int n) {
    for(int i = 0; i < n; i++) {
        s2.push(s1.top());
        s1.pop();
    }
}

// passed by reference, changes will be reflected.
void reverseStack(stack<int> &s1) {
    // helper stack
    stack<int> s2;
    int n = s1.size();

    for(int i = 0; i < n; i++) {
        // pick the top element and insert at the bottom
        int x = s1.top();
        s1.pop();
        // transfer n-i-1 elements from stack s1 -> s2
        transfer(s1, s2, n - i - 1);
        // insert the x at the bottom of s1
        s1.push(x);
        // transfer n-i-1 elements from stack s2 -> s1
        transfer(s2, s1, n - i - 1);
    }
}

int main() {

    stack<int> s;
    for(int i = 1; i <= 5; i++)
        s.push(i);

    cout << "original stack: ";
    print(s);
    cout << "\nreversed stack: ";
    reverseStack(s);
    print(s);

    return 0;
}