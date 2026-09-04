class Solution {
public:
    // int cal(vector<vector<int>>& triangle,int r,int c,int m,int n,vector<vector<int>>&dp)
    // {
    //     if(dp[r][c]!=-2)
    //     {
    //         return dp[r][c];
    //     }
    //     if(r==m-1)
    //     {
    //         return dp[r][c]=triangle[r][c];
    //     }
    //     return dp[r][c]=triangle[r][c]+min(cal(triangle,r+1,c,m,n,dp),cal(triangle,r+1,c+1,m,n,dp));
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<int>prev(n,-2);
        for(int i=m-1;i>=0;i--)
        {
            vector<int>temp(n,-2);
            for(int j=i;j>=0;j--)
            {
                if(i==m-1)
                {
                    temp[j]=triangle[i][j];
                }
                else{temp[j]=triangle[i][j]+min(prev[j],prev[j+1]);}
            }
            prev=temp;
        }
        return prev[0];
    }
};