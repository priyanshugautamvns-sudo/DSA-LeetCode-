class Solution {
public:

    int dpp(vector<int>& prefix, int i,
            vector<int>& dp, int n)
    {
        if(i == n - 1)
            return prefix[i];

        if(dp[i] != -1)
            return dp[i];
        int v=dpp(prefix, i + 1, dp, n);
        int take = prefix[i] - v;

        int skip = v;

        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();

        vector<int> prefix(n);

        prefix[0] = stones[0];

        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + stones[i];

        vector<int> dp(n, -1);

        return dpp(prefix, 1, dp, n);
    }
};