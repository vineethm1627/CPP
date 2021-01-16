/*
    follows FIFO order.
    has 2 pointers, front and rear.

    A few common operations:
        enqueue: (push) insertion takes place at the rear.
        dequeue: (pop) deletion takes place at the front.
        front(): returns the data at the front without popping it.
    
    used in
        games
        os scheduling applications
        server requests
        whatsapp messaging
        perform operations in trees and graphs
*/
#include <iostream>
#include <climits>
using namespace std;

class Queue {
    int *arr;
    int front, rear;
    int cur_size, max_size;

    public:
        Queue(int max_size = 5) {
            arr = new int[max_size];
            cur_size = 0;
            this->max_size = max_size;
            front = 0;
            rear = max_size - 1;
        }

        bool full() {
            return cur_size == max_size;
        }

        void push(int data) {
            if(!full()) {
                rear = (rear + 1) % max_size;
                arr[rear] = data;
                cur_size++;
            }
        }

        bool empty() {
            return cur_size == 0;
        }

        void pop() {
            if(!empty()) {
                front = (front + 1) % max_size;
                cur_size--;
            }
        }

        int get_front() {
            if(!empty())
                return arr[front];
            return INT_MIN;
        }

        ~Queue() {
            if(arr != NULL) {
                delete [] arr;
                arr = NULL;
            }
        }
};

int main() {

    Queue q(7);
    for(int i = 1; i <= 6; i++) {
        q.push(i);
    }

    q.pop();
    q.pop();
    q.push(7);

    while(!q.empty()) {
        cout << q.get_front() << " ";
        q.pop();
    }

    return 0;
}