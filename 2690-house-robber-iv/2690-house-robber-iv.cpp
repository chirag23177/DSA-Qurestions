class Solution {
public:
    bool canRobWithMax(vector<int>& nums, int maxStolen, int k) {
        int count = 0;
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] <= maxStolen) {
                count++;
                if (count >= k) {
                    return true;
                }
                i += 2;
            } else {
                i++;
            }
        }

        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canRobWithMax(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};