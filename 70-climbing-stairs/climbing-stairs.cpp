class Solution {
public:
    unordered_map<int,int>dp;
    int cnt=0;
    int climbStairs(int n) {
        if(n==1)
        {
            return cnt+1;
        }
        else if(n==2)
        {
            return cnt+2;
        }
        if(dp[n-1]==0)
        {
            dp[n-1]=climbStairs(n-1);
            dp[n-2]=climbStairs(n-2);
        }
        return dp[n-1]+dp[n-2];
    }
};