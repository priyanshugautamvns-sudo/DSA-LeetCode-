class Solution {
public:
    int dpp(string &word1, string &word2, int i, int j,
            vector<vector<int>>& dp)
    {
        if(i == word1.size())
        {
            return word2.size() - j;
        }

        if(j == word2.size())
        {
            return word1.size() - i;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
        {
            dp[i][j] = dpp(word1, word2, i + 1, j + 1, dp);
        }
        else
        {
            dp[i][j] = 1 + min(
                dpp(word1, word2, i + 1, j, dp),
                dpp(word1, word2, i, j + 1, dp)
            );
        }

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return dpp(word1, word2, 0, 0, dp);
    }
};