class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupMap;

        for (string& s : strs) {
            // Frequency count vector as key
            vector<int> count(26, 0);
            for (char c : s) count[c - 'a']++;

            // Convert count vector to string as unique key
            string key;
            for (int freq : count) {
                key += "#" + to_string(freq);  // use # as delimiter
            }

            groupMap[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : groupMap) {
            result.push_back(move(entry.second));
        }

        return result;
    }
};
