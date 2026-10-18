class Solution {
public:
    bool dpp(string& s, vector<string>& wordDict,int i,int j,int k,vector<vector<vector<int>>>& dp)
    {
        if(i==s.size())
        {
            if(j==wordDict[k].size())
            {
                return true;
            }
            else return false;
        }
        if(dp[i][k][j]!=-1)
        {
            if(dp[i][k][j]==1) return true;
            else return false;
        } 
        bool a1=false;
        bool a2=false;
        if(j==wordDict[k].size())
        {
            for(int l=0;l<wordDict.size();l++)
            {
                if(s[i]==wordDict[l][0])
                {
                    a1=a1||dpp(s,wordDict,i+1,1,l,dp);
                }
            }
        }
        else
        {
            if(s[i]==wordDict[k][j])
            {
                a2=dpp(s,wordDict,i+1,j+1,k,dp);
            }
        }
        if(a1||a2==true) return dp[i][k][j]=1;
        else return dp[i][k][j]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool a=false;
        vector<vector<vector<int>>>dp(s.size(),vector<vector<int>>(wordDict.size(),vector<int>(s.size(),-1)));
        for(int l=0;l<wordDict.size();l++)
        {
            if(s[0]==wordDict[l][0])
            {
                a=a||dpp(s,wordDict,1,1,l,dp);
            }
        }
        return a;
    }
};