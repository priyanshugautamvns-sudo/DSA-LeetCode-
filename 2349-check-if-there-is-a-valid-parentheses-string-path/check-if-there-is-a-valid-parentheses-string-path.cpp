class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if((m + n - 1) % 2 != 0)
            return false;

        if(grid[0][0] == ')')
            return false;

        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(m+n+1, false))
        );

        int cnt = 1;  // grid[0][0] = '('
        dp[0][0][cnt] = true;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    continue;

                int change;

                if(grid[i][j] == '(')
                    change = 1;
                else
                    change = -1;

                for(int cnt = 0; cnt <= m+n; cnt++)
                {
                    // Coming from top
                    if(i > 0)
                    {
                        int prev = cnt - change;

                        if(prev >= 0 && dp[i-1][j][prev])
                            dp[i][j][cnt] = true;
                    }

                    // Coming from left
                    if(j > 0)
                    {
                        int prev = cnt - change;

                        if(prev >= 0 && dp[i][j-1][prev])
                            dp[i][j][cnt] = true;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};