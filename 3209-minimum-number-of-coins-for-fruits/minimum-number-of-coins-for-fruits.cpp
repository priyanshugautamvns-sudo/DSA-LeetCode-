class Solution {
public:
    // int dpp(vector<int>& prices,int i)
    // {
    //     if(i>=prices.size()) return 0;
    //     int mini=INT_MAX;
    //     int j=i+2;
    //     while(j>0)
    //     {
    //         mini=min(mini,prices[i]+dpp(prices,i+j));
    //         j--;
    //     }
    //     return mini;
    // }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(2*(n+1),0);
        for(int i=n-1;i>=0;i--)
        {
            int mini=INT_MAX;
            int j=i+2;
            while(j>0)
            {
                mini=min(mini,prices[i]+dp[i+j]);
                j--;
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};  