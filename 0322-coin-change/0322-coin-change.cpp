class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int mincoin = INT_MAX;
            for (int j = 0; j <n; j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                        mincoin = min(1 + dp[i - coins[j]], mincoin);
                }
            }
            dp[i] = mincoin;
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};