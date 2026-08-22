class Solution {
public:
    int dpp(vector<int>& prices, int i, int b,
            vector<vector<int>>& dp)
    {
        if(i == prices.size())
            return 0;

        if(dp[i][b] != -1)
            return dp[i][b];

        if(b == 0)
        {
            int buy = -prices[i] + dpp(prices, i + 1, 1, dp);
            int skip = dpp(prices, i + 1, 0, dp);

            return dp[i][b] = max(buy, skip);
        }
        else
        {
            int sell = prices[i];
            
            // After selling, we cannot buy again.
            // So don't call dpp again.
            
            int skip = dpp(prices, i + 1, 1, dp);

            return dp[i][b] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return dpp(prices, 0, 0, dp);
    }
};