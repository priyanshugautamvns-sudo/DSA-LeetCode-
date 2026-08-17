class Solution {
public:
    int dpp(vector<int>& coins,int amount,int i,int n,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if(amount!=0) return INT_MAX;
            else return 1;
        }
        if(amount==0)
        {
            return 1;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        int c1=dpp(coins,amount,i+1,n,dp);
        int c2=INT_MAX;
        if(coins[i]<=amount)
        {
            c2=dpp(coins,amount-coins[i],i,n,dp);
        }
        if(c2!=INT_MAX) c2++;
        return dp[i][amount]=min(c1,c2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        if(dpp(coins,amount,0,n,dp)==INT_MAX)
        {
            return -1;
        }
        return dpp(coins,amount,0,n,dp)-1;
    }
};