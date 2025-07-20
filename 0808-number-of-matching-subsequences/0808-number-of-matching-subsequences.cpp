class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;

        unordered_map<char, queue<pair<string, int>>> buckets;

        for (auto word : words) {
            buckets[word[0]].push({word, 0});
        }

        for (auto c : s) {
            auto& q = buckets[c];
            int sz = q.size();

            while (sz--) {
                auto [word, idx] = q.front();
                q.pop();

                idx++;
                if (idx == word.size()) {
                    count++;
                } else {
                    buckets[word[idx]].push({word, idx});
                }
            }
        }
        return count;
    }
};