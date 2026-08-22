class Solution {
public:
    int dpp(vector<int>& prices,int b,int i,vector<vector<int>>&dp,int n)
    {
        if(i==n) return 0;
        if(dp[i][b]!=-1) return dp[i][b];
        if(b==0)
        {
            int buy=dpp(prices,1,i+1,dp,n)-prices[i];
            int skip=dpp(prices,b,i+1,dp,n);
            return dp[i][b]=max(buy,skip);
        }
        else
        {
            int sell=dpp(prices,0,i+1,dp,n)+prices[i];
            int skip=dpp(prices,b,i+1,dp,n);
            return dp[i][b]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return dpp(prices,0,0,dp,n);
    }
};