class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[n][i][j]=0;
                dp[n][i][j]=0;
            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    int curr;
                    if(j == k) curr = grid[i][j];
                    else curr = grid[i][j] + grid[i][k];
                    int best = 0;
                    for(int x=-1;x<=1;x++)
                    {
                        for(int y=-1;y<=1;y++) 
                        {
                            int nj=j+x;
                            int nk=k+y;
                            if(nj>=0 && nj<m && nk>=0 && nk<m) 
                            {
                                best=max(best,dp[i+1][nj][nk]);
                            }
                        }
                    }
                    dp[i][j][k]=curr+best;
                } 
            }
        }
        return dp[0][0][m-1];
    }
};