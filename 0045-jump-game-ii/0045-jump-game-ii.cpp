class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int l = 0, r = 0;
        while(r < nums.size()-1) {
            int farthest = 0;
            for(int i = l; i<=r; i++) {
                farthest = max(farthest, nums[i] + i);

            }
            l = r + 1;
            r = farthest;
            steps++;
        }

        return steps;
    }
};