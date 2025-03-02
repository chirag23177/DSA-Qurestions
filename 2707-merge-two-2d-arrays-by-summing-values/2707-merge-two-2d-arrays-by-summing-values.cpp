class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> m;
        for (auto i : nums1) {
            m[i[0]] = i[1];
        }
        for(auto i : nums2){
            m[i[0]] += i[1];
        }
        vector<vector<int>> result;
        for(auto l : m){
            result.push_back({l.first, l.second});
        }

        return result;
    }
};