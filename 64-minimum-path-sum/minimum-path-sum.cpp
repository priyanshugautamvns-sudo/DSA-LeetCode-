class Solution {
public:
    int func(vector<vector<int>>& grid,int r,int c,int m,int n,vector<vector<int>>&dp)
    {
        if(dp[r][c]!=-1) return dp[r][c];
        if(r==m-1 && c==n-1)
        {
            return dp[r][c]=grid[r][c];
        }
        else if(r==m-1 || c==n-1)
        {
            if(r==m-1)
            {
                return dp[r][c]=grid[r][c]+func(grid,r,c+1,m,n,dp);
            }
            else
            {
                return dp[r][c]=grid[r][c]+func(grid,r+1,c,m,n,dp);
            }
        }
        return dp[r][c]=min(grid[r][c]+func(grid,r+1,c,m,n,dp),grid[r][c]+func(grid,r,c+1,m,n,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(grid,0,0,m,n,dp);
    }
};