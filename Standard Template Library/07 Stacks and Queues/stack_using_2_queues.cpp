/*
    implement stack data structure using 2 queues.

    struct stack {
        queue q1, q2;
    }

    we need to implement the functionality of LIFO using 2 queues.

    push --> O(1)store the element in the non-empty queue.
    pop --> O(n) move n-1 elements into empty queue and pop the last element.
    top --> O(n) move n-1 elements into empty queue and push the last element in the other queue.
    empty --> O(1)

    time complexity of push and pop can be interchanged
    if while pushing we juggle the elements between 2 queues.
*/
#include <iostream>
#include <queue>
using namespace std;

template<class T>
class Stack {

    queue<T> q1, q2;
    // q1 --> fill (push here)
    // q2 --> empty (push here when pop is encountered)
    public:
        void push(T x) {
            q1.push(x);
        }

        void pop() {
            // remove the last added element from q1
            // we have to move the first n-1 elements in q1 to q2.
            // interchange the names of q1 and q2, call swap method.
            if(q1.empty()) { 
                // underflow, no element to pop.
                return; 
            }
            while(q1.size() > 1) {
                // pop n-1 elements from q1 and add it to q2
                T element = q1.front();
                q2.push(element);
                q1.pop();
            }
            q1.pop(); // the last element is popped.
            // swap q1 and q2.
            q1.swap(q2);
        }

        T top() {
            if(q1.empty()) {
                return -1;
            }
            T element;
            while(!q1.empty()) {
                element = q1.front();
                q2.push(element);
                q1.pop();
            }
            q1.swap(q2);
            return element;
        }

        int size() {
            return q1.size() + q2.size();
        }

        bool empty() {
            return size() == 0;
        }

};

int main() {

    Stack<int> s;
    
    for(int i = 1; i <= 5; i++) 
        s.push(i);

    cout << "size : " << s.size() << endl;
    cout << "top element : " << s.top() << endl; 
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}