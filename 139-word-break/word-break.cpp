class Solution {
public:
    // bool dpp(string& s, vector<string>& wordDict,int i,int j,int k,vector<vector<vector<int>>>& dp)
    // {
    //     if(i==s.size())
    //     {
    //         if(j==wordDict[k].size())
    //         {
    //             return true;
    //         }
    //         else return false;
    //     }
    //     if(dp[i][k][j]!=-1)
    //     {
    //         if(dp[i][k][j]==1) return true;
    //         else return false;
    //     } 
    //     bool a1=false;
    //     bool a2=false;
    //     if(j==wordDict[k].size())
    //     {
    //         for(int l=0;l<wordDict.size();l++)
    //         {
    //             if(s[i]==wordDict[l][0])
    //             {
    //                 a1=a1||dpp(s,wordDict,i+1,1,l,dp);
    //             }
    //         }
    //     }
    //     else
    //     {
    //         if(s[i]==wordDict[k][j])
    //         {
    //             a2=dpp(s,wordDict,i+1,j+1,k,dp);
    //         }
    //     }
    //     if(a1||a2==true) return dp[i][k][j]=1;
    //     else return dp[i][k][j]=0;
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool a=false;
        int si=s.size();
        for(int h=0;h<wordDict.size();h++)
        {
            int q=wordDict[h].size();
            si=max(si,q);
        }
        vector<vector<vector<int>>>dp(s.size()+1,vector<vector<int>>(wordDict.size()+1,vector<int>(si+1,0)));
        for(int b=0;b<wordDict.size();b++)
        {
            int t=wordDict[b].size();
            dp[s.size()][b][t]=1;
        }
        for(int l=0;l<wordDict.size();l++)
        {
            if(s[0]==wordDict[l][0])
            {
                for(int i=s.size()-1;i>=0;i--)
                {
                    for(int k=0;k<wordDict.size();k++)
                    {
                        int r=wordDict[k].size();
                        for(int j=r;j>=0;j--)
                        {
                            bool a1=false;
                            bool a2=false;
                            if(j==wordDict[k].size())
                            {
                                for(int l=0;l<wordDict.size();l++)
                                {
                                    if(s[i]==wordDict[l][0])
                                    {
                                        a1=a1||dp[i+1][l][1];
                                    }
                                }
                            }
                            else
                            {
                                if(s[i]==wordDict[k][j])
                                {
                                    a2=dp[i+1][k][j+1];
                                }
                            }
                            if(a1||a2==true) dp[i][k][j]=1;
                            else dp[i][k][j]=0;
                        }
                    }
                }
                a=a||dp[1][l][1];
            }
        }
        return a;
    }
};