/*
    Generate numbers with given digits only in increasing order.

    All the digits should lie in the set {5,6}.
*/
#include <iostream>
#include <queue>
using namespace std;

void generate(int n) {
    queue<string> q;
    q.push("5");
    q.push("6");

    for(int count = 0; count < n; count++) {
        string front = q.front();
        q.pop();
        cout << front << " ";
        // push children in the queue
        q.push(front + "5");
        q.push(front + "6");
    }
}

int main() {

    int n;
    cin >> n;

    generate(n);
    
    return 0;
}