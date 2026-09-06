class Solution {
public:
    // int dpp(string&s,string&t,int i,int j,vector<vector<int>>&dp)
    // {
    //     if(j==t.size()) return 1;
    //     else if(i==s.size()) return 0;
    //     if(dp[i][j]!=-1)  return dp[i][j];
    //     if(s[i]==t[j])
    //     {
    //         return dp[i][j]=dpp(s,t,i+1,j+1,dp)+dpp(s,t,i+1,j,dp);
    //     }
    //     return dp[i][j]=dpp(s,t,i+1,j,dp);
    // }
    int numDistinct(string s, string t) {
        vector<long long>next(t.size()+1,0);
        next[t.size()]=1;
        for(long long i=s.size()-1;i>=0;i--)
        {
            vector<long long>curr(t.size()+1,0);
            curr[t.size()] = 1;
            for(long long j=t.size()-1;j>=0;j--)
            {
                if(s[i]==t[j])
                {
                    if(next[j+1] > INT_MAX - next[j])
                        curr[j] = INT_MAX;
                    else
                        curr[j] = next[j+1] + next[j];

                }
                else curr[j]=next[j]; 
            }
            next=curr;
        }
        return next[0];
    }
};