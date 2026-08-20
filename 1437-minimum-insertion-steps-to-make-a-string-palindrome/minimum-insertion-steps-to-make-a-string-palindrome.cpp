class Solution {
public:
    int dpp(string&s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j])
        {
            dp[i][j]=dpp(s,i+1,j-1,dp);
        }
        else
        {
            dp[i][j]=1+min(dpp(s,i+1,j,dp),dpp(s,i,j-1,dp));
        }
        return dp[i][j];
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return dpp(s,0,s.size()-1,dp);
    }
};