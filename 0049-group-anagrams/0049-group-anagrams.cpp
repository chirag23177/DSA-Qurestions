class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hmap;
        vector<vector<string>> result;
        for(auto word:strs){
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            hmap[sortedWord].push_back(word);
        }

        for(auto& [key,group] : hmap){
            result.push_back(group);
        }
        return result;
    }
};