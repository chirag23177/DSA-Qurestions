class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i, j;
        i = 0;
        j = n - 1;

        while (i < j) {
            while(i<j && !isalnum(s[i])){i++;}
            while(i<j && !isalnum(s[j])){j--;}
            

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
                // break;
            }
            i++;
            j--;
        }

        return true;
    }
};