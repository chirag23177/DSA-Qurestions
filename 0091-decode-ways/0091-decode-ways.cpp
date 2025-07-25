class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        if(s[0] == '0' || n == 0) return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            
            if(s[i-1] != '0'){
                dp[i] += dp[i-1];
            }
            string snum = s.substr(i-2,2);
            int num = stoi(snum);
            if(num >=10 && num <=26){
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};

