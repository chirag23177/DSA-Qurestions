class Solution {
public:
    int findElement(vector<int>& nums, int l, int r, int target){
        if(l>r) return -1;
        int mid = l+(r-l)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(target < nums[mid]){
            return findElement(nums, l, mid-1, target);
        }
        else{
            return findElement(nums, mid+1, r, target);
        }
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l<r){
            int mid = l+(r-l)/2;

            if(nums[mid]<nums[r]){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }

        int minIdx = l;
        int a = findElement(nums,0,l-1,target);
        int b = findElement(nums,l,nums.size()-1,target);

        if(a == -1 && b == -1){
            return -1;
        }
        else{
            return max(a,b);
        }
    }
};