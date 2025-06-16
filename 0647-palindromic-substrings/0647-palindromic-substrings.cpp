class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int reslen = 0;
        int count = 0;
        if (n <= 1)
            return 1;

        // odd
        for (int i = 0; i < n; i++) {
            int j = i;
            int k = i;
            while (j >= 0 && k < n && s[j] == s[k]) {
                j--;
                k++;
                count++;
            }
        }
        // even
        for (int i = 0; i < n; i++) {
            int j = i;
            int k = i + 1;
            while (j >= 0 && k < n && s[j] == s[k]) {
                j--;
                k++;
                count++;
            }
        }

        return count;
    }
};