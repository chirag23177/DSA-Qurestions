class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum = nums[0];
       int maxSum = nums[0];
       for(int i = 1; i<nums.size(); i++) {
            sum = max(sum+nums[i], nums[i]);
            maxSum = max(sum, maxSum);
        }
       return maxSum; 
    }
};