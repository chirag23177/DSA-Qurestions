class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int reqsum = (n * (n+1))/2;
        for(auto num: nums){
            sum += num;
        }
        return reqsum - sum;
    }
};