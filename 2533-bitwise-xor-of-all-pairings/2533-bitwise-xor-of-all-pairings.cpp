class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();

        if (!(n & 1) && !(m & 1)) {
            return 0;
        } else if (n & 1 && !(m & 1)) {
            for (int num : nums2) {
                ans ^= num;
            }
        } else if (!(n & 1) && m & 1) {
            for (int num : nums1) {
                ans ^= num;
            }
        } else {
            for (int num1 : nums1) {
                ans ^= num1;
            }
            for (int num2 : nums2) {
                ans ^= num2;
            }
        }

        return ans;
    }
};