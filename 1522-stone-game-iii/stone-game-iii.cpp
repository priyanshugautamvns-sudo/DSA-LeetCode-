class Solution {
public:
    // int dpp(int i,vector<int>&dp,vector<int>& stoneValue,int n)
    // {
    //     if(i==n) return 0;
    //     if(dp[i]!=INT_MIN) return dp[i];
    //     int sum=stoneValue[i];
    //     int c1=sum-dpp(i+1,dp,stoneValue,n);
    //     int c2=INT_MIN;
    //     if(i+1<n)
    //     {
    //         sum+=stoneValue[i+1];
    //         c2=sum-dpp(i+2,dp,stoneValue,n);
    //     }
    //     int c3=INT_MIN;
    //     if(i+2<n)
    //     {
    //         sum+=stoneValue[i+2];
    //         c3=sum-dpp(i+3,dp,stoneValue,n);
    //     }
    //     return dp[i]=max(c1,max(c2,c3));
    // }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(3,INT_MIN);
        dp[0]=0;
        for(int i=n-1;i>=0;i--)
        {
            int sum=stoneValue[i];
            int c1=sum-dp[0];
            int c2=INT_MIN;
            if(i+1<n)
            {
                sum+=stoneValue[i+1];
                c2=sum-dp[1];
            }
            int c3=INT_MIN;
            if(i+2<n)
            {
                sum+=stoneValue[i+2];
                c3=sum-dp[2];
            }
            dp[2]=dp[1];
            dp[1]=dp[0];
            dp[0]=max(c1,max(c2,c3));
        }
        if(dp[0]==0) return "Tie";
        else if(dp[0]>0) return "Alice";
        else return "Bob";
    }
};