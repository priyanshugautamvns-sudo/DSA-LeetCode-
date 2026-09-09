class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 ||j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }

                }
            }
        }
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        int cnt=0;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x1=x+dx[i];
                int y1=y+dy[i];
                if(x1>=0 && x1<n && y1>=0 && y1<m && vis[x1][y1]==0)
                {
                    if(vis[x1][y1]==0 && grid[x1][y1]==1)
                    {
                        q.push({x1,y1});
                        vis[x1][y1]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};