class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums;
        int l = 0;
        int r = 0;

        vector<int> res;

        priority_queue<pair<int, int>> mxheap;

        while (r < nums.size()) {
            mxheap.push({nums[r], r});

            if (r - l + 1 == k) {
                while (mxheap.top().second < l) {
                    mxheap.pop();
                }
                res.push_back(mxheap.top().first);
                l++;
            }
            r++;
        }

        return res;
    }
};