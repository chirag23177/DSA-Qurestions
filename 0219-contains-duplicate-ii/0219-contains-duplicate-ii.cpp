class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, pair<int,int>> hmap;
        for( int i = 0; i<nums.size(); i++){
            int count = hmap[nums[i]].first;
            if(count+1 > 1){
                if(abs(hmap[nums[i]].second - i) <=k){
                    return true;
                }
                else
                    hmap[nums[i]] = {count+1, i};
            }
            else
                hmap[nums[i]] = {count+1, i};
        }
        return false;
    }
};