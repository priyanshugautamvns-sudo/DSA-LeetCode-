class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<vector<vector<pair<int,int>>>>adj(n,vector<vector<pair<int,int>>>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i>0) adj[i][j].push_back({i-1,j});
                if(i<n-1) adj[i][j].push_back({i+1,j});
                if(j>0) adj[i][j].push_back({i,j-1});
                if(j<m-1) adj[i][j].push_back({i,j+1});
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            if(mat[x][y]==0) ans[x][y]=0;
            q.pop();
            for(int i=0;i<adj[x][y].size();i++)
            {
                if(mat[adj[x][y][i].first][adj[x][y][i].second]==1 && vis[adj[x][y][i].first][adj[x][y][i].second]==0) 
                {
                    ans[adj[x][y][i].first][adj[x][y][i].second]=1+ans[x][y];
                    q.push({adj[x][y][i].first, adj[x][y][i].second}); 
                    vis[adj[x][y][i].first][adj[x][y][i].second] = 1;
                }
            }
        }
        return ans;
    }
};