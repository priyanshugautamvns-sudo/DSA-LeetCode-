class Solution {
public:
    int cal(int  m,int  n,vector<vector<int>>&dp)
    {
        if(m==1 ||n==1) return 1;
        if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
        if(dp[m-2][n-1]==-1)
        {
            dp[m-2][n-1]=cal(m-1,n,dp);
        }
        if(dp[m-1][n-2]==-1)
        {
            dp[m-1][n-2]=cal(m,n-1,dp);
        }
        return dp[m-2][n-1]+dp[m-1][n-2];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return cal(m,n,dp);
    }
};