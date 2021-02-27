/*
    Leetcode Problem: https://leetcode.com/problems/4sum/
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        // base case: min 4 elements should be there
        if(nums.size() < 4) 
            return {};
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 3; i++) {
            // edge case
            if(i > 0 and nums[i] == nums[i - 1])
                continue;

            for(int j = i + 1; j < nums.size() - 2; j++) {
                // edge case
                if(j > i + 1 and nums[j] == nums[j - 1])
                    continue;
                
                // now apply pair sum
                int left = j + 1, right = nums.size() - 1;
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        
                        // avoid duplicates
                        while(left < right and nums[left] == nums[left - 1])
                            left++;
                        
                        while(left < right and nums[right] == nums[right + 1])
                            right--;
                    }
                    else if(sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        // if(result.empty() and target == nums[0] * 4) {
        //     result.push_back({nums[0], nums[0], nums[0], nums[0]});
        // }
        return result;
    }
};