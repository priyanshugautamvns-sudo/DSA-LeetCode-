class Solution {
public:
    bool dpp(string&s, string&p,int i,int j,vector<vector<int>>&dp)
    {
        if(i==s.size() && j==p.size()) return true;
        if(j == p.size())
            return false;

        // String finished
        if(i == s.size())
        {
            // Remaining pattern should contain only '*'
            for(int k = j; k < p.size(); k++)
            {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool c1=false;
        bool c2=false;
        bool c3=false;
        if(s[i]==p[j] || p[j]=='?')
        {
            c1=dpp(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='*')
        {
            c2=dpp(s,p,i+1,j,dp)||dpp(s,p,i,j+1,dp);
        }
        else
        {
            c3=false;
        }
        return dp[i][j]=c1||c2||c3;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return dpp(s,p,0,0,dp);
    }
};