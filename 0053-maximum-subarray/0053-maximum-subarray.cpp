class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = -1e8;
        int maxSum = INT_MIN;
        for(int i = 0; i<nums.size(); i++) {
            dp = max(dp + nums[i], nums[i]);
            maxSum = max(dp, maxSum);
        }

        return maxSum;
    }
};