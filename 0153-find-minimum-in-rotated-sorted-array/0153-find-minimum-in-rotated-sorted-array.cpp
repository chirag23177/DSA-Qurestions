class Solution {
public:
    int findMin(vector<int>& nums, int l, int r){
        if(l == r){
            return nums[l];
        }

        int mid = l + (r-l)/2;

        if(nums[mid]<nums[r]){
            return findMin(nums, l, mid);
        }
        else{
            return findMin(nums, mid + 1, r);
        }
    }

    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
};