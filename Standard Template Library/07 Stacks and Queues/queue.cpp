#include <iostream>
#include <queue>
using namespace std;

/*
    follows FIFO (First In First Out)
    elements are added from the back and deleted from the front.
    whatsapp message queing ordering is important.
    sender who sent first should be received first.
    network buffer queues.

    various common operations on queue are :
    1) push
    2) pop
    3) front
    4) empty
    
    There is no concept of indexing in queue.
*/

int main() {

    queue<int> q;

    for(int i = 1; i <=5; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}