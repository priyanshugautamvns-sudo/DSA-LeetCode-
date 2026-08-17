class Solution {
public:
    int dpp(int amount, vector<int>& coins,int i,int n,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if(amount==0)
            {
                return 1;
            }
            else return 0;
        }
        if(amount==0)
        {
            return 1;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int c1=dpp(amount,coins,i+1,n,dp);
        int c2=0;
        if(amount>=coins[i])
        {
            c2=dpp(amount-coins[i],coins,i,n,dp);
        }
        return dp[i][amount]=c1+c2;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return dpp(amount,coins,0,n,dp);
    }
};