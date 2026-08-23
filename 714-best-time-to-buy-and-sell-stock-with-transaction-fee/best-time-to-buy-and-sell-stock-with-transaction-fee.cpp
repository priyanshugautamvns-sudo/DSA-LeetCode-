class Solution {
public:
    int dpp(vector<int>& prices, vector<vector<int>>& dp,
            int i, int b, int fee) {

        if (i == prices.size())
            return 0;

        if (dp[i][b] != -1)
            return dp[i][b];

        if (b == 0) {
            // Buy OR skip
            int buy = dpp(prices, dp, i + 1, 1, fee) - prices[i];
            int skip = dpp(prices, dp, i + 1, 0, fee);

            return dp[i][b] = max(buy, skip);
        }
        else {
            // Sell OR hold
            int sell = dpp(prices, dp, i + 1, 0, fee)
                       + prices[i] - fee;

            int hold = dpp(prices, dp, i + 1, 1, fee);

            return dp[i][b] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return dpp(prices, dp, 0, 0, fee);
    }
};