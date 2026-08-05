class Solution {
public:
    int cal(vector<vector<int>>& triangle,int r,int c,int m,int n,vector<vector<int>>&dp)
    {
        if(dp[r][c]!=1000000000)
        {
            return dp[r][c];
        }
        if(r==m-1)
        {
            return dp[r][c]=triangle[r][c];
        }
        return dp[r][c]=triangle[r][c]+min(cal(triangle,r+1,c,m,n,dp),cal(triangle,r+1,c+1,m,n,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,1000000000));
        return cal(triangle,0,0,m,n,dp);
    }
};