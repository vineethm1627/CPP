/*
     find k largest numbers in a running stream of numbers.
     You cannot store all the numbers

     The count of such numbers is not defined, your task is to find out the 
     k largest elements at any instance.
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// priority queue is passed by value, so the changes won't be reflected in the actual priority_queue.
void query_print(priority_queue< int, vector<int>, greater<int> > minHeap) {
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    int k;
    cin >> k;
    priority_queue< int, vector<int>, greater<int> > minHeap;
    int num;

    while(cin >> num) {
        if(num == -1) {
            query_print(minHeap);
        }
        else if(minHeap.size() < k) 
            minHeap.push(num);
        else {
            if(num > minHeap.top()) {
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }

    return 0;
}
