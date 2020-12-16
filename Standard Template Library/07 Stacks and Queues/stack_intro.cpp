#include <iostream>
#include <stack>
using namespace std;

/*
    LIFO : Last In First Out
    used in PDA (Push Down Automata)
    Elements can be inserted at only one end ie the top
    push and pop can take O(1) time.

    A stack can be implemented using arrays, vectors, linked list and dynamic array.
    various common operations on stack are :
        1) push
        2) pop
        3) top --> peek / look at the element on the top without removing it.
        4) empty --> to check the stack is empty or not
    
    There is no concept of indexing in stack.
*/

int main() {

    stack<int> s;
    for(int i = 1; i <= 5; i++) {
        s.push(i);
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}