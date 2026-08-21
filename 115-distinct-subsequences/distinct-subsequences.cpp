class Solution {
public:
    int dpp(string&s,string&t,int i,int j,vector<vector<int>>&dp)
    {
        if(j==t.size()) return 1;
        else if(i==s.size()) return 0;
        if(dp[i][j]!=-1)  return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=dpp(s,t,i+1,j+1,dp)+dpp(s,t,i+1,j,dp);
        }
        return dp[i][j]=dpp(s,t,i+1,j,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return dpp(s,t,0,0,dp);
    }
};