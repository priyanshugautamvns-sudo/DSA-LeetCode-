class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool dpp(vector<vector<char>>& grid, int i, int j, int cnt)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Current cell
        if(grid[i][j] == '(')
            cnt++;
        else
            cnt--;

        if(cnt < 0)
            return false;

        // Last cell
        if(i == m-1 && j == n-1)
        {
            return cnt == 0;
        }

        // Already calculated
        if(dp[i][j][cnt] != -1)
            return dp[i][j][cnt];

        bool right = false;
        bool down = false;

        if(j+1 < n)
        {
            right = dpp(grid, i, j+1, cnt);
        }

        if(i+1 < m)
        {
            down = dpp(grid, i+1, j, cnt);
        }

        return dp[i][j][cnt] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if((m+n-1) % 2 != 0)
            return false;

        if(grid[0][0] == ')')
            return false;

        // cnt maximum can be m+n
        dp.assign(m, vector<vector<int>>(n, vector<int>(m+n+1, -1)));

        return dpp(grid, 0, 0, 0);
    }
};