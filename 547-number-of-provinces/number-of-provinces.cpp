class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(!q.empty())
                {
                    int f=q.front();
                    q.pop();
                    for(int j=0;j<n;j++)
                    {
                        if(isConnected[f][j]==1 && f!=j)
                        {
                            if(vis[j]==0)
                            {
                                vis[j]=1;
                                q.push(j);
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};