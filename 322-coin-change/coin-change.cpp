class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        for (int coin : coins) {
            int res = helper(coins, amount - coin, dp);
            if (res != INT_MAX) {
                mini = min(mini, 1 + res);
            }
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = helper(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
