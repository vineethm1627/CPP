/*
    Leetcode problem: https://leetcode.com/problems/4sum/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> pairSum(vector<int> &nums, int target, int start) {
    vector<vector<int>> result;
    int n = nums.size();
    int left = start, right = n - 1;
    while(left < right) {
        int sum = nums[left] + nums[right];
        if(sum == target) {
            result.push_back({nums[left], nums[right]});
            left++;
            right--;
            // avoid the duplicates
            if(left < right and nums[left] == nums[left - 1])
                left++;

            if(left < right and nums[right] == nums[right + 1])
                right--; 
        }
        else if(sum < target)
            left++;
        else
            right--;
    }
    return result;
}

vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
    vector<vector<int>> result;
    unordered_set<int> s;
    for(int i = start; i < nums.size(); i++) {
        // result.back()[1] is the second element of the pair
        if(result.empty() || result.back()[1] != nums[i]) {
            if(s.count(target - nums[i]))
                result.push_back({target - nums[i], nums[i]});
            s.insert(nums[i]);
        }
    }
    return result;
}

// generalized implementation of k-sum
vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
    vector<vector<int>> result;
    // base condition
    if(start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        return result;
    // function calls
    if(k == 2) 
        return pairSum(nums, target, start);
    
    // recursive calls
    for(int i = start; i < nums.size(); i++) {
        if(i == start || nums[i] != nums[i - 1]) {
            for(auto v : kSum(nums, target - nums[i], i + 1, k - 1)) {
                result.push_back({nums[i]});
                // push the last vector inserted in the vector of vectors returned by the function
                result.back().insert(result.back().end(), v.begin(), v.end());
            }
        }
    }
    return result;
}

int main() {

    int n, target;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) 
        cin >> nums[i];
    
    cin >> target;
    // sort the array
    sort(nums.begin(), nums.end());
    // call for fourSum ie k = 4
    int k = 3;
    vector<vector<int>> result = kSum(nums, target, 0, k);
    for(auto v : result) {
        for(auto x : v) 
            cout << x << " ";
        cout << endl;
    }
    return 0;
}