class Solution {
public:

    int dpp(vector<int>& prefix, int i,
            vector<int>& dp,int n)
    {
        if(i==n-1) return prefix[i];
        if(dp[i]!=-1) return dp[i];
        int skip=dpp(prefix,i+1,dp,n);
        int take=prefix[i]-skip;
        
        return dp[i]=max(take,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        vector<int> prefix(stones.size());
        prefix[0] = stones[0];
        for(int i = 1; i < stones.size(); i++)
            prefix[i] = prefix[i-1] + stones[i];
        vector<int> dp(stones.size(), -1);
        return dpp(prefix, 1, dp,stones.size());
    }
};