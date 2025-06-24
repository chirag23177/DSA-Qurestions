class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if (n == 0)
            return 0;

        vector<int> freq(26, 0);

        int l = 0,r = 0, maxlength = 0, maxfreq = 0;

        while (r < n) {
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            if ((r - l + 1) - maxfreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            if ((r - l + 1) - maxfreq <= k) {
                maxlength = max(maxlength, (r - l + 1));
            }
            r++;
        }

        return maxlength;
    }
};