/*
    Leetcode link: https://leetcode.com/problems/find-median-from-data-stream/
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap; // max of left part
    priority_queue<int, vector<int>, greater<int>> minHeap; // min of right part
    
    MedianFinder() {
        // answer will always comprise the top element of the maxHeap
    }
    
    void addNum(int num) {
        // left side of the array
        if(maxHeap.empty() or num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        // balance the 2 heaps
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() - minHeap.size() >= 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */