class Solution {
public:
    int dpp(vector<int>& prices,vector<vector<vector<int>>>&dp,int i,int n,int b,int k)
    {
        if(i==n) return 0;
        if(dp[i][b][k]!=-1) return dp[i][b][k];
        if(b==0)
        {
            if(k>0)
            {
                int buy=dpp(prices,dp,i+1,n,1,k-1)-prices[i];
                int skip=dpp(prices,dp,i+1,n,b,k);
                return dp[i][b][k]=max(buy,skip);
            }
            else
            {
                return dp[i][b][k]=0;
            }
        }
        else
        {
            int sell=dpp(prices,dp,i+1,n,0,k)+prices[i];
            int skip=dpp(prices,dp,i+1,n,b,k);
            return dp[i][b][k]=max(sell,skip);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return dpp(prices,dp,0,n,0,k);
    }
};