class Solution {
public:
    int solve(int i, int j, vector<int> &coins, vector<vector<int>> &dp) {
        if (j == 0) return 0;
        if (i == 0) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        if (coins[i - 1] <= j) dp[i][j] = min(1 + solve(i, j - coins[i - 1], coins, dp), 
                                solve(i - 1, j, coins, dp));

        else dp[i][j] = solve(i - 1, j, coins, dp);

        return dp[i][j];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        int ans = solve(n, amount, coins, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
