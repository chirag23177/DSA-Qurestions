class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int goal = nums.size()-1;
        for(int i = nums.size()-2; i>=0; i--) {
            if( i + nums[i] >= goal){
                goal = i;
            }
        }

        return !goal;
    }
};