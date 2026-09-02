class Solution {
public:
    int dpp(vector<int>& stones,vector<vector<int>>&dp,int i,int j,int sum,int n)
    {
        if(i>j) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int c1=sum-stones[i]-dpp(stones,dp,i+1,j,sum-stones[i],n);
        int c2=sum-stones[j]-dpp(stones,dp,i,j-1,sum-stones[j],n);
        return dp[i][j]=max(c1,c2);    
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int p=0;p<n;p++)
        {
            sum+=stones[p];
        }
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        return dpp(stones,dp,0,n-1,sum,n);
    }
}; 