class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> choice1(nums.begin(),nums.end()-1);
        vector<int> choice2(nums.begin()+1 ,nums.end());
        return max(amount(choice2), amount(choice1));
    }

    int amount(vector<int>& nums){
        int n = nums.size();
        int opt1 =0, opt2 = 0;
        for(int i = 0; i<n; i++){
                int temp = max(opt1 + nums[i], opt2);
                opt1 = opt2;
                opt2 = temp;
        }
        return opt2;
    }
};