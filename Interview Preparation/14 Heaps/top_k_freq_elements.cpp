/*
    https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
// opposite conditions to that given in the question.
// conditions for the elements to settle down in the heap.
class compare { 
    public:
        bool operator()(const pii p1, const pii p2) {
            // lesser freq elements will settle down
            if(p1.second < p2.second)
                return true;
            // lesser valued elements will settle down if they have the same freq
            else if(p1.second == p2.second)
                return p1.first < p2.first;
            else
                return false;
        }
};

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        priority_queue<pii, vector<pii>, compare> pq;
        map<int, int> m;
        for(const int x : nums)
            m[x]++;
        
        for(const auto p : m)
            pq.push(p);
        
        int count = 0;
        vector<int> result;
        while(!pq.empty() and count < k) {
            result.push_back(pq.top().first);
            pq.pop();
            count++;
        }
        return result;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends