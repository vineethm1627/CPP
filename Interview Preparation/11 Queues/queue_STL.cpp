#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    for(int i = 1; i <= 10; i++)
        q.push(i);
    
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    cout << "queue: ";

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    } 

    return 0;
}