class Solution {
public:
    int dpp(vector<int>& prices,vector<vector<vector<int>>>&dp,int i,int n,int b,int m)
    {
        if(i==n) return 0;
        if(dp[i][b][m]!=-1) return dp[i][b][m];
        if(b==0)
        {
            if(m>0)
            {
                int buy=dpp(prices,dp,i+1,n,1,m-1)-prices[i];
                int skip=dpp(prices,dp,i+1,n,b,m);
                return dp[i][b][m]=max(buy,skip);
            }
            else
            {
                return dp[i][b][m]=0;
            }
        }
        else
        {
            int sell=dpp(prices,dp,i+1,n,0,m)+prices[i];
            int skip=dpp(prices,dp,i+1,n,b,m);
            return dp[i][b][m]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return dpp(prices,dp,0,n,0,2);
    }
};