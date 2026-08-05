class Solution {
public:
 int sum=0;
    int cal(vector<vector<int>>& obstacleGrid,int r,int c,vector<vector<int>>&dp,int n,int m)
    {
        if(r==n-1 && c==m-1)
        {
            return 1;
        }
        if(dp[r][c]!=-1 ) return dp[r][c];
        // if(r==obstacleGrid.size()-1 || c==obstacleGrid[0].size()-1)
        // {
        //     return 1;
        // }
       int c1=0,c2=0;
      // if(r<n&&c<m){
        if(r+1<n&&c<m&&obstacleGrid[r+1][c]==0) c1=cal(obstacleGrid,r+1,c,dp,n,m);
         if(r<n&&c+1<m&&obstacleGrid[r][c+1]==0) c2=cal(obstacleGrid,r,c+1,dp,n,m);
        
        sum=c1+c2;



      // }


        return dp[r][c]= sum;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=0;
        int c=0;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1)return 0;
        return cal(obstacleGrid,r,c,dp,n,m);
    }
};