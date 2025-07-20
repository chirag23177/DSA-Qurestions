class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<pair<string, int>>> buckets(26);
        int count = 0;

        for (auto& word : words)
            buckets[word[0] - 'a'].push({word, 0});

        for (char c : s) {
            int idx = c - 'a';
            int size = buckets[idx].size();
            while (size--) {
                auto [word, pos] = buckets[idx].front();
                buckets[idx].pop();
                pos++;
                if (pos == word.size())
                    count++;
                else
                    buckets[word[pos] - 'a'].push({word, pos});
            }
        }

        return count;
    }
};
