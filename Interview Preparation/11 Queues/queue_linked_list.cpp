#include <iostream>
#include <list>
using namespace std;

class Queue {
    int cur_size;
    list<int> l;

    public:
        Queue() {
            cur_size = 0;
        }

        bool empty() {
            return cur_size == 0;
        }

        void push(int data) {
            l.push_back(data); 
            cur_size++;
        } 

        void pop() {
            if(!empty()) {
                l.pop_front();
                cur_size--;
            }
        }

        int get_front() {
            return l.front();
        }
        
        int get_rear() {
            return l.back();
        }
};

int main() {
    Queue q;

    for(int i = 1; i <= 10; i++)
        q.push(i);
    
    while(!q.empty()) {
        cout << q.get_front() << " ";
        q.pop();
    }

    return 0;
}