class Solution {
public:
    int MOD = 1e9 + 7;
    int dpp(int n,int k,vector<vector<long long>>& dp)
    {
        if(k==0) return 1;
        if(n<k+1) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        long long skip=dpp(n-1,k,dp)%MOD;
        long long take=0;
        int n1=n;
        while(n1-1>=k)
        {
            take+=dpp(n1-1,k-1,dp)%MOD;
            n1--;
        }
        return dp[n][k]=(take+skip)%MOD;
    }
    int numberOfSets(int n, int k) {
        if(n<k+1) return 0;
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
        return dpp(n,k,dp);
    }
};