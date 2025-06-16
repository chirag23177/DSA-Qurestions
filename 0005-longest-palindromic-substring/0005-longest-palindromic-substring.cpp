class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int reslen = 0;
        string res = "";
        if (n<=1)
            return s;

        // odd
        for (int i = 0; i < n; i++) {
            int j = i-1;
            int k = i+1;
            while(j>=0 && k<n && s[j] == s[k]){
                j--;
                k++;
            }
            int len = k-j-1;
            if(len>reslen){
                reslen = len;
                res = s.substr(j+1, len);
            }
        }
        // even
        for (int i = 0; i < n; i++) {
            int j = i;
            int k = i+1;
            while(j>=0 && k<n && s[j] == s[k]){
                j--;
                k++;
            }
            int len = k-j-1;
            if(len>reslen){
                reslen = len;
                res = s.substr(j+1, len);
            }
        }

        return res;
    }
};