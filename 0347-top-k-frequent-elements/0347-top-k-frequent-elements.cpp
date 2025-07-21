class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num: nums){
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size()+1);

        for(auto [key, value] : freq){
            buckets[value].push_back(key);
        }

        vector<int> res;

        for(int i = nums.size(); i>=0 && res.size()<k; i--){
            for(auto num: buckets[i]){
                res.push_back(num);
                // if()
            }
        }

        return res;
    }
};