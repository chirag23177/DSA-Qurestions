class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> freq(26,0);

        int l = 0;
        int maxlength = 0;
        int maxfreq = 0;

        for(int r = 0; r<n; r++){
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq,freq[s[r] - 'A']);

            if((r-l+1) -maxfreq >k){
                freq[s[l] - 'A']--;
                l++;
            }
            if((r-l+1) -maxfreq <=k){
                maxlength = max(maxlength,(r-l+1));
            }

        }

        return maxlength;
    }
};