/* 
    Implement a stack data structure using 2 queue objects.

    or

    Implement LIFO data structure using 2 FIFO data structures.

*/

#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Stack {
    queue<T> q1, q2;

    public:
        void push(T data) {
            q1.push(data);
        } 

        T top() {
            if(q1.empty()) 
                return -1;
            
            while(q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            // return the last element
            int e = q1.front();
            q2.push(q1.front());
            q1.pop();
            swap(q1, q2);

            return e;
        }

        int size() {
            return q1.size() + q2.size();
        }

        bool empty() {
            return size() == 0;
        }

        void pop() {
            if(q1.empty())
                return;
            // move first n-1 elements to q2
            while(q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            // remove the last element
            q1.pop();

            // swap the names of q1 and q2
            swap(q1, q2);
        }
};

int main() {

    Stack<int> s;
    for(int i = 1; i <= 5; i++)
        s.push(i);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}