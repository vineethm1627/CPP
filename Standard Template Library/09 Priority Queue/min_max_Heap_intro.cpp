#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> maxHeap; // by default it is maxHeap where the top element is the maximum of all its sub elements
    priority_queue< int, vector<int>, greater<int> > minHeap;
    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        maxHeap.push(num);
        minHeap.push(num);
    }

    // remove elements from the heap
    cout << "MaxHeap: " << endl;
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << "\nMinHeap: " << endl;
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    } 

    return 0;
}