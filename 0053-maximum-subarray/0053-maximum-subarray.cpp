class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size();i++){
            a = max(a+nums[i], nums[i]);
            maxi = max(maxi,a);
        }
        return maxi;
    }
};