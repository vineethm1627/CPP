/*
    Given n ropes of different sizes, you need to join the ropes together.
    The cost of joining 2 ropes of different sizes a, b is (a + b).
    
    Find the min. cost to join all the ropes together.

    use greedy approach, pick the 2 smallest ropes to join first.
*/
#include <iostream>
#include <queue>
using namespace std;
 
int join_ropes(int ropes[], int n) {
    // minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes, ropes + n);

    int cost = 0;
    while(minHeap.size() > 1) {
        int a = minHeap.top();
        minHeap.pop();

        int b = minHeap.top();
        minHeap.pop();

        int new_rope = a + b;
        cost += new_rope;
        // push this new rope in the minHeap
        minHeap.push(new_rope);
    }
    return cost;
}
 
int main() {
    
    int ropes[] = {4, 3, 2, 6};
    int n = sizeof(ropes) / sizeof(ropes[0]);

    cout << join_ropes(ropes, n) << endl;
 
    return 0;
}