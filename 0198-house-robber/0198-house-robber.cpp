class Solution {
public:
    int rob(vector<int>& nums) {
        int opt1 =0;
        int opt2 = 0;
        for(int i = 0; i< nums.size(); i++){
            int temp = max(nums[i] + opt1, opt2);
            opt1 = opt2;
            opt2 = temp;
        }
        return  opt2;
    }
};