class Solution {
public:

    int solve(string &s, int k, int i, vector<int>& dp,
              vector<vector<bool>>& pal)
    {
        if(i >= s.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // i ko skip karo
        int ans = solve(s, k, i + 1, dp, pal);

        // i se palindrome lo
        for(int j = i + k - 1; j < s.size(); j++)
        {
            if(pal[i][j])
            {
                ans = max(ans, 1 + solve(s, k, j + 1, dp, pal));
            }
        }

        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Palindrome table
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1]))
                {
                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n, -1);

        return solve(s, k, 0, dp, pal);
    }
};