class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> freq;

        int l,r;
        l = 0;
        r = 0;

        int length = 0;

        while(r<n){
            if(freq.find(s[r]) != freq.end() && freq[s[r]] >= l){
                l = freq[s[r]] +1;
            }
            freq[s[r]] = r;
            length = max(length, r-l+1);
            r++;
        }

        return length;
        
    }
};