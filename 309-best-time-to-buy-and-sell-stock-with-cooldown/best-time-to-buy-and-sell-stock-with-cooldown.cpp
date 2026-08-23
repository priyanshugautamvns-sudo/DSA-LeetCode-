class Solution {
public:
    int dpp(vector<int>&prices,int i,int n,vector<vector<vector<int>>>&dp,int b,int cnt)
    {
        if(i==n) return 0;
        if(dp[i][b][cnt]!=-1) return dp[i][b][cnt];
        if(cnt==1)
        {
            return dp[i][b][cnt]=dpp(prices,i+1,n,dp,b,0);
        }
        else if(b==0)
        {
            int buy=dpp(prices,i+1,n,dp,1,0)-prices[i];
            int skip=dpp(prices,i+1,n,dp,b,cnt);
            return dp[i][b][cnt]=max(buy,skip);
        }
        else
        {
            int sell=dpp(prices,i+1,n,dp,0,1)+prices[i];
            int skip=dpp(prices,i+1,n,dp,b,cnt);
            return dp[i][b][cnt]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return dpp(prices,0,n,dp,0,0);
    }
};