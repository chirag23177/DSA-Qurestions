class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> anagrams;

        for(auto word : strs){
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());

            anagrams[sorted_word].push_back(word);
        }

        for(auto [base, words]: anagrams){
            res.push_back(words);
        }

        return res;
    }
};