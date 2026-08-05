class Solution {
public:
    // int func(vector<vector<int>>& grid,int r,int c,int m,int n,vector<vector<int>>&dp)
    // {
    //     if(dp[r][c]!=-1) return dp[r][c];
    //     if(r==m-1 && c==n-1)
    //     {
    //         return dp[r][c]=grid[r][c];
    //     }
    //     else if(r==m-1 || c==n-1)
    //     {
    //         if(r==m-1)
    //         {
    //             return dp[r][c]=grid[r][c]+func(grid,r,c+1,m,n,dp);
    //         }
    //         else
    //         {
    //             return dp[r][c]=grid[r][c]+func(grid,r+1,c,m,n,dp);
    //         }
    //     }
    //     return dp[r][c]=min(grid[r][c]+func(grid,r+1,c,m,n,dp),grid[r][c]+func(grid,r,c+1,m,n,dp));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                {
                    dp[i][j]=grid[m-1][n-1];
                }
                else if(i==m-1 || j==n-1)
                {
                    if(i==m-1)
                    {
                        dp[i][j]=grid[i][j]+dp[i][j+1];
                    }
                    else
                    {
                        dp[i][j]=grid[i][j]+dp[i+1][j];
                    }
                }
                else
                {
                    dp[i][j]=min(grid[i][j]+dp[i+1][j],grid[i][j]+dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};