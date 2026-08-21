class Solution {
public:

    bool dpp(string& s, string& p, int i, int j,
             vector<vector<int>>& dp,
             vector<bool>& onlyStar)
    {
        if(i == s.size())
            return onlyStar[j];

        if(j == p.size())
            return false;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] =
                dpp(s, p, i + 1, j + 1, dp, onlyStar);
        }

        if(p[j] == '*')
        {
            return dp[i][j] =
                dpp(s, p, i + 1, j, dp, onlyStar) ||
                dpp(s, p, i, j + 1, dp, onlyStar);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        vector<bool> onlyStar(m + 1, true);

        for(int j = m - 1; j >= 0; j--)
        {
            onlyStar[j] = onlyStar[j + 1] && (p[j] == '*');
        }

        return dpp(s, p, 0, 0, dp, onlyStar);
    }
};