class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto it:nums){
            freq[it]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto [key,count] : freq){
            bucket[count].push_back(key);
        }
        vector<int> result;
        for(int i = nums.size(); i>=0 && result.size()<k; i--){
            for(auto num:bucket[i]){
                result.push_back(num);
                if(result.size() == k) break;
            }
        }
        return result;
    }
};