/*
    Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

    Example 1:
    Input: [1,2,1]
    Output: [2,-1,2]
    Explanation: The first 1's next greater number is 2; 
    The number 2 can't find next greater number; 
    The second 1's next greater number needs to search circularly, which is also 2.

    Input: [4,-2,5,9,8]
    Output: [5,5,9,-1,9]

*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n); // to store the result
        stack<int> s; // to store the indices of the next greater number.
        // we are not storing numbers because of duplicates
        
        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!s.empty() and arr[s.top()] <= arr[i % n]) {
                s.pop();
            }
            result[i % n] = (s.empty() ? -1 : arr[s.top()]);
            // push the current index on the stack
            s.push(i % n);
        }
        return result;
    }
};